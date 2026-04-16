#include <sys/syscall.h>
#include <sys/ptrace.h>
#include <sys/prctl.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h> 
#include <signal.h> 
#include <stdio.h>

void	clear_stdin(void)
{
	int	iVar1;
	
	do
	{
		iVar1 = getchar();
		if ((char)iVar1 == '\n')
			return;
	} while ((char)iVar1 != -1);
	return;
}

int	get_unum(void)
{
	unsigned int	local_10;

	local_10 = 0;
	fflush(stdout);
	scanf("%u", &local_10);
	clear_stdin();
	return (local_10);
}

void	prog_timeout(int signum)
{
	syscall(SYS_exit, 1);
	return;
}

void	enable_timeout_cons(void)
{
	signal(14, prog_timeout);
	alarm(60);
	return;
}

int	main(void)
{
	int				iVar1;
	char			*pcVar2;
	char			bVar3;
	unsigned int	local_a4;
	char			local_a0[128];
	unsigned int	local_20;
	unsigned int	local_1c;
	long			local_18;
	int				local_14;
	
	bVar3 = 0;
	local_14 = fork();
	pcVar2 = local_a0;
	for (iVar1 = 128; iVar1 != 0; iVar1--)
	{
		pcVar2[0] = '\0';
		pcVar2[1] = '\0';
		pcVar2[2] = '\0';
		pcVar2[3] = '\0';
		pcVar2 += 4;
	}
	local_18 = 0;
	local_a4 = 0;
	if (local_14 == 0)
	{
		prctl(1, 1);
		ptrace(PTRACE_TRACEME, 0, 0, 0);
		puts("Give me some shellcode, k");
		gets(local_a0);
	}
	else
	{
		do
		{
			wait((int *)&local_a4);
			local_20 = local_a4;
			if (((local_a4 & 127) == 0) || (local_1c = local_a4, '\0' < (char)(((char)local_a4 & 127) + 1) >> 1))
			{
				puts("child is exiting...");
				return (0);
			}
			local_18 = ptrace(PTRACE_PEEKUSER, local_14, 44, 0);
		} while (local_18 != 11);
		puts("no exec() for you");
		kill(local_14, 9);
	}
	return (0);
}
