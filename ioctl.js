var fs = require("fs");
var ioctl = require('./build/Release/ioctl');

/*
// Get blocksize of disk
var fd = fs.openSync('/dev/sda1', 'r');
var buf = new Buffer(8);

var ret = ioctl.ioctlSync(fd, ioctl.BLKGETSIZE, buf);
console.log("Blocksize:" + buf.readUInt32LE(0));
*/

// Get device name
fs.open('/dev/input/by-id/usb-Griffin_Technology__Inc._Griffin_PowerMate-event-if00', 'r', function(err, fd) {
	if (err) throw err;

	var buf = new Buffer(32);
	ioctl.ioctl(fd, ioctl.EVIOCGNAME, buf, function(err, ret, buffer) {
		if (err) throw err;
		console.log(err);
		console.log(ret);
		console.log(buffer);
	});
	
})
/*
var fd = fs.openSync('/dev/input/by-id/usb-Griffin_Technology__Inc._Griffin_PowerMate-event-if00', 'r');

var buf = new Buffer(32);
var ret = ioctl.ioctlSync(fd, ioctl.EVIOCGNAME, buf);
console.log(ret);
console.log("Name: " + buf.toString('ascii', 0, ret.ret));
*/