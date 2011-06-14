ifeq ($(strip $(PLATFORM)),)
	PLATFORM = cell
endif

TARGET			:=	libemusys
TYPE			:=	lib
BUILD			:=	build
SOURCE			:=	$(PLATFORM) src opengl_common src/utility src/utility/Files src/utility/GUI src/utility/GUI/Summerface 
INCLUDE			:=	. src src/lua src/fex

ifeq ($(strip $(PLATFORM)),cell)
	CXXFLAGS	:=	-DES_HOME_PATH=/dev_hdd0/game/MAME90000/USRDIR/
else
	CXXFLAGS	:=	-DES_HOME_PATH=psmame
endif

ifneq ($(BUILD)-$(PLATFORM),$(notdir $(CURDIR)))
	include $(CURDIR)/../Makefile-$(PLATFORM).base
else
	include $(CURDIR)/../../Makefile-$(PLATFORM).base
endif
