.PHONY: all test

all: binding.gyp ioctl.cc ioctl_constants.cc
	node-gyp configure build

test:
	nodejs ioctl.js
