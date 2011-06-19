ifeq ($(strip $(PLATFORM)),)
	PLATFORM = cell
endif

##Package Details
SFOXML				:=	package/sfo.xml
ICON0				:=	package/ICON0.png
TITLE				:=	MESS
APPID				:=	MESS90000
CONTENTID			:=	UP0001-$(APPID)_00-0000000000000000

##Build info
TARGET				:=	psmess
TYPE				:=	bin
PACKAGE				:=	psmess.pkg
BUILD				:=	build
SOURCE				:=	src src/tinyxml

INCLUDE				:=	src src/tinyxml ../system
LIBDIRS				:=	../system
LIBS				:=	-lemusys-$(PLATFORM)

ifneq ($(BUILD)-$(PLATFORM),$(notdir $(CURDIR)))
	include $(CURDIR)/../Makefile-$(PLATFORM).base
else
	include $(CURDIR)/../../Makefile-$(PLATFORM).base
endif


