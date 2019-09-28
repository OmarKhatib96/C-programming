/* Definition des methodes pour l'AES */
#include <stdint.h>

#ifndef __AES_H
#define __AES_H

typedef uint8_t byte;
typedef struct {
	byte *start;
	byte *sbox;
	byte *shiftrow;
	byte *mixcolumn;
	byte *roundkey;
} State ;

void KeyExpansion(void);
void addRoundKey(void);
void subBytes(void);
void invsubBytes(void);
void shiftRows(void);
void invshiftRows(void);
void mixColumns(void);
uint8_t Multiply(byte x, byte y);
void invmixColumns(void);
void computeKey(byte rcon);
void InitState();
void AES_Run(void);
void AES_Decipher(void);
void AES_InitKey(const byte Key[16]);
void AES_SetPlainText(const byte Text[16]);
void AES_GetCipherText(byte *CipherText);
void AES_GetPlainText(byte *Text);
void AES_SetCipherText(const byte CipherText[16]);
void AES_RunandStoreState(unsigned Nr, State *round);
#endif // __AES_H
