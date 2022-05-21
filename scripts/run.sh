#!/bin/sh

REPO=$(realpath $PWD/..)
BUILD=$(realpath $REPO/..)

qemu-system-x86_64 \
	-kernel $BUILD/linux/arch/x86_64/boot/bzImage \
	-initrd $BUILD/initramfs.cpio.gz \
	-append "console=ttyS0 nokaslr hpet=disable quiet" \
	-nographic \
	-enable-kvm \
	-s
