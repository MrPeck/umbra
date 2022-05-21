#!/bin/sh

REPO=$(realpath $PWD/..)
BUILD=$(realpath $REPO/..)

gdb \
	-q \
	-ex "add-auto-load-safe-path $BUILD/linux/" \
	-ex "file $BUILD/linux/vmlinux" \
	-ex "lx-symbols $REPO/nyx" \
	-ex "add-symbol-file $REPO/nyx/nyx.ko 0xffffffffc0000000" \
	-ex "target remote localhost:1234"

