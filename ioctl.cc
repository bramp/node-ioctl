/**
 * node-ioctl
 * by Andrew Brampton 2013
 */
#include <node.h>
#include <node_buffer.h>
#include <v8.h>

#include <errno.h>
#include <sys/ioctl.h>

using namespace v8;
using namespace node;

void init_constants(Handle<Object> exports);

#define TYPE_ERROR(msg) \
    ThrowException(Exception::TypeError(String::New(msg)));

/**
 * fs.ioctl(fd, request, [buffer], callback(err, ret, buffer))
 */
Handle<Value> Ioctl(const Arguments& args) {
  HandleScope scope;

  int argc = args.Length();

  if (argc < 1) return TYPE_ERROR("fd required");
  if (argc < 2) return TYPE_ERROR("request required");
//  if (argc < 3) return TYPE_ERROR("callback required");

  if (!args[0]->IsInt32()) return TYPE_ERROR("fd must a file handle");
  if (!args[1]->IsNumber()) return TYPE_ERROR("request must be a integer");
  if (argc == 4 && !Buffer::HasInstance(args[2])) return TYPE_ERROR("buffer must be a Buffer");
//  if (!args[argc-1]->IsFunction()) return TYPE_ERROR("callback must be a function");

  int fd = args[0]->Int32Value();
  int request = args[1]->Int32Value();
  char * data = argc == 4 ? Buffer::Data(args[2]) : NULL;
  Local<Function> cb = Local<Function>::Cast(args[argc - 1]);

  int ret = ioctl(fd, request, data);

  if (args[argc-1]->IsFunction()) {
    //async
    Local<Value> argv[3];
    argv[0] = ret < 0 ? UVException(errno, NULL, "ioctl") : Local<Value>::New(Null());
    argv[1] = Integer::New(ret);
    argv[2] = args[2];

    cb->Call(Context::GetCurrent()->Global(), 3, argv);
    return Undefined();

  } else {
    //sync
    if (ret < 0) {
      return ThrowException(UVException(errno, NULL, "ioctl"));
    }
    return scope.Close(Number::New(ret));
  }
}

void init(Handle<Object> exports) {
  exports->Set(String::NewSymbol("ioctl"),
      FunctionTemplate::New(Ioctl)->GetFunction());

  init_constants(exports);
}

NODE_MODULE(ioctl, init)