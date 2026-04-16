#include <stdlib.h>
#include <stdio.h>

void	main(void)
{
	char			bVar1;
	unsigned int	uVar2;
	char			*pbVar3;
	char			bVar4;
	char			local_78[100];
	unsigned int	local_14;

	bVar4 = 0;
	local_14 = 0;
	fgets((char *)local_78, 100, stdin);
	local_14 = 0;
	do
	{
		uVar2 = 0xffffffff;
		pbVar3 = local_78;
		do
		{
			if (uVar2 == 0)
				break;
			uVar2--;
			bVar1 = *pbVar3;
			pbVar3++;
		} while (bVar1 != 0);
		if (~uVar2 - 1 <= local_14)
		{
			printf((char *)local_78);
			exit(0);
		}
		if (('@' < (char)local_78[local_14]) && ((char)local_78[local_14] < '['))
			local_78[local_14] = local_78[local_14] ^ 32;
		local_14++;
	} while (1);
}
