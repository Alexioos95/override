What do we have?

	$ ll
	total 17
	dr-xr-x---+ 1 level03 level03   80 Sep 13  2016 ./
	dr-x--x--x  1 root    root     260 Oct  2  2016 ../
	-rw-r--r--  1 level03 level03  220 Sep 10  2016 .bash_logout
	lrwxrwxrwx  1 root    root       7 Sep 13  2016 .bash_profile -> .bashrc
	-rw-r--r--  1 level03 level03 3533 Sep 10  2016 .bashrc
	-rwsr-s---+ 1 level04 users   7677 Sep 10  2016 level03*
	-rw-r--r--+ 1 level03 level03   41 Oct 19  2016 .pass
	-rw-r--r--  1 level03 level03  675 Sep 10  2016 .profile

A `level03` binary. Let's check the assembly:

	$ gdb ./level03
	[...]
	(gdb) b main
	[...]
	(gdb) r
	[...]
	(gdb) disas
	Dump of assembler code for function main:
	0x0804885a <+0>:	push   %ebp
	0x0804885b <+1>:	mov    %esp,%ebp
	=> 0x0804885d <+3>:	and    $0xfffffff0,%esp
	0x08048860 <+6>:	sub    $0x20,%esp
	0x08048863 <+9>:	push   %eax
	0x08048864 <+10>:	xor    %eax,%eax
	0x08048866 <+12>:	je     0x804886b <main+17>
	0x08048868 <+14>:	add    $0x4,%esp
	0x0804886b <+17>:	pop    %eax
	0x0804886c <+18>:	movl   $0x0,(%esp)
	0x08048873 <+25>:	call   0x80484b0 <time@plt>
	0x08048878 <+30>:	mov    %eax,(%esp)
	0x0804887b <+33>:	call   0x8048500 <srand@plt>
	0x08048880 <+38>:	movl   $0x8048a48,(%esp)
	0x08048887 <+45>:	call   0x80484d0 <puts@plt>
	0x0804888c <+50>:	movl   $0x8048a6c,(%esp)
	0x08048893 <+57>:	call   0x80484d0 <puts@plt>
	0x08048898 <+62>:	movl   $0x8048a48,(%esp)
	0x0804889f <+69>:	call   0x80484d0 <puts@plt>
	0x080488a4 <+74>:	mov    $0x8048a7b,%eax
	0x080488a9 <+79>:	mov    %eax,(%esp)
	0x080488ac <+82>:	call   0x8048480 <printf@plt>
	0x080488b1 <+87>:	mov    $0x8048a85,%eax
	0x080488b6 <+92>:	lea    0x1c(%esp),%edx
	0x080488ba <+96>:	mov    %edx,0x4(%esp)
	0x080488be <+100>:	mov    %eax,(%esp)
	0x080488c1 <+103>:	call   0x8048530 <__isoc99_scanf@plt>
	0x080488c6 <+108>:	mov    0x1c(%esp),%eax
	0x080488ca <+112>:	movl   $0x1337d00d,0x4(%esp)
	0x080488d2 <+120>:	mov    %eax,(%esp)
	0x080488d5 <+123>:	call   0x8048747 <test>
	0x080488da <+128>:	mov    $0x0,%eax
	0x080488df <+133>:	leave  
	0x080488e0 <+134>:	ret    
	End of assembler dump.

	(gdb) info functions
	[...]
	0x080485f4  clear_stdin
	0x08048617  get_unum
	0x0804864f  prog_timeout
	0x08048660  decrypt
	0x08048747  test
	0x0804885a  main

	(gdb) disas clear_stdin
	Dump of assembler code for function clear_stdin:
	0x080485f4 <+0>:	push   %ebp
	0x080485f5 <+1>:	mov    %esp,%ebp
	0x080485f7 <+3>:	sub    $0x18,%esp
	0x080485fa <+6>:	movb   $0x0,-0x9(%ebp)
	0x080485fe <+10>:	jmp    0x8048601 <clear_stdin+13>
	0x08048600 <+12>:	nop
	0x08048601 <+13>:	call   0x80484a0 <getchar@plt>
	0x08048606 <+18>:	mov    %al,-0x9(%ebp)
	0x08048609 <+21>:	cmpb   $0xa,-0x9(%ebp)
	0x0804860d <+25>:	je     0x8048615 <clear_stdin+33>
	0x0804860f <+27>:	cmpb   $0xff,-0x9(%ebp)
	0x08048613 <+31>:	jne    0x8048600 <clear_stdin+12>
	0x08048615 <+33>:	leave  
	0x08048616 <+34>:	ret    
	End of assembler dump.

	(gdb) disas get_unum
	Dump of assembler code for function get_unum:
	0x08048617 <+0>:	push   %ebp
	0x08048618 <+1>:	mov    %esp,%ebp
	0x0804861a <+3>:	sub    $0x28,%esp
	0x0804861d <+6>:	movl   $0x0,-0xc(%ebp)
	0x08048624 <+13>:	mov    0x804a040,%eax
	0x08048629 <+18>:	mov    %eax,(%esp)
	0x0804862c <+21>:	call   0x8048490 <fflush@plt>
	0x08048631 <+26>:	mov    $0x80489c0,%eax
	0x08048636 <+31>:	lea    -0xc(%ebp),%edx
	0x08048639 <+34>:	mov    %edx,0x4(%esp)
	0x0804863d <+38>:	mov    %eax,(%esp)
	0x08048640 <+41>:	call   0x8048530 <__isoc99_scanf@plt>
	0x08048645 <+46>:	call   0x80485f4 <clear_stdin>
	0x0804864a <+51>:	mov    -0xc(%ebp),%eax
	0x0804864d <+54>:	leave  
	0x0804864e <+55>:	ret    
	End of assembler dump.

	(gdb) disas prog_timeout
	Dump of assembler code for function prog_timeout:
	0x0804864f <+0>:	push   %ebp
	0x08048650 <+1>:	mov    %esp,%ebp
	0x08048652 <+3>:	mov    $0x1,%eax
	0x08048657 <+8>:	mov    $0x1,%ebx
	0x0804865c <+13>:	int    $0x80
	0x0804865e <+15>:	pop    %ebp
	0x0804865f <+16>:	ret    
	End of assembler dump.

	(gdb) disas decrypt
	Dump of assembler code for function decrypt:
	0x08048660 <+0>:	push   %ebp
	0x08048661 <+1>:	mov    %esp,%ebp
	0x08048663 <+3>:	push   %edi
	0x08048664 <+4>:	push   %esi
	0x08048665 <+5>:	sub    $0x40,%esp
	0x08048668 <+8>:	mov    %gs:0x14,%eax
	0x0804866e <+14>:	mov    %eax,-0xc(%ebp)
	0x08048671 <+17>:	xor    %eax,%eax
	0x08048673 <+19>:	movl   $0x757c7d51,-0x1d(%ebp)
	0x0804867a <+26>:	movl   $0x67667360,-0x19(%ebp)
	0x08048681 <+33>:	movl   $0x7b66737e,-0x15(%ebp)
	0x08048688 <+40>:	movl   $0x33617c7d,-0x11(%ebp)
	0x0804868f <+47>:	movb   $0x0,-0xd(%ebp)
	0x08048693 <+51>:	push   %eax
	0x08048694 <+52>:	xor    %eax,%eax
	0x08048696 <+54>:	je     0x804869b <decrypt+59>
	0x08048698 <+56>:	add    $0x4,%esp
	0x0804869b <+59>:	pop    %eax
	0x0804869c <+60>:	lea    -0x1d(%ebp),%eax
	0x0804869f <+63>:	movl   $0xffffffff,-0x2c(%ebp)
	0x080486a6 <+70>:	mov    %eax,%edx
	0x080486a8 <+72>:	mov    $0x0,%eax
	0x080486ad <+77>:	mov    -0x2c(%ebp),%ecx
	0x080486b0 <+80>:	mov    %edx,%edi
	0x080486b2 <+82>:	repnz scas %es:(%edi),%al
	0x080486b4 <+84>:	mov    %ecx,%eax
	0x080486b6 <+86>:	not    %eax
	0x080486b8 <+88>:	sub    $0x1,%eax
	0x080486bb <+91>:	mov    %eax,-0x24(%ebp)
	0x080486be <+94>:	movl   $0x0,-0x28(%ebp)
	0x080486c5 <+101>:	jmp    0x80486e5 <decrypt+133>
	0x080486c7 <+103>:	lea    -0x1d(%ebp),%eax
	0x080486ca <+106>:	add    -0x28(%ebp),%eax
	0x080486cd <+109>:	movzbl (%eax),%eax
	0x080486d0 <+112>:	mov    %eax,%edx
	0x080486d2 <+114>:	mov    0x8(%ebp),%eax
	0x080486d5 <+117>:	xor    %edx,%eax
	0x080486d7 <+119>:	mov    %eax,%edx
	0x080486d9 <+121>:	lea    -0x1d(%ebp),%eax
	0x080486dc <+124>:	add    -0x28(%ebp),%eax
	0x080486df <+127>:	mov    %dl,(%eax)
	0x080486e1 <+129>:	addl   $0x1,-0x28(%ebp)
	0x080486e5 <+133>:	mov    -0x28(%ebp),%eax
	0x080486e8 <+136>:	cmp    -0x24(%ebp),%eax
	0x080486eb <+139>:	jb     0x80486c7 <decrypt+103>
	0x080486ed <+141>:	lea    -0x1d(%ebp),%eax
	0x080486f0 <+144>:	mov    %eax,%edx
	0x080486f2 <+146>:	mov    $0x80489c3,%eax
	0x080486f7 <+151>:	mov    $0x11,%ecx
	0x080486fc <+156>:	mov    %edx,%esi
	0x080486fe <+158>:	mov    %eax,%edi
	0x08048700 <+160>:	repz cmpsb %es:(%edi),%ds:(%esi)
	0x08048702 <+162>:	seta   %dl
	0x08048705 <+165>:	setb   %al
	0x08048708 <+168>:	mov    %edx,%ecx
	0x0804870a <+170>:	sub    %al,%cl
	0x0804870c <+172>:	mov    %ecx,%eax
	0x0804870e <+174>:	movsbl %al,%eax
	0x08048711 <+177>:	test   %eax,%eax
	0x08048713 <+179>:	jne    0x8048723 <decrypt+195>
	0x08048715 <+181>:	movl   $0x80489d4,(%esp)
	0x0804871c <+188>:	call   0x80484e0 <system@plt>
	0x08048721 <+193>:	jmp    0x804872f <decrypt+207>
	0x08048723 <+195>:	movl   $0x80489dc,(%esp)
	0x0804872a <+202>:	call   0x80484d0 <puts@plt>
	0x0804872f <+207>:	mov    -0xc(%ebp),%esi
	0x08048732 <+210>:	xor    %gs:0x14,%esi
	0x08048739 <+217>:	je     0x8048740 <decrypt+224>
	0x0804873b <+219>:	call   0x80484c0 <__stack_chk_fail@plt>
	0x08048740 <+224>:	add    $0x40,%esp
	0x08048743 <+227>:	pop    %esi
	0x08048744 <+228>:	pop    %edi
	0x08048745 <+229>:	pop    %ebp
	0x08048746 <+230>:	ret    
	End of assembler dump.

	(gdb) disas test
	Dump of assembler code for function test:
	0x08048747 <+0>:	push   %ebp
	0x08048748 <+1>:	mov    %esp,%ebp
	0x0804874a <+3>:	sub    $0x28,%esp
	0x0804874d <+6>:	mov    0x8(%ebp),%eax
	0x08048750 <+9>:	mov    0xc(%ebp),%edx
	0x08048753 <+12>:	mov    %edx,%ecx
	0x08048755 <+14>:	sub    %eax,%ecx
	0x08048757 <+16>:	mov    %ecx,%eax
	0x08048759 <+18>:	mov    %eax,-0xc(%ebp)
	0x0804875c <+21>:	cmpl   $0x15,-0xc(%ebp)
	0x08048760 <+25>:	ja     0x804884a <test+259>
	0x08048766 <+31>:	mov    -0xc(%ebp),%eax
	0x08048769 <+34>:	shl    $0x2,%eax
	0x0804876c <+37>:	add    $0x80489f0,%eax
	0x08048771 <+42>:	mov    (%eax),%eax
	0x08048773 <+44>:	jmp    *%eax
	0x08048775 <+46>:	mov    -0xc(%ebp),%eax
	0x08048778 <+49>:	mov    %eax,(%esp)
	0x0804877b <+52>:	call   0x8048660 <decrypt>
	0x08048780 <+57>:	jmp    0x8048858 <test+273>
	0x08048785 <+62>:	mov    -0xc(%ebp),%eax
	0x08048788 <+65>:	mov    %eax,(%esp)
	0x0804878b <+68>:	call   0x8048660 <decrypt>
	0x08048790 <+73>:	jmp    0x8048858 <test+273>
	0x08048795 <+78>:	mov    -0xc(%ebp),%eax
	0x08048798 <+81>:	mov    %eax,(%esp)
	0x0804879b <+84>:	call   0x8048660 <decrypt>
	0x080487a0 <+89>:	jmp    0x8048858 <test+273>
	0x080487a5 <+94>:	mov    -0xc(%ebp),%eax
	0x080487a8 <+97>:	mov    %eax,(%esp)
	0x080487ab <+100>:	call   0x8048660 <decrypt>
	0x080487b0 <+105>:	jmp    0x8048858 <test+273>
	0x080487b5 <+110>:	mov    -0xc(%ebp),%eax
	0x080487b8 <+113>:	mov    %eax,(%esp)
	0x080487bb <+116>:	call   0x8048660 <decrypt>
	0x080487c0 <+121>:	jmp    0x8048858 <test+273>
	0x080487c5 <+126>:	mov    -0xc(%ebp),%eax
	0x080487c8 <+129>:	mov    %eax,(%esp)
	0x080487cb <+132>:	call   0x8048660 <decrypt>
	0x080487d0 <+137>:	jmp    0x8048858 <test+273>
	0x080487d5 <+142>:	mov    -0xc(%ebp),%eax
	0x080487d8 <+145>:	mov    %eax,(%esp)
	0x080487db <+148>:	call   0x8048660 <decrypt>
	0x080487e0 <+153>:	jmp    0x8048858 <test+273>
	0x080487e2 <+155>:	mov    -0xc(%ebp),%eax
	0x080487e5 <+158>:	mov    %eax,(%esp)
	0x080487e8 <+161>:	call   0x8048660 <decrypt>
	0x080487ed <+166>:	jmp    0x8048858 <test+273>
	0x080487ef <+168>:	mov    -0xc(%ebp),%eax
	0x080487f2 <+171>:	mov    %eax,(%esp)
	0x080487f5 <+174>:	call   0x8048660 <decrypt>
	0x080487fa <+179>:	jmp    0x8048858 <test+273>
	0x080487fc <+181>:	mov    -0xc(%ebp),%eax
	0x080487ff <+184>:	mov    %eax,(%esp)
	0x08048802 <+187>:	call   0x8048660 <decrypt>
	0x08048807 <+192>:	jmp    0x8048858 <test+273>
	0x08048809 <+194>:	mov    -0xc(%ebp),%eax
	0x0804880c <+197>:	mov    %eax,(%esp)
	0x0804880f <+200>:	call   0x8048660 <decrypt>
	0x08048814 <+205>:	jmp    0x8048858 <test+273>
	0x08048816 <+207>:	mov    -0xc(%ebp),%eax
	0x08048819 <+210>:	mov    %eax,(%esp)
	0x0804881c <+213>:	call   0x8048660 <decrypt>
	0x08048821 <+218>:	jmp    0x8048858 <test+273>
	0x08048823 <+220>:	mov    -0xc(%ebp),%eax
	0x08048826 <+223>:	mov    %eax,(%esp)
	0x08048829 <+226>:	call   0x8048660 <decrypt>
	0x0804882e <+231>:	jmp    0x8048858 <test+273>
	0x08048830 <+233>:	mov    -0xc(%ebp),%eax
	0x08048833 <+236>:	mov    %eax,(%esp)
	0x08048836 <+239>:	call   0x8048660 <decrypt>
	0x0804883b <+244>:	jmp    0x8048858 <test+273>
	0x0804883d <+246>:	mov    -0xc(%ebp),%eax
	0x08048840 <+249>:	mov    %eax,(%esp)
	0x08048843 <+252>:	call   0x8048660 <decrypt>
	0x08048848 <+257>:	jmp    0x8048858 <test+273>
	0x0804884a <+259>:	call   0x8048520 <rand@plt>
	0x0804884f <+264>:	mov    %eax,(%esp)
	0x08048852 <+267>:	call   0x8048660 <decrypt>
	0x08048857 <+272>:	nop
	0x08048858 <+273>:	leave  
	0x08048859 <+274>:	ret    
	End of assembler dump.

Cleaned https://dogbolt.org/ output (as just `Ghidra` seemed to be extremely confusing and just plainly wrong):

	void clear_stdin(void)
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

Clear stdin.

	int	get_unum(void)
	{
		unsigned int	local_10;

		local_10 = 0;
		fflush(stdout);
		scanf("%u", &local_10);
		clear_stdin();
		return (local_10);
	}

Read stdin and return the unsigned int read.

	void	prog_timeout(void)
	{
		syscall(SYS_exit, 1);
		return;
	}

Leave the program.

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
		
		local_10 = *(int *)(in_GS_OFFSET + 20);
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

Init vars and decrement `uVar2` (4294967295) until the `\0` of local_21 is reached (so -18 = 4294967277).

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

A XOR loop. ~4294967277 - 1 = 241 mean it's ran 241 times.

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
		if (local_10 == *(int *)(in_GS_OFFSET + 20))
			return (iVar3);
		__stack_chk_fail();
	}

If the string matches with `Congratulations!`, start a shell.

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

Decrypt depending on the result of param_2 - param_1, using random if it's not between 1 and 9 or 16 and 21.

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

Print, into a call to `test` done with the result of a `scanf` and 322424845.

We want to do a certain XOR to make our string correspond to the one it's compared. `ctx` will be equal to the difference between 322424845 and our input, and that difference must be between 1-9 or 16-21. 18 is used to decrement uVar2, so we tried with that randomly. 322424845 - 18 = 322424827.

	$ ./level03
	***********************************
	*               level03         **
	***********************************
	Password:322424827
	$ cat /home/users/level04/.pass
	kgv3tkEb9h2mLkRsPkXRfc2mHbjMxQzvb2FrgKkf

Well, we got lucky.
