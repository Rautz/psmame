#pragma once
#ifdef __CELLOS_LV2__
# define	LOG_FILE	"/dev_hdd0/game/MESS90000/USRDIR/mame.log"
# define	CONFIG_FILE	"/dev_hdd0/game/MAME90000/USRDIR/frontend.conf"
#else
# define	LOG_FILE	"./mame.log"
# define	CONFIG_FILE	"./frontend.conf"
#endif

