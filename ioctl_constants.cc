#include <v8.h>

#include <fcntl.h>
#include <linux/fs.h>
#include <linux/input.h>

#define NODE_DEFINE_CONSTANT_NAME(target, name, constant)                 \
  (target)->Set(v8::String::NewSymbol(name),                              \
                v8::Integer::New(constant),                               \
                static_cast<v8::PropertyAttribute>(v8::ReadOnly|v8::DontDelete))

void init_constants(v8::Handle<v8::Object> exports) {

  // fs.h
  NODE_DEFINE_CONSTANT_NAME(exports, "BLKROSET",   BLKROSET);
  NODE_DEFINE_CONSTANT_NAME(exports, "BLKROGET",   BLKROGET);
  NODE_DEFINE_CONSTANT_NAME(exports, "BLKRRPART",  BLKRRPART);
  NODE_DEFINE_CONSTANT_NAME(exports, "BLKGETSIZE", BLKGETSIZE);
  NODE_DEFINE_CONSTANT_NAME(exports, "BLKFLSBUF",  BLKFLSBUF);
  NODE_DEFINE_CONSTANT_NAME(exports, "BLKRASET",   BLKRASET);
  NODE_DEFINE_CONSTANT_NAME(exports, "BLKRAGET",   BLKRAGET);
  NODE_DEFINE_CONSTANT_NAME(exports, "FIBMAP",     FIBMAP);
  NODE_DEFINE_CONSTANT_NAME(exports, "FIGETBSZ",   FIGETBSZ);

  // input.h
  NODE_DEFINE_CONSTANT_NAME(exports, "EVIOCGVERSION", EVIOCGVERSION); /* get driver version */
  NODE_DEFINE_CONSTANT_NAME(exports, "EVIOCGID", EVIOCGID);   /* get device ID */
  NODE_DEFINE_CONSTANT_NAME(exports, "EVIOCGREP", EVIOCGREP); /* get repeat settings */
  NODE_DEFINE_CONSTANT_NAME(exports, "EVIOCSREP", EVIOCSREP); /* set repeat settings */

  NODE_DEFINE_CONSTANT_NAME(exports, "EVIOCGKEYCODE", EVIOCGKEYCODE); /* get keycode */
  NODE_DEFINE_CONSTANT_NAME(exports, "EVIOCGKEYCODE_V2", EVIOCGKEYCODE_V2);
  NODE_DEFINE_CONSTANT_NAME(exports, "EVIOCSKEYCODE", EVIOCSKEYCODE); /* set keycode */
  NODE_DEFINE_CONSTANT_NAME(exports, "EVIOCSKEYCODE_V2", EVIOCSKEYCODE_V2);

  NODE_DEFINE_CONSTANT_NAME(exports, "EVIOCGNAME", EVIOCGNAME(32)); /* get device name */
  NODE_DEFINE_CONSTANT_NAME(exports, "EVIOCGPHYS", EVIOCGPHYS(32)); /* get physical location */
  NODE_DEFINE_CONSTANT_NAME(exports, "EVIOCGUNIQ", EVIOCGUNIQ(32)); /* get unique identifier */
  NODE_DEFINE_CONSTANT_NAME(exports, "EVIOCGPROP", EVIOCGPROP(32)); /* get device properties */

}