#include <sys/syscall.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

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

void	prog_timeout(void)
{
	syscall(SYS_exit, 1);
	return;
}

int	decrypt(int ctx, unsigned char *out, size_t *outlen, unsigned char *in, size_t inlen)
{
	char			bVar1;
	unsigned int	uVar2;
	int				iVar3;
	char			*pbVar4;
	char			*pbVar5;
	int				in_GS_OFFSET;
	bool			bVar6;
	bool			bVar7;
	unsigned int	local_2c;
	char			local_21[17];
	int				local_10;

	// local_10 = *(int *)(in_GS_OFFSET + 20);
	local_21[0] = 'Q';
	local_21[1] = '}';
	local_21[2] = '|';
	local_21[3] = 'u';
	local_21[4] = '`';
	local_21[5] = 's';
	local_21[6] = 'f';
	local_21[7] = 'g';
	local_21[8] = '~';
	local_21[9] = 's';
	local_21[10] = 'f';
	local_21[11] = '{';
	local_21[12] = '}';
	local_21[13] = '|';
	local_21[14] = 'a';
	local_21[15] = '3';
	local_21[16] = 0;
	uVar2 = 0xffffffff;
	pbVar4 = local_21;
	do
	{
		if (uVar2 == 0)
			break;
		uVar2--;
		bVar1 = *pbVar4;
		pbVar4++;
	} while (bVar1 != 0);
	local_2c = 0;
	while (true)
	{
		bVar6 = local_2c < ~uVar2 - 1;
		bVar7 = local_2c == ~uVar2 - 1;
		if (!bVar6)
			break;
		local_21[local_2c] = (char)ctx ^ local_21[local_2c];
		local_2c++;
	}
	iVar3 = 17;
	pbVar4 = local_21;
	pbVar5 = "Congratulations!";
	do
	{
		if (iVar3 == 0)
			break;
		iVar3--;
		bVar6 = *pbVar4 < *pbVar5;
		bVar7 = *pbVar4 == *pbVar5;
		pbVar4++;
		pbVar5++;
	} while (bVar7);
	if ((!bVar6 && !bVar7) == bVar6)
		iVar3 = system("/bin/sh");
	else
		iVar3 = puts("\nInvalid Password");
	// if (local_10 == *(int *)(in_GS_OFFSET + 20))
	// 	return (iVar3);
	__stack_chk_fail();
}

void	test(int param_1, int param_2)
{
	int 			pEVar1;
	unsigned char	*in_stack_ffffffd8;
	size_t			*in_stack_ffffffdc;
	unsigned char	*in_stack_ffffffe0;
	size_t			in_stack_ffffffe4;

	pEVar1 = (int)(param_2 - param_1);
	switch (pEVar1)
	{
		default:
			pEVar1 = (int)rand();
			decrypt(pEVar1, in_stack_ffffffd8 ,in_stack_ffffffdc, in_stack_ffffffe0, in_stack_ffffffe4);
			break;
		case (int)0x1:
			decrypt(pEVar1, in_stack_ffffffd8 ,in_stack_ffffffdc, in_stack_ffffffe0, in_stack_ffffffe4);
			break;
		case (int)0x2:
			decrypt(pEVar1, in_stack_ffffffd8 ,in_stack_ffffffdc, in_stack_ffffffe0, in_stack_ffffffe4);
			break;
		case (int)0x3:
			decrypt(pEVar1, in_stack_ffffffd8 ,in_stack_ffffffdc, in_stack_ffffffe0, in_stack_ffffffe4);
			break;
		case (int)0x4:
			decrypt(pEVar1, in_stack_ffffffd8 ,in_stack_ffffffdc, in_stack_ffffffe0, in_stack_ffffffe4);
			break;
		case (int)0x5:
			decrypt(pEVar1, in_stack_ffffffd8 ,in_stack_ffffffdc, in_stack_ffffffe0, in_stack_ffffffe4);
			break;
		case (int)0x6:
			decrypt(pEVar1, in_stack_ffffffd8 ,in_stack_ffffffdc, in_stack_ffffffe0, in_stack_ffffffe4);
			break;
		case (int)0x7:
			decrypt(pEVar1, in_stack_ffffffd8 ,in_stack_ffffffdc, in_stack_ffffffe0, in_stack_ffffffe4);
			break;
		case (int)0x8:
			decrypt(pEVar1, in_stack_ffffffd8 ,in_stack_ffffffdc, in_stack_ffffffe0, in_stack_ffffffe4);
			break;
		case (int)0x9:
			decrypt(pEVar1, in_stack_ffffffd8 ,in_stack_ffffffdc, in_stack_ffffffe0, in_stack_ffffffe4);
			break;
		case (int)0x10:
			decrypt(pEVar1, in_stack_ffffffd8 ,in_stack_ffffffdc, in_stack_ffffffe0, in_stack_ffffffe4);
			break;
		case (int)0x11:
			decrypt(pEVar1, in_stack_ffffffd8 ,in_stack_ffffffdc, in_stack_ffffffe0, in_stack_ffffffe4);
			break;
		case (int)0x12:
			decrypt(pEVar1, in_stack_ffffffd8 ,in_stack_ffffffdc, in_stack_ffffffe0, in_stack_ffffffe4);
			break;
		case (int)0x13:
			decrypt(pEVar1, in_stack_ffffffd8 ,in_stack_ffffffdc, in_stack_ffffffe0, in_stack_ffffffe4);
			break;
		case (int)0x14:
			decrypt(pEVar1, in_stack_ffffffd8 ,in_stack_ffffffdc, in_stack_ffffffe0, in_stack_ffffffe4);
			break;
		case (int)0x15:
			decrypt(pEVar1, in_stack_ffffffd8 ,in_stack_ffffffdc, in_stack_ffffffe0, in_stack_ffffffe4);
	}
	return;
}

int	main(void)
{
	unsigned int	__seed;
	int				savedregs;

	__seed = time((time_t *)0);
	srand(__seed);
	puts("***********************************");
	puts("*\t\tlevel03\t\t**");
	puts("***********************************");
	printf("Password:");
	scanf("%d", &savedregs);
	test(savedregs, 322424845);
	return (0);
}
