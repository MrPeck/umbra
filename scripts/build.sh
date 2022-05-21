#!/bin/sh

REPO=$(realpath $PWD/..)
BUILD=$(realpath $REPO/..)

./clean.sh

cd $REPO/nyx
make KDIR=$BUILD/linux
cp $REPO/nyx/nyx.ko $BUILD/initramfs/home

cd $REPO/hermes
make
cp $REPO/hermes/agent $BUILD/initramfs/home

cd $BUILD/initramfs
find . -print0 | cpio --null -o --format=newc | gzip -9 > $BUILD/initramfs.cpio.gz

