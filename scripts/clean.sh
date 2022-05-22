#!/bin/sh

REPO=$(realpath $(dirname $(realpath $0))/..)
BUILD=$(realpath $(dirname $(realpath $0))/../..)

make -C $REPO KDIR=$BUILD/linux clean
