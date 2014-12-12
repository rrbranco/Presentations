#include <sys/syscall.h>

#define sys_mycall(x) syscall(SYS_exit, x);


main()
{
	sys_mycall(12);
}
