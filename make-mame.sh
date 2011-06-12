#!/bin/bash

mkdir -p mamesets

for i in {1..23}; do
export PS3_SET_NUM=$i
touch src/mame/mamedriv.c
make NOWERROR=1 CROSSBUILD=1 TARGETOS=linux OSD=sdl NO_X11=1 NO_OPENGL=1 -f makefile.ps3 -j3
mv mame mamesets/mame-$i.elf
done

