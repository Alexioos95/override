#include <sys/syscall.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

char *DAT_08048d61 = "read";
char *DAT_08048d66 = "quit";

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


int	store_number(unsigned int *param_1)
{
	unsigned int	uVar1;
	unsigned int	uVar2;
	int				uVar3;

	printf(" Number: ");
	uVar1 = get_unum();
	printf(" Index: ");
	uVar2 = get_unum();
	if ((uVar2 % 3 == 0) || (uVar1 >> 24 == 183))
	{
		puts(" *** ERROR! ***");
		puts("	 This index is reserved for wil!");
		puts(" *** ERROR! ***");
		uVar3 = 1;
	}
	else
	{
		*(unsigned int *)(uVar2 * 4 + param_1) = uVar1;
		uVar3 = 0;
	}
	return (uVar3);
}

int	read_number(unsigned int *param_1)
{
	int	iVar1;

	printf(" Index: ");
	iVar1 = get_unum();
	printf(" Number at data[%u] is %u\n", iVar1, *(int *)(iVar1 * 4 + param_1));
	return (0);
}

int main(int param_1, int *param_2, int *param_3)
{
	char			cVar1;
	char			bVar2;
	int				iVar3;
	unsigned int	uVar4;
	char			*pbVar5;
	int				*puVar6;
	char			*pcVar7;
	char			*pbVar8;
	int				in_GS_OFFSET;
	bool			bVar9;
	bool			bVar10;
	bool			bVar11;
	char			bVar12;
	int				*local_1c8;
	int				*local_1c4;
	unsigned int	local_1bc[100];
	int				local_2c;
	char			local_28[20];
	int				local_14;

	bVar12 = 0;
	local_1c4 = param_2;
	local_1c8 = param_3;
	// local_14 = *(int *)(in_GS_OFFSET + 20);
	local_2c = 0;
	local_28[0] = 0;
	local_28[1] = 0;
	local_28[2] = 0;
	local_28[3] = 0;
	local_28[4] = 0;
	local_28[5] = 0;
	local_28[6] = 0;
	local_28[7] = 0;
	local_28[8] = 0;
	local_28[9] = 0;
	local_28[10] = 0;
	local_28[11] = 0;
	local_28[12] = 0;
	local_28[13] = 0;
	local_28[14] = 0;
	local_28[15] = 0;
	local_28[16] = 0;
	local_28[17] = 0;
	local_28[18] = 0;
	local_28[19] = 0;
	puVar6 = local_1bc;
	for (iVar3 = 100; iVar3 != 0; iVar3--)
	{
		*puVar6 = 0;
		puVar6++;
	}
	for (; *local_1c4 != 0; local_1c4++)
	{
		uVar4 = 0xffffffff;
		pcVar7 = (char *)*local_1c4;
		do
		{
			if (uVar4 == 0)
				break;
			uVar4--;
			cVar1 = *pcVar7;
			pcVar7++;
		} while (cVar1 != '\0');
		memset((void *)*local_1c4, 0, ~uVar4 - 1);
	}
	for (; *local_1c8 != 0; local_1c8++)
	{
		uVar4 = 0xffffffff;
		pcVar7 = (char *)*local_1c8;
		do
		{
			if (uVar4 == 0)
				break;
			uVar4--;
			cVar1 = *pcVar7;
			pcVar7++;
		} while (cVar1 != '\0');
		memset((void *)*local_1c8, 0, ~uVar4 - 1);
	}
	puts(
			"----------------------------------------------------\n  Welcome to wil\'s crappy number storage service!   \n----------------------------------------------------\n Commands:                                          \n    store - store a number into the data storage    \n    read  - read a number from the data storage     \n    quit  - exit the program                        \n----------------------------------------------------\n   wil has reserved some storage :>                 \n----------------------------------------------------\n"
	);
	do
	{
		printf("Input command: ");
		local_2c = 1;
		fgets((char *)local_28, 20, stdin);
		uVar4 = 0xffffffff;
		pbVar5 = local_28;
		do
		{
			if (uVar4 == 0)
				break;
			uVar4--;
			bVar2 = *pbVar5;
			pbVar5++;
		} while (bVar2 != 0);
		uVar4 = ~uVar4;
		bVar9 = uVar4 == 1;
		bVar11 = uVar4 == 2;
		*(char *)((int)&local_2c + uVar4 + 2) = 0;
		iVar3 = 5;
		pbVar5 = local_28;
		pbVar8 = (char *)"store";
		do
		{
			if (iVar3 == 0)
				break;
			iVar3--;
			bVar9 = *pbVar5 < *pbVar8;
			bVar11 = *pbVar5 == *pbVar8;
			pbVar5++;
			pbVar8++;
		} while (bVar11);
		bVar10 = false;
		bVar9 = (!bVar9 && !bVar11) == bVar9;
		if (bVar9)
			local_2c = store_number(local_1bc);
		else
		{
			iVar3 = 4;
			pbVar5 = local_28;
			pbVar8 = DAT_08048d61;
			do
			{
				if (iVar3 == 0)
					break;
				iVar3 = iVar3 + -1;
				bVar10 = *pbVar5 < *pbVar8;
				bVar9 = *pbVar5 == *pbVar8;
				pbVar5++;
				pbVar8++;
			} while (bVar9);
			bVar11 = false;
			bVar9 = (!bVar10 && !bVar9) == bVar10;
			if (bVar9)
				local_2c = read_number(local_1bc);
			else
			{
				iVar3 = 4;
				pbVar5 = local_28;
				pbVar8 = DAT_08048d66;
				do
				{
					if (iVar3 == 0)
						break;
					iVar3--;
					bVar11 = *pbVar5 < *pbVar8;
					bVar9 = *pbVar5 == *pbVar8;
					pbVar5++;
					pbVar8++;
				} while (bVar9);
				if ((!bVar11 && !bVar9) == bVar11)
				{
					// if (local_14 == *(int *)(in_GS_OFFSET + 20))
						// return (0);
					// __stack_chk_fail();
				}
			}
		}
		if (local_2c == 0)
			printf(" Completed %s command successfully\n", local_28);
		else
			printf(" Failed to do %s command\n", local_28);
		local_28[0] = 0;
		local_28[1] = 0;
		local_28[2] = 0;
		local_28[3] = 0;
		local_28[4] = 0;
		local_28[5] = 0;
		local_28[6] = 0;
		local_28[7] = 0;
		local_28[8] = 0;
		local_28[9] = 0;
		local_28[10] = 0;
		local_28[11] = 0;
		local_28[12] = 0;
		local_28[13] = 0;
		local_28[14] = 0;
		local_28[15] = 0;
		local_28[16] = 0;
		local_28[17] = 0;
		local_28[18] = 0;
		local_28[19] = 0;
	} while (1);
}
