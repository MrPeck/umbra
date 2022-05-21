#!/bin/sh

REPO=$(realpath $PWD/..)
BUILD=$(realpath $REPO/..)

cd $REPO/nyx
make KDIR=$BUILD/linux clean

cd $REPO/hermes
make clean

