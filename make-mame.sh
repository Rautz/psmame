#!/bin/sh
make NOWERROR=1 CROSSBUILD=1 TARGETOS=linux OSD=sdl NO_X11=1 NO_OPENGL=1 -f makefile.ps3 -j3

