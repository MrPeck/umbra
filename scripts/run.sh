#!/bin/sh

BUILD=$(realpath $(dirname $(realpath $0))/../..)

qemu-system-x86_64 \
	-kernel $BUILD/linux/arch/x86_64/boot/bzImage \
	-initrd $BUILD/initramfs.cpio.gz \
	-append "console=ttyS0 nokaslr hpet=disable quiet" \
	-nographic \
	-enable-kvm \
	-s
