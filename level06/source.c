#include <sys/syscall.h>
#include <sys/ptrace.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
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

int	auth(char *param_1, unsigned int param_2)
{
	size_t			sVar1;
	int				uVar2;
	long			lVar3;
	int				local_18;
	unsigned int	local_14;

	sVar1 = strcspn(param_1, "\n");
	param_1[sVar1] = '\0';
	sVar1 = strnlen(param_1, 32);
	if ((int)sVar1 < 6)
		uVar2 = 1;
	else
	{
		lVar3 = ptrace(PTRACE_TRACEME);
		if (lVar3 == -1)
		{
			puts("\x1b[32m.---------------------------.");
			puts("\x1b[31m| !! TAMPERING DETECTED !!  |");
			puts("\x1b[32m\'---------------------------\'");
			uVar2 = 1;
		}
		else
		{
			local_14 = ((int)param_1[3] ^ 4919) + 6221293;
			for (local_18 = 0; local_18 < (int)sVar1; local_18++)
			{
				if (param_1[local_18] < ' ')
					return (1);
				local_14 = local_14 + ((int)param_1[local_18] ^ local_14) % 1337;
			}
			if (param_2 == local_14)
				uVar2 = 0;
			else
				uVar2 = 1;
		}
	}
	return (uVar2);
}

int	main(void)
{
	int		iVar1;
	int		in_GS_OFFSET;
	char	local_34[32];
	int		local_14;

	local_14 = *(int *)(in_GS_OFFSET + 20);
	puts("***********************************");
	puts("*\t\tlevel06\t\t	*");
	puts("***********************************");
	printf("-> Enter Login: ");
	fgets(local_34, 32, stdin);
	puts("***********************************");
	puts("***** NEW ACCOUNT DETECTED ********");
	puts("***********************************");
	printf("-> Enter Serial: ");
	scanf("%u", &local_14);
	iVar1 = auth(local_34, local_14);
	if (iVar1 == 0)
	{
		puts("Authenticated!");
		system("/bin/sh");
	}
	// if (local_14 != *(int *)(in_GS_OFFSET + 20))
	// 	__stack_chk_fail();
	return (iVar1 != 0);
}
