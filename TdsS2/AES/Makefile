















all:  aes  

aes : AES.o linux_utils.o main.o
	gcc  AES.o linux_utils.o main.o  -o aes



main.o: main.c linux_utils.h AES.h
	gcc -c -g main.c


AES.o: AES.c AES.h
	gcc -c -g AES.c

linux_utils.o: linux_utils.c linux_utils.h
	gcc -c -g linux_utils.c
















