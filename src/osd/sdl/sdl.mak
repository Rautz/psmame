###########################################################################
#
#   sdl.mak
#
#   SDL-specific makefile
#
#   Copyright (c) 1996-2010, Nicola Salmoria and the MAME Team.
#   Visit http://mamedev.org for licensing and usage restrictions.
#
#   SDLMAME by Olivier Galibert and R. Belmont
#
###########################################################################

###########################################################################
#################   BEGIN USER-CONFIGURABLE OPTIONS   #####################
###########################################################################


#-------------------------------------------------
# specify build options; see each option below
# for details
#-------------------------------------------------


# uncomment and edit next line to specify a distribution
# supported debian-stable, ubuntu-intrepid

# DISTRO = debian-stable
# DISTRO = ubuntu-intrepid
# DISTRO = gcc44-generic

# uncomment next line to build without OpenGL support

# NO_OPENGL = 1

# uncomment next line to build without X11 support (TARGETOS=unix only)
# this also implies, that no debugger will be builtin.

# NO_X11 = 1

# uncomment and adapt next line to link against specific GL-Library
# this will also add a rpath to the executable
# MESA_INSTALL_ROOT = /usr/local/dfb_GL

# uncomment the next line to build a binary using
# GL-dispatching.
# This option takes precedence over MESA_INSTALL_ROOT

USE_DISPATCH_GL = 1

# uncomment and change the next line to compile and link to specific
# SDL library. This is currently supported for unix and win32.
# There is no need to play with this option unless you are doing
# active development on sdlmame or SDL.

ifeq ($(TARGETOS),win32)
#SDL_INSTALL_ROOT = /usr/local/sdl13w32
else
#SDL_INSTALL_ROOT = /usr/local/sdl13
#SDL_INSTALL_ROOT = /usr/local/test
endif

# uncomment and change the next line to build the gtk debugger for win32
# Get what you need here: http://www.gtk.org/download-windows.html
# GTK_INSTALL_ROOT = y:/couriersud/win/gtk-32



###########################################################################
##################   END USER-CONFIGURABLE OPTIONS   ######################
###########################################################################

ifdef NOASM
DEFS += -DSDLMAME_NOASM
endif

# bring in external flags for RPM build
CCOMFLAGS += $(OPT_FLAGS)

#-------------------------------------------------
# distribution may change things
#-------------------------------------------------

ifeq ($(DISTRO),)
DISTRO = generic
else
ifeq ($(DISTRO),debian-stable)
DEFS += -DNO_AFFINITY_NP
else
ifeq ($(DISTRO),ubuntu-intrepid)
# Force gcc-4.2 on ubuntu-intrepid
CC = @gcc -V 4.2
LD = g++-4.2
else
ifeq ($(DISTRO),gcc44-generic)
CC = @gcc -V 4.4
LD = @g++-4.4
else
$(error DISTRO $(DISTRO) unknown)
endif
endif
endif
endif

DEFS += -DDISTRO=$(DISTRO)

#-------------------------------------------------
# sanity check the configuration
#-------------------------------------------------

ifdef BIGENDIAN
X86_MIPS3_DRC =
X86_PPC_DRC =
FORCE_DRC_C_BACKEND = 1
endif

ifdef NOASM
X86_MIPS3_DRC =
X86_PPC_DRC =
FORCE_DRC_C_BACKEND = 1
endif

#-------------------------------------------------
# compile and linking flags
#-------------------------------------------------
BASE_TARGETOS = unix
SYNC_IMPLEMENTATION = tc

#-------------------------------------------------
# Sanity checks
#-------------------------------------------------
ifeq ($(BASE_TARGETOS),)
$(error $(TARGETOS) not supported !)
endif

#-------------------------------------------------
# object and source roots
#-------------------------------------------------
SDLSRC = $(SRC)/osd/$(OSD)
SDLOBJ = $(OBJ)/osd/$(OSD)

OBJDIRS += $(SDLOBJ)

#-------------------------------------------------
# OSD core library
#-------------------------------------------------

OSDCOREOBJS = \
	$(SDLOBJ)/strconv.o	\
	$(SDLOBJ)/sdldir.o	\
	$(SDLOBJ)/sdlfile.o 	\
	$(SDLOBJ)/sdlptty_$(BASE_TARGETOS).o	\
	$(SDLOBJ)/sdlsocket.o	\
	$(SDLOBJ)/sdlmisc_$(BASE_TARGETOS).o	\
	$(SDLOBJ)/sdlos_$(BASE_TARGETOS).o	\
	$(SDLOBJ)/sdlsync_$(SYNC_IMPLEMENTATION).o     \
	$(SDLOBJ)/sdlwork.o

# any "main" must be in LIBOSD or else the build will fail!
# for the windows build, we just add it to libocore as well.
OSDOBJS = \
	$(SDLMAIN) \
	$(SDLOBJ)/sdlmain.o \
	$(SDLOBJ)/input.o \
	$(SDLOBJ)/sound.o  \
	$(SDLOBJ)/video.o \
	$(SDLOBJ)/drawsdl.o \
	$(SDLOBJ)/window.o \
	$(SDLOBJ)/output.o \
	$(SDLOBJ)/watchdog.o

# Add SDL1.3 support
ifdef SDL_INSTALL_ROOT
OSDOBJS += $(SDLOBJ)/draw13.o
endif

# add an ARCH define
DEFS += "-DSDLMAME_ARCH=$(ARCHOPTS)" -DSYNC_IMPLEMENTATION=$(SYNC_IMPLEMENTATION)

#-------------------------------------------------
# Generic defines and additions
#-------------------------------------------------
OSDCLEAN = sdlclean
# add the debugger includes
INCPATH += -Isrc/debug
# add the prefix file
INCPATH += -include $(SDLSRC)/sdlprefix.h

#-------------------------------------------------
# BASE_TARGETOS specific configurations
#-------------------------------------------------
#-------------------------------------------------
# Unix
#-------------------------------------------------
DEFS += -DSDLMAME_UNIX
DEBUGOBJS = 
LIBGL = -lGL
NO_DEBUGGER = 1
LIBS += -lSDL_ttf -lutil


#-------------------------------------------------
# OPENGL
#-------------------------------------------------
ifeq ($(NO_OPENGL),1)
DEFS += -DUSE_OPENGL=0
else
OSDOBJS += $(SDLOBJ)/drawogl.o $(SDLOBJ)/gl_shader_tool.o $(SDLOBJ)/gl_shader_mgr.o
DEFS += -DUSE_OPENGL=1
ifeq ($(USE_DISPATCH_GL),1)
DEFS += -DUSE_DISPATCH_GL=1
else
LIBS += $(LIBGL)
endif
endif

ifneq ($(USE_DISPATCH_GL),1)
ifdef MESA_INSTALL_ROOT
LIBS += -L$(MESA_INSTALL_ROOT)/lib
LDFLAGS += -Wl,-rpath=$(MESA_INSTALL_ROOT)/lib
INCPATH += -I$(MESA_INSTALL_ROOT)/include
endif
endif

#-------------------------------------------------
# X11
#-------------------------------------------------
DEFS += -DSDLMAME_NO_X11

#-------------------------------------------------
# Dependencies
#-------------------------------------------------

# due to quirks of using /bin/sh, we need to explicitly specify the current path
CURPATH = ./

# drawSDL depends on the core software renderer, so make sure it exists
$(SDLOBJ)/drawsdl.o : $(SRC)/emu/rendersw.c
$(SDLOBJ)/drawogl.o : $(SDLSRC)/texcopy.c $(SDLSRC)/texsrc.h

#$(OSDCOREOBJS): $(SDLSRC)/sdl.mak
#$(OSDOBJS): $(SDLSRC)/sdl.mak
$(LIBOCORE): $(OSDCOREOBJS)
$(LIBOSD): $(OSDOBJS)

#-------------------------------------------------
# Tools
#-------------------------------------------------

TOOLS += \
	testkeys$(EXE)

$(SDLOBJ)/testkeys.o: $(SDLSRC)/testkeys.c
	@echo Compiling $<...
	$(CC)  $(CFLAGS) $(DEFS) -c $< -o $@

TESTKEYSOBJS = \
	$(SDLOBJ)/testkeys.o \

testkeys$(EXE): $(TESTKEYSOBJS) $(LIBUTIL) $(LIBOCORE) $(SDLUTILMAIN)
	@echo Linking $@...
	$(LD) $(LDFLAGS) $^ $(LIBS) -o $@

#-------------------------------------------------
# clean up
#-------------------------------------------------

$(OSDCLEAN):
	@rm -f .depend_*

#-------------------------------------------------
# various support targets
#-------------------------------------------------

testlib:
	-echo LIBS: $(LIBS)
	-echo DEFS: $(DEFS)
	-echo CORE: $(OSDCOREOBJS)

ifneq ($(TARGETOS),win32)
BUILD_VERSION = $(shell grep 'build_version\[\] =' src/version.c | sed -e "s/.*= \"//g" -e "s/ .*//g")
DISTFILES = test_dist.sh whatsnew.txt whatsnew_$(BUILD_VERSION).txt makefile  docs/ src/
EXCLUDES = -x "*/.svn/*"

zip:
	zip -rq ../mame_$(BUILD_VERSION).zip $(DISTFILES) $(EXCLUDES)

endif

