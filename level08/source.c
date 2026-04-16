#include <stdio.h>

void	log_wrapper(FILE *param_1, char *param_2, char *param_3)
{
	char			cVar1;
	size_t			sVar2;
	unsigned long	uVar3;
	unsigned long	uVar4;
	char			*pcVar5;
	long			in_FS_OFFSET;
	char			bVar6;
	FILE			*local_120;
	char			local_118[264];
	long			local_10;
	
	bVar6 = 0;
	local_10 = *(long *)(in_FS_OFFSET + 40);
	local_120 = param_1;
	strcpy(local_118, param_2);
	uVar3 = 0xffffffffffffffff;
	pcVar5 = local_118;
	do
	{
		if (uVar3 == 0)
			break;
		uVar3--;
		cVar1 = *pcVar5;
		pcVar5++;
	} while (cVar1 != '\0');
	uVar4 = 0xffffffffffffffff;
	pcVar5 = local_118;
	do
	{
		if (uVar4 == 0)
			break;
		uVar4--;
		cVar1 = *pcVar5;
		pcVar5++;
	} while (cVar1 != '\0');
	snprintf(local_118 + (~uVar4 - 1), 254 - (~uVar3 - 1), param_3);
	sVar2 = strcspn(local_118, "\n");
	local_118[sVar2] = '\0';
	fprintf(local_120, "LOG: %s\n", local_118);
	if (local_10 != *(long *)(in_FS_OFFSET + 40))
		__stack_chk_fail();
	return;
}

int	main(int param_1, int *param_2)
{
	char			cVar1;
	int				__fd;
	int				iVar2;
	FILE			*pFVar3;
	FILE			*__stream;
	unsigned long	uVar4;
	char			*pcVar5;
	long			in_FS_OFFSET;
	char			bVar6;
	char			local_79;
	char			local_78[104];
	long			local_10;

	bVar6 = 0;
	local_10 = *(long *)(in_FS_OFFSET + 40);
	local_79 = -1;
	if (param_1 != 2)
		printf("Usage: %s filename\n", *param_2);
	pFVar3 = fopen("./backups/.log", "w");
	if (pFVar3 == (FILE *)0x0)
	{
		printf("ERROR: Failed to open %s\n", "./backups/.log");
		exit(1);
	}
	log_wrapper(pFVar3, "Starting back up: ", param_2[1]);
	__stream = fopen((char *)param_2[1], "r");
	if (__stream == (FILE *)0x0)
	{
		printf("ERROR: Failed to open %s\n", param_2[1]);
		exit(1);
	}
	strncpy(local_78, "./backups/", 11);
	uVar4 = 0xffffffffffffffff;
	pcVar5 = local_78;
	do
	{
		if (uVar4 == 0)
			break;
		uVar4--;
		cVar1 = *pcVar5;
		pcVar5++;
	} while (cVar1 != '\0');
	strncat(local_78, (char *)param_2[1], 99 - (~uVar4 - 1));
	__fd = open(local_78, 193, 432);
	if (__fd < 0)
	{
		printf("ERROR: Failed to open %s%s\n", "./backups/", param_2[1]);
		exit(1);
	}
	while (1)
	{
		iVar2 = fgetc(__stream);
		local_79 = (char)iVar2;
		if (local_79 == -1)
			break;
		write(__fd, &local_79, 1);
	}
	log_wrapper(pFVar3, "Finished back up ", param_2[1]);
	fclose(__stream);
	close(__fd);
	if (local_10 != *(long *)(in_FS_OFFSET + 40))
		__stack_chk_fail();
	return (0);
}
