#include "AES.h"
#include <assert.h>
#include <stdlib.h>
#ifdef _DEBUG
#include <stdio.h>
#endif

// Sbox Lookup Table
const byte sbox[256] = {
    0x63, 0x7c, 0x77, 0x7b, 0xf2, 0x6b, 0x6f, 0xc5,
    0x30, 0x01, 0x67, 0x2b, 0xfe, 0xd7, 0xab, 0x76,
    0xca, 0x82, 0xc9, 0x7d, 0xfa, 0x59, 0x47, 0xf0,
    0xad, 0xd4, 0xa2, 0xaf, 0x9c, 0xa4, 0x72, 0xc0,
    0xb7, 0xfd, 0x93, 0x26, 0x36, 0x3f, 0xf7, 0xcc,
    0x34, 0xa5, 0xe5, 0xf1, 0x71, 0xd8, 0x31, 0x15,
    0x04, 0xc7, 0x23, 0xc3, 0x18, 0x96, 0x05, 0x9a,
    0x07, 0x12, 0x80, 0xe2, 0xeb, 0x27, 0xb2, 0x75,
    0x09, 0x83, 0x2c, 0x1a, 0x1b, 0x6e, 0x5a, 0xa0,
    0x52, 0x3b, 0xd6, 0xb3, 0x29, 0xe3, 0x2f, 0x84,
    0x53, 0xd1, 0x00, 0xed, 0x20, 0xfc, 0xb1, 0x5b,
    0x6a, 0xcb, 0xbe, 0x39, 0x4a, 0x4c, 0x58, 0xcf,
    0xd0, 0xef, 0xaa, 0xfb, 0x43, 0x4d, 0x33, 0x85,
    0x45, 0xf9, 0x02, 0x7f, 0x50, 0x3c, 0x9f, 0xa8,
    0x51, 0xa3, 0x40, 0x8f, 0x92, 0x9d, 0x38, 0xf5,
    0xbc, 0xb6, 0xda, 0x21, 0x10, 0xff, 0xf3, 0xd2,
    0xcd, 0x0c, 0x13, 0xec, 0x5f, 0x97, 0x44, 0x17,
    0xc4, 0xa7, 0x7e, 0x3d, 0x64, 0x5d, 0x19, 0x73,
    0x60, 0x81, 0x4f, 0xdc, 0x22, 0x2a, 0x90, 0x88,
    0x46, 0xee, 0xb8, 0x14, 0xde, 0x5e, 0x0b, 0xdb,
    0xe0, 0x32, 0x3a, 0x0a, 0x49, 0x06, 0x24, 0x5c,
    0xc2, 0xd3, 0xac, 0x62, 0x91, 0x95, 0xe4, 0x79,
    0xe7, 0xc8, 0x37, 0x6d, 0x8d, 0xd5, 0x4e, 0xa9,
    0x6c, 0x56, 0xf4, 0xea, 0x65, 0x7a, 0xae, 0x08,
    0xba, 0x78, 0x25, 0x2e, 0x1c, 0xa6, 0xb4, 0xc6,
    0xe8, 0xdd, 0x74, 0x1f, 0x4b, 0xbd, 0x8b, 0x8a,
    0x70, 0x3e, 0xb5, 0x66, 0x48, 0x03, 0xf6, 0x0e,
    0x61, 0x35, 0x57, 0xb9, 0x86, 0xc1, 0x1d, 0x9e,
    0xe1, 0xf8, 0x98, 0x11, 0x69, 0xd9, 0x8e, 0x94,
    0x9b, 0x1e, 0x87, 0xe9, 0xce, 0x55, 0x28, 0xdf,
    0x8c, 0xa1, 0x89, 0x0d, 0xbf, 0xe6, 0x42, 0x68,
    0x41, 0x99, 0x2d, 0x0f, 0xb0, 0x54, 0xbb, 0x16
};

const byte inv_sbox[256] = 
{
    0x52, 0x09, 0x6A, 0xD5, 0x30, 0x36, 0xA5, 0x38, 0xBF, 0x40, 0xA3, 0x9E, 0x81, 0xF3, 0xD7, 0xFB,
    0x7C, 0xE3, 0x39, 0x82, 0x9B, 0x2F, 0xFF, 0x87, 0x34, 0x8E, 0x43, 0x44, 0xC4, 0xDE, 0xE9, 0xCB,
    0x54, 0x7B, 0x94, 0x32, 0xA6, 0xC2, 0x23, 0x3D, 0xEE, 0x4C, 0x95, 0x0B, 0x42, 0xFA, 0xC3, 0x4E,
    0x08, 0x2E, 0xA1, 0x66, 0x28, 0xD9, 0x24, 0xB2, 0x76, 0x5B, 0xA2, 0x49, 0x6D, 0x8B, 0xD1, 0x25,
    0x72, 0xF8, 0xF6, 0x64, 0x86, 0x68, 0x98, 0x16, 0xD4, 0xA4, 0x5C, 0xCC, 0x5D, 0x65, 0xB6, 0x92,
    0x6C, 0x70, 0x48, 0x50, 0xFD, 0xED, 0xB9, 0xDA, 0x5E, 0x15, 0x46, 0x57, 0xA7, 0x8D, 0x9D, 0x84,
    0x90, 0xD8, 0xAB, 0x00, 0x8C, 0xBC, 0xD3, 0x0A, 0xF7, 0xE4, 0x58, 0x05, 0xB8, 0xB3, 0x45, 0x06,
    0xD0, 0x2C, 0x1E, 0x8F, 0xCA, 0x3F, 0x0F, 0x02, 0xC1, 0xAF, 0xBD, 0x03, 0x01, 0x13, 0x8A, 0x6B,
    0x3A, 0x91, 0x11, 0x41, 0x4F, 0x67, 0xDC, 0xEA, 0x97, 0xF2, 0xCF, 0xCE, 0xF0, 0xB4, 0xE6, 0x73,
    0x96, 0xAC, 0x74, 0x22, 0xE7, 0xAD, 0x35, 0x85, 0xE2, 0xF9, 0x37, 0xE8, 0x1C, 0x75, 0xDF, 0x6E,
    0x47, 0xF1, 0x1A, 0x71, 0x1D, 0x29, 0xC5, 0x89, 0x6F, 0xB7, 0x62, 0x0E, 0xAA, 0x18, 0xBE, 0x1B,
    0xFC, 0x56, 0x3E, 0x4B, 0xC6, 0xD2, 0x79, 0x20, 0x9A, 0xDB, 0xC0, 0xFE, 0x78, 0xCD, 0x5A, 0xF4,
    0x1F, 0xDD, 0xA8, 0x33, 0x88, 0x07, 0xC7, 0x31, 0xB1, 0x12, 0x10, 0x59, 0x27, 0x80, 0xEC, 0x5F,
    0x60, 0x51, 0x7F, 0xA9, 0x19, 0xB5, 0x4A, 0x0D, 0x2D, 0xE5, 0x7A, 0x9F, 0x93, 0xC9, 0x9C, 0xEF,
    0xA0, 0xE0, 0x3B, 0x4D, 0xAE, 0x2A, 0xF5, 0xB0, 0xC8, 0xEB, 0xBB, 0x3C, 0x83, 0x53, 0x99, 0x61,
    0x17, 0x2B, 0x04, 0x7E, 0xBA, 0x77, 0xD6, 0x26, 0xE1, 0x69, 0x14, 0x63, 0x55, 0x21, 0x0C, 0x7D
};

const byte rcon [] = {
	0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36, 0x6c, 0xd8, 0xab
};

byte state[16];
byte key[16];
byte expKey[176];

void addRoundKey(void)
{
	int i;
	for(i=0; i < 16; i++)
	{
		state[i] ^= key[i];
	}
    #ifdef _DEBUG
        int j;
		printf("\n\tAddRoundKey : ");
		for(j=0; j<16; j++) printf("%02x ",state[j]);
    #endif
}

/* subBytes
 * Table Lookup
 */
void subBytes(void)
{
	int i;
	for(i = 0; i < 16; i++)
	{
		state[i] = sbox[state[i]];
	}
    #ifdef _DEBUG
        int j;
		printf("\n\tSubBytes : ");
		for(j=0; j<16; j++) printf("%02x ",state[j])
    #endif
}

/* shiftRows                Before         After
 * Row 1: No change        0 4  8 12      0  4  8 12    
 * Row 2: Left Shift by 1  1 5  9 13  =>  5  9 13  1    
 * Row 3: Left Shift by 2  2 6 10 14     10 14  2  6   
 * Row 4: Left Shift by 3  3 7 11 15     15 3   7 11  
 */
void shiftRows(void)
{
	byte temp;
	//Row 2
	temp = state[1]; 
	state[1] = state[5]; 
	state[5] = state[9];
    state[9] = state[13]; 
	state[13] = temp;
	//Row 3
	temp = state[10]; 
	state[10] = state[2]; 
	state[2] = temp;
	temp = state[14]; 
	state[14] = state[6]; 
	state[6] = temp;
	//Row 4
	temp = state[3]; 
	state[3] = state[15]; 
	state[15] = state[11]; 
    state[11] = state[7]; 
	state[7] = temp;
    #ifdef _DEBUG
        int j;
		printf("\n\tShiftRows : ");
		for(j=0; j<16; j++) printf("%02x ",state[j]);
    #endif
}

/* MixColumns Shortcut 
 * Vunerable to timing attack, must add nop
 */
byte xtime(byte x)
{
	return (x & 0x80) ? ((x << 1) ^ 0x1b) : (x<<1);
}

/* Mix Columns */
void mixColumns(void)
{
	byte i, a, b, 
		c, d, e;
	
	/* Process a column at a time */
	for(i = 0; i < 16; i+=4)
	{
		a = state[i]; b = state[i+1]; c = state[i+2]; d = state[i+3];
		e = a ^ b ^ c ^ d;
		state[i]   ^= e ^ xtime(a^b);
		state[i+1] ^= e ^ xtime(b^c);
		state[i+2] ^= e ^ xtime(c^d);
		state[i+3] ^= e ^ xtime(d^a);
	}
    #ifdef _DEBUG
        int j;
		printf("\n\tMixColumns : ");
		for(j=0; j<16; j++) printf("%02x ",state[j]);
    #endif
}

// This function produces Nb(Nr+1) round keys. The round keys are used in each round to decrypt the states. 
void KeyExpansion(void)
{
    byte i, j, k;
    byte temp[4]; // Used for the column/row operations
  
    // The first round key is the key itself.
    for(i = 0; i < 16; ++i)
    {
        expKey[i] = key[i];
    }
    #ifdef _DEBUG
		printf("\n\tKeyExpansion (round 0): ");
		for(j=0; j<16; j++) printf("%02x ",expKey[j]);
    #endif

    // All other round keys are found from the previous round keys.
    for(i = 1; i < 11; i++)
    {
        for(j = 0; j < 4; ++j)
        {
            temp[j]=expKey[((i<<4)-4) + j];
        }

        // This function rotates the 4 bytes in a word to the left once.
        // [a0,a1,a2,a3] becomes [a1,a2,a3,a0]
        // Function RotWord()
        k = temp[0];
        temp[0] = temp[1];
        temp[1] = temp[2];
        temp[2] = temp[3];
        temp[3] = k;

        // SubWord() is a function that takes a four-byte input word and 
        // applies the S-box to each of the four bytes to produce an output word.
        // Function Subword()
        temp[0] = sbox[temp[0]];
        temp[1] = sbox[temp[1]];
        temp[2] = sbox[temp[2]];
        temp[3] = sbox[temp[3]];

        // xor temp with rcon
        temp[0] =  temp[0] ^ rcon[i-1];

        for(j=0; j < 16; j++){
            if (j<4) {
                expKey[(i<<4)+j] = expKey[(i<<4)-16+j] ^ temp[j];
            } else {
                expKey[(i<<4)+j] = expKey[(i<<4)-16+j] ^ expKey[(i<<4)+j-4];
            }
        }
        #ifdef _DEBUG
            printf("\n\tKeyExpansion (round %d): ", i);
            for(j=0; j<16; j++) printf("%02x ",expKey[(i<<4)+j]);
        #endif
    }
}

/* Compute a round of the key
 * 0 4  8 12
 * 1 5  9 13
 * 2 6 10 14
 * 3 7 11 15
 */
void computeKey(byte rcon)
{
	byte buf0, buf1, buf2, buf3;
	buf0 = sbox[ key[13] ];
	buf1 = sbox[ key[14] ];
	buf2 = sbox[ key[15] ];
	buf3 = sbox[ key[12] ];

	key[0] ^= buf0 ^ rcon;
	key[1] ^= buf1;
	key[2] ^= buf2;
	key[3] ^= buf3;

	key[4] ^= key[0];
	key[5] ^= key[1];
	key[6] ^= key[2];
	key[7] ^= key[3];

	key[8]  ^= key[4];
	key[9]  ^= key[5];
	key[10] ^= key[6];
	key[11] ^= key[7];

	key[12] ^= key[8];
	key[13] ^= key[9];
	key[14] ^= key[10];
	key[15] ^= key[11];
    #ifdef _DEBUG
        int j;
        printf("\n\tComputeKey : ");
        for(j=0; j<16; j++) printf("%02x ",key[j]);
    #endif
}

void InitState()
{
	state[0]=0x00;
	state[1]=0x00;
	state[2]=0x00;
	state[3]=0x00;
	state[4]=0x00;
	state[5]=0x00;
	state[6]=0x00;
	state[7]=0x00;
	state[8]=0x00;
	state[9]=0x00;
	state[10]=0x00;
	state[11]=0x00;
	state[12]=0x00;
	state[13]=0x00;
	state[14]=0x00;
	state[15]=0x00;
    #ifdef _DEBUG
        int j;
        printf("\n\tInitState : ");
        for(j=0; j<16; j++) printf("%02x ",state[j]);
    #endif
}

/**
  * @brief  Initialisation de la clé AES
  * @retval None
  */
void AES_InitKey(const byte Key[16])
{
	int i;
	for (i=0; i<16; i++){
		key[i]=Key[i];
	}
    #ifdef _DEBUG
        int j;
        printf("\n\tInitKey : ");
        for(j=0; j<16; j++) printf("%02x ",key[j]);
    #endif
}

/**
  * @brief  Chiffrement AES
  * @retval None
  */

// without storing intermediate state
void AES_Run(void)
{
	int i;
	addRoundKey();
	for(i = 0; i < 9; i++)
	{
		subBytes();		
		shiftRows();
		mixColumns();
		computeKey(rcon[i]);
		addRoundKey();
	}
	subBytes();
	shiftRows();
	computeKey(rcon[i]);
	addRoundKey();
}

/* invshiftRows              Before         After
 * Row 1: No change         0 4  8 12      0  4  8 12    
 * Row 2: Right Shift by 1  1 5  9 13  =>  13 1  5  9    
 * Row 3: Right Shift by 2  2 6 10 14      10 14  2  6   
 * Row 4: Right Shift by 3  3 7 11 15      7  11 15  3   
 */
void invshiftRows(void)
{
	byte temp;
    //Row 2
	temp = state[13]; 
	state[13] = state[9]; 
	state[9] = state[5];
    state[5] = state[1]; 
	state[1] = temp;
	//Row 3
	temp = state[10]; 
	state[10] = state[2]; 
	state[2] = temp;
	temp = state[14]; 
	state[14] = state[6]; 
	state[6] = temp;
	//Row 4
	temp = state[3]; 
	state[3] = state[7]; 
	state[7] = state[11]; 
    state[11] = state[15]; 
	state[15] = temp;
    #ifdef _DEBUG
        int j;
        printf("\n\tInvShiftRows : ");
        for(j=0; j<16; j++) printf("%02x ",state[j]);
    #endif
}
 
/* subBytes
 * Table Lookup
 */
void invsubBytes(void)
{
	int i;
	for(i = 0; i < 16; i++)
	{
		state[i] = inv_sbox[state[i]];
	}
    #ifdef _DEBUG
        int j;
        printf("\n\tInvSubBytes : ");
        for(j=0; j<16; j++) printf("%02x ",state[j]);
    #endif
}

// Multiply is used to multiply numbers in the field GF(2^8)
uint8_t Multiply(byte x, byte y)
{
  return (((y & 1) * x) ^
       (((y>>1) & 1) * xtime(x)) ^
       (((y>>2) & 1) * xtime(xtime(x))) ^
       (((y>>3) & 1) * xtime(xtime(xtime(x)))) ^
       (((y>>4) & 1) * xtime(xtime(xtime(xtime(x))))));
}

// invMixColumns function mixes the columns of the state matrix.
// The method used to multiply may be difficult to understand for the inexperienced.
// Please use the references to gain more information.
void invmixColumns(void)
{
  uint8_t i;
  byte a,b,c,d;
  for(i=0;i<4;++i)
  { 
    a = state[(i<<2) + 0];
    b = state[(i<<2) + 1];
    c = state[(i<<2) + 2];
    d = state[(i<<2) + 3];

    state[(i<<2) + 0] = Multiply(a, 0x0e) ^ Multiply(b, 0x0b) ^ Multiply(c, 0x0d) ^ Multiply(d, 0x09);
    state[(i<<2) + 1] = Multiply(a, 0x09) ^ Multiply(b, 0x0e) ^ Multiply(c, 0x0b) ^ Multiply(d, 0x0d);
    state[(i<<2) + 2] = Multiply(a, 0x0d) ^ Multiply(b, 0x09) ^ Multiply(c, 0x0e) ^ Multiply(d, 0x0b);
    state[(i<<2) + 3] = Multiply(a, 0x0b) ^ Multiply(b, 0x0d) ^ Multiply(c, 0x09) ^ Multiply(d, 0x0e);
  }
    #ifdef _DEBUG
        int j;
        printf("\n\tInvMixColumns : ");
        for(j=0; j<16; j++) printf("%02x ",state[j]);
    #endif
}

void AES_Decipher(void)
{
  uint8_t i = 10,j;

  KeyExpansion();
  // Add the First round key to the state before starting the rounds.
  for(j = 0; j < 16; j++){
    key[j] = expKey[(i<<4) + j];
  }
  addRoundKey(); 

  // There will be Nr rounds.
  // The first Nr-1 rounds are identical.
  // These Nr-1 rounds are executed in the loop below.
  for(i = 9 ; i > 0 ; i--)
  {
    invshiftRows();
    invsubBytes();
    for(j = 0; j < 16; j++){
        key[j] = expKey[(i<<4) + j];
    }
    addRoundKey();
    invmixColumns();
  }
  
  // The last round is given below.
  // The MixColumns function is not here in the last round.
  invshiftRows();
  invsubBytes();
  for(j = 0; j < 16; j++){
    key[j] = expKey[j];
  }
  addRoundKey();
}

/**
  * @brief  Réception du texte clair 
  * @retval None
  */
void AES_SetPlainText(const byte Text[16])
{
	int i;
	for(i=0;i<16;i++)
	{	
		state[i] = Text[i];
	}
    #ifdef _DEBUG
        int j;
        printf("\n\tSetPlaintext : ");
        for(j=0; j<16; j++) printf("%02x ",state[j]);
    #endif
}

/**
  * @brief  Renvoi du chiffré
  * @retval None
  */
void AES_GetCipherText(byte *Ciphertext)
{	
	int i;
	for(i=0;i<16;i++)
	{	
		Ciphertext[i] = state[i];
	}
    #ifdef _DEBUG
        int j;
        printf("\n\tGetCiphertext : ");
        for(j=0; j<16; j++) printf("%02x ",Ciphertext[j]);
    #endif
}

/**
  * @brief  Réception du texte clair 
  * @retval None
  */
void AES_GetPlainText(byte *Text)
{
	int i;
	for(i=0;i<16;i++)
	{	
		Text[i] = state[i];
	}
    #ifdef _DEBUG
        int j;
        printf("\n\tGetplaintext : ");
        for(j=0; j<16; j++) printf("%02x ",Text[j]);
    #endif
}

/**
  * @brief  Definition du chiffré
  * @retval None
  */
void AES_SetCipherText(const byte Ciphertext[16])
{	
	int i;
	for(i=0;i<16;i++)
	{	
		state[i] = Ciphertext[i];
	}
    #ifdef _DEBUG
        int j;
        printf("\n\tSetCiphertext : ");
        for(j=0; j<16; j++) printf("%02x ",state[j]);
    #endif
}

// store intermediate state for Nr round
void AES_RunandStoreState(unsigned Nr, State *round)
{
	assert(round);
	int i,j;
	round[0].start = (byte *) malloc(16*sizeof(byte));
	round[0].sbox = 0;
	round[0].shiftrow = 0;
	round[0].mixcolumn = 0;
	round[0].roundkey = (byte *) malloc(16*sizeof(byte));
	for (j=0; j<16; j++) {
		round[0].start[j] = state[j];
		round[0].roundkey[j] = key[j];
	}
	addRoundKey();
	i = 1;
	do
	{
		round[i].start =  (byte *) malloc(16*sizeof(byte));
		for (j=0; j<16; j++) {
			round[i].start[j] = state[j];
		}
		subBytes();		
		round[i].sbox =  (byte *) malloc(16*sizeof(byte));
		for (j=0; j<16; j++) {
			round[i].sbox[j] = state[j];
		}
		shiftRows();
		round[i].shiftrow =  (byte *) malloc(16*sizeof(byte));
		for (j=0; j<16; j++) {
			round[i].shiftrow[j] = state[j];
		}
		mixColumns();
		computeKey(rcon[i-1]);
		round[i].mixcolumn =  (byte *) malloc(16*sizeof(byte));
		round[i].roundkey =  (byte *) malloc(16*sizeof(byte));
		for (j=0; j<16; j++) {
			round[i].mixcolumn[j] = state[j];
			round[i].roundkey[j] = key[j];
		}
		addRoundKey();
		i++;
	} while(i<Nr);
	if (Nr == 10) {
		round[i].start =  (byte *) malloc(16*sizeof(byte));
		for (j=0; j<16; j++) {
			round[i].start[j] = state[j];
		}
		subBytes();		
		round[i].sbox =  (byte *) malloc(16*sizeof(byte));
		for (j=0; j<16; j++) {
			round[i].sbox[j] = state[j];
		}
		shiftRows();
		round[i].shiftrow =  (byte *) malloc(16*sizeof(byte));
		for (j=0; j<16; j++) {
			round[i].shiftrow[j] = state[j];
		}
		computeKey(rcon[i-1]);
		round[i].roundkey = (byte *) malloc(16*sizeof(byte));
		for (j=0; j<16; j++) {
			round[i].mixcolumn = 0;
			round[i].roundkey[j] = key[j];
		}
		addRoundKey();
	}
}

