#pragma once
#ifdef __CELLOS_LV2__
# define	ROM_DIR		"/dev_hdd0/ROMS/mame"
# define	GAME_LIST	"/dev_hdd0/game/MAME90000/USRDIR/games.txt"
# define	LOG_FILE	"/dev_hdd0/game/MAME90000/USRDIR/mame.log"
# define	GAME_DB		"/dev_hdd0/game/MAME90000/USRDIR/gamedb"
# define	SNAP_DIR	"/dev_hdd0/ROMS/mame_data/snaps"
# define	CONFIG_FILE	"/dev_hdd0/game/MAME90000/USRDIR/frontend.conf"
#else
# define	ROM_DIR		"./ROMS"
# define	GAME_LIST	"./games.txt"
# define	LOG_FILE	"./mame.log"
# define	GAME_DB		"./gamedb"
# define	SNAP_DIR	"./snaps"
# define	CONFIG_FILE	"./frontend.conf"
#endif

