#pragma once
#ifdef __CELLOS_LV2__
# define	LOG_FILE	"/dev_hdd0/game/MESS90000/USRDIR/mame.log"
# define	CONFIG_FILE	"/dev_hdd0/game/MESS90000/USRDIR/frontend.conf"
# define	SYSTEM_XML	"/dev_hdd0/game/MESS90000/USRDIR/systems.xml"
#else
# define	LOG_FILE	"./mame.log"
# define	CONFIG_FILE	"./frontend.conf"
# define	SYSTEM_XML	"./systems.xml"
#endif

