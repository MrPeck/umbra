#!/bin/sh

REPO=$(realpath $(dirname $(realpath $0))/..)
BUILD=$(realpath $(dirname $(realpath $0))/../..)

$REPO/scripts/clean.sh

make -C $REPO KDIR=$BUILD/linux

cp $REPO/nyx/nyx.ko $BUILD/initramfs/home
cp $REPO/hermes/agent $BUILD/initramfs/home

find $BUILD/initramfs -print0 | cpio --null -o --format=newc | gzip -9 > $BUILD/initramfs.cpio.gz

