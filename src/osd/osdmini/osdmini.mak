###########################################################################
#
#   osdmini.mak
#
#   Minimal OSD makefile
#
###########################################################################
#
#   Copyright Aaron Giles
#   All rights reserved.
#
#   Redistribution and use in source and binary forms, with or without
#   modification, are permitted provided that the following conditions are
#   met:
#
#       * Redistributions of source code must retain the above copyright
#         notice, this list of conditions and the following disclaimer.
#       * Redistributions in binary form must reproduce the above copyright
#         notice, this list of conditions and the following disclaimer in
#         the documentation and/or other materials provided with the
#         distribution.
#       * Neither the name 'MAME' nor the names of its contributors may be
#         used to endorse or promote products derived from this software
#         without specific prior written permission.
#
#   THIS SOFTWARE IS PROVIDED BY AARON GILES ''AS IS'' AND ANY EXPRESS OR
#   IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
#   WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
#   DISCLAIMED. IN NO EVENT SHALL AARON GILES BE LIABLE FOR ANY DIRECT,
#   INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
#   (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
#   SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
#   HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
#   STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
#   IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
#   POSSIBILITY OF SUCH DAMAGE.
#
###########################################################################


#-------------------------------------------------
# object and source roots
#-------------------------------------------------

MINISRC = $(SRC)/osd/$(OSD)
MINIOBJ = $(OBJ)/osd/$(OSD)

OBJDIRS += $(MINIOBJ) $(MINIOBJ)/system/src $(MINIOBJ)/system/cell
CCOMFLAGS += -DMDCELL -DPSGL -I$(SRC)/osd/$(OSD)/system
LIBS += -L$(CELL_SDK)/target/ppu/lib -L$(CELL_SDK)/target/ppu/lib/PSGL/RSX/ultra-opt -lPSGL -lm -lnet_stub -lfs_stub -lio_stub -lsysutil_stub -lsysmodule_stub -lgcm_cmd -lresc_stub -lgcm_sys_stub -laudio_stub 

#-------------------------------------------------
# OSD core library
#-------------------------------------------------
OSDCOREOBJS = \
	$(MINIOBJ)/minidir.o \
	$(MINIOBJ)/minifile.o \
	$(MINIOBJ)/minimisc.o \
	$(MINIOBJ)/minisync.o \
	$(MINIOBJ)/minitime.o \
	$(MINIOBJ)/miniwork.o \
	$(MINIOBJ)/system/src/main.o \
	$(MINIOBJ)/system/cell/main.o \
	$(MINIOBJ)/system/cell/CellAudio.o \
	$(MINIOBJ)/system/cell/CellVideo.o \
	$(MINIOBJ)/system/cell/CellInput.o \
	$(MINIOBJ)/system/cell/CellNetwork.o \
	$(MINIOBJ)/system/cell/CellThreads.o \
	$(MINIOBJ)/system/cell/CellVideo.o 




#-------------------------------------------------
# OSD mini library
#-------------------------------------------------

OSDOBJS = \
	$(MINIOBJ)/minimain.o



#-------------------------------------------------
# rules for building the libaries
#-------------------------------------------------

$(LIBOCORE): $(OSDCOREOBJS)

$(LIBOSD): $(OSDOBJS)
