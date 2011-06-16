#!/bin/bash

mkdir -p mamesets

for i in {1..15}; do
export PS3_SET_NUM=$i
touch src/mame/mamedriv.c
make NOWERROR=1 CROSSBUILD=1 TARGETOS=linux OSD=sdl NO_X11=1 NO_OPENGL=1 -f makefile.ps3 -j3
make_self_wc mame mamesets/mame-$i.self
done

