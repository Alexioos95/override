#include <stdio.h>

void secret_backdoor(void)
{
	char	local_88[128];

	fgets(local_88, 128, stdin);
	system(local_88);
	return;
}

void	set_username(long param_1)
{
	long	lVar1;
	char	*pcVar2;
	char	local_98[140];
	int		local_c;
	
	pcVar2 = local_98;
	for (lVar1 = 16; lVar1 != 0; lVar1--)
	{
		pcVar2[0] = '\0';
		pcVar2[1] = '\0';
		pcVar2[2] = '\0';
		pcVar2[3] = '\0';
		pcVar2[4] = '\0';
		pcVar2[5] = '\0';
		pcVar2[6] = '\0';
		pcVar2[7] = '\0';
		pcVar2 += 8;
	}
	puts(">: Enter your username");
	printf(">>: ");
	fgets(local_98, 128, stdin);
	for (local_c = 0; (local_c < 41 && (local_98[local_c] != '\0')); local_c++)
	{
		*(char *)(param_1 + 140 + (long)local_c) = local_98[local_c];
	}
	printf(">: Welcome, %s", param_1 + 140);
	return;
}

void	set_msg(char *param_1)
{
	long	lVar1;
	char	*pcVar2;
	char	local_408[1024];
	
	pcVar2 = local_408;
	for (lVar1 = 128; lVar1 != 0; lVar1--)
	{
		pcVar2[0] = '\0';
		pcVar2[1] = '\0';
		pcVar2[2] = '\0';
		pcVar2[3] = '\0';
		pcVar2[4] = '\0';
		pcVar2[5] = '\0';
		pcVar2[6] = '\0';
		pcVar2[7] = '\0';
		pcVar2 += 8;
	}
	puts(">: Msg @Unix-Dude");
	printf(">>: ");
	fgets(local_408, 1024, stdin);
	strncpy(param_1, local_408, (long)*(int *)(param_1 + 180));
	return;
}

void	handle_msg(void)
{
	char	local_c8[140];
	char	local_3c[40];
	int		local_14;

	local_14 = 0;
	set_username(local_c8);
	set_msg(local_c8);
	puts(">: Msg sent!");
	return;
}

int main(void)
{
	puts("--------------------------------------------\n|   ~Welcome to l33t-m$n ~    v1337        |\n--------------------------------------------");
	handle_msg();
	return (0);
}
