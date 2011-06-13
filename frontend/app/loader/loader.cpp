#include <cell/cell_fs.h>
#include <sys/process.h>

int				main		(int argc, char** argv)
{
	cellFsChmod("/dev_hdd0/game/MAME90000/USRDIR/frontend.self", 0777);
	sys_game_process_exitspawn2("/dev_hdd0/game/MAME90000/USRDIR/frontend.self", NULL, NULL, NULL, 0, 64, SYS_PROCESS_PRIMARY_STACK_SIZE_512K);
}

