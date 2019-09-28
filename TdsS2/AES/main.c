#include <stdio.h>
#ifdef _WIN32
#include <conio.h>
#else
#include "linux_utils.h"
#include "AES.h"
#endif
#include <stdlib.h>


const byte StandardKey[16]= { 
	0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 
	0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c 
};

const byte StandardText[16] = { 
    0x32, 0x43, 0xf6, 0xa8, 0x88, 0x5a, 0x30, 0x8d, 
    0x31, 0x31, 0x98, 0xa2, 0xe0, 0x37, 0x07, 0x34 
};

int main(int argc, char **argv)
{
	int i;
	byte ciphertext[16] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	byte deciphertext[16] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
     
    // cipher text
	printf("Plain text : (Hex) ");
	for (i=0; i < 16; i++){
		printf("%02x ",StandardText[i]);
	}
	printf("\n (ASCII) %s\n", StandardText);
	AES_InitKey(StandardKey);
	AES_SetPlainText(StandardText);
	AES_Run();
	AES_GetCipherText(&ciphertext[0]);
	printf("\nCipher text at the end: (Hex) ");
	for (i=0; i < 16; i++){
		printf("%02x ",ciphertext[i]);
	}
	printf("\n (ASCII) %s\n", ciphertext);

    // decipher cipher text
	printf("Cipher text to decipher: (Hex) ");
	for (i=0; i <= 16; i++){
		printf("%02x ",ciphertext[i]);
	}
    printf("\n");
    AES_SetCipherText(ciphertext);
    AES_InitKey(StandardKey);
    AES_Decipher();
    AES_GetPlainText(&deciphertext[0]);
	printf("\nObtained plain text : (Hex) ");
	for (i=0; i < 16; i++){
		printf("%02x ",deciphertext[i]);
	}
    deciphertext[16] = '\0';
	printf("\n (ASCII) %s\n\n", deciphertext);
   

    // export round values
	int j;
    unsigned Nr = 10;
	State *round = (State *) malloc((Nr+1)*sizeof(State));
	AES_InitKey(StandardKey);
	AES_SetPlainText(StandardText);
	AES_RunandStoreState(Nr,round);
	for (i=0; i<Nr;i++){
		printf("\nRound %d",i);
		printf("\n\tStart : ");
		for(j=0; j<16; j++) printf("%02x ",round[i].start[j]);
		if (i) {
			printf("\n\tSBox : "); 
			for(j=0; j<16; j++) 
				printf("%02x ",round[i].sbox[j]);}
		
		if (i) {
			printf("\n\tShiftRow : ");
			for(j=0; j<16; j++) printf("%02x ",round[i].shiftrow[j]);
		}
		if (i && i != 10) {
			printf("\n\tMixColumn : ");
			for(j=0; j<16; j++) printf("%02x ",round[i].mixcolumn[j]);
		}
		printf("\n\tAddRoundKey : ");
		for(j=0; j<16; j++) printf("%02x ",round[i].roundkey[j]);
	}
	AES_GetCipherText(&ciphertext[0]);
	printf("\nCipher text after %d round:", Nr);
	for (i=0; i < 16; i++){
		printf("%02x ",ciphertext[i]);
	}
	printf("\n");
	// delete round pointer
	free(round);


    /* wait for hit key.... */
    while(!_kbhit());
	return 0;
}
