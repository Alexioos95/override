#include <stdbool.h>
#include <stdio.h>

char	a_user_name[100];

int	verify_user_name(void)
{
	int		iVar1;
	char	*pbVar2;
	char	*pbVar3;
	char	uVar4;
	char	uVar5;
	char	bVar6;

	bVar6 = 0;
	puts("verifying username....\n");
	iVar1 = 7;
	pbVar2 = a_user_name;
	pbVar3 = "dat_wil";
	do
	{
		if (iVar1 == 0)
			break;
		iVar1--;
		uVar4 = *pbVar2 < *pbVar3;
		uVar5 = *pbVar2 == *pbVar3;
		pbVar2++;
		pbVar3++;
	} while ((bool)uVar5);
	return (int)(char)((!(bool)uVar4 && !(bool)uVar5) - uVar4);
}

int	verify_user_pass(char *param_1)
{
	int		iVar1;
	char	*pbVar2;
	char	in_CF;
	char	in_ZF;

	iVar1 = 5;
	pbVar2 = "admin";
	do
	{
		if (iVar1 == 0)
			break;
		iVar1--;
		in_CF = *param_1 < *pbVar2;
		in_ZF = *param_1 == *pbVar2;
		param_1++;
		pbVar2++;
	} while ((bool)in_ZF);
	return (int)(char)((!(bool)in_CF && !(bool)in_ZF) - in_CF);
}

int	main(void)
{
	int		uVar1;
	int		iVar2;
	char	*pcVar3;
	char	local_54[64];
	int		local_14;

	pcVar3 = local_54;
	for (iVar2 = 16; iVar2 != 0; iVar2--)
	{
		pcVar3[0] = '\0';
		pcVar3[1] = '\0';
		pcVar3[2] = '\0';
		pcVar3[3] = '\0';
		pcVar3 = pcVar3 + 4;
	}
	local_14 = 0;
	puts("********* ADMIN LOGIN PROMPT *********");
	printf("Enter Username: ");
	fgets(a_user_name, 256, stdin);
	local_14 = verify_user_name();
	if (local_14 == 0)
	{
		puts("Enter Password: ");
		fgets(local_54, 100, stdin);
		local_14 = verify_user_pass(local_54);
		if ((local_14 == 0) || (local_14 != 0))
		{
			puts("nope, incorrect password...\n");
			uVar1 = 1;
		}
		else
			uVar1 = 0;
	}
	else
	{
		puts("nope, incorrect username...\n");
		uVar1 = 1;
	}
	return (uVar1);
}
