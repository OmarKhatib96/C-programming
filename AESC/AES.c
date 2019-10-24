#include <stdio.h>
#include <stdlib.h>
#include "AddRoundKey.h"
#include "SubBytes.h"
#include "MixColumns.h"
#include "ShiftRows.h"
#include "constantes.h"

void Cipher(Byte in[4][NBR],Byte out[4][NBR],Word w[NBR][NR+1]){
Byte state[NBR][NBR];



for(int i=0;i<NBR;i++){
	for(int j=0;j<NBR;j++){
		
		in[i][j]=state[i][j];

	}}



AddRoundKey(state,w[0][NBR-1]);



for(int round=1;round<NBR-1;round++){
	
	SubBytes(state);
	ShiftRows(state);
	MixColumns( state);
	AddRoundKey(state,w[round*NBR][(round+1)*NBR-1]);

}

SubBytes(state);
ShiftRows(state);

AddRoundKey(state,w[NR*NBR][(NR+1)*(NBR-1)]);



for(int i=0;i<NBR;i++){
	for(int j=0;j<NBR;j++){
		
		out[i][j]=state[i][j];

	}}


}


int main(){

Byte in[NBR][NBR]={{1,2,5,7},{8,5,6,7},{45,5,1,2},{10,8,9,3}};
Byte out[NBR][NBR]={{1,2,4,4},{7,5,5,7},{4,5,10,23},{1,81,0,2}};
Word w[NBR][NR+1]={{2,3,4,5,6,7,8,9,10,11},{2,31,14,3,20,75,80,90,5,11},{2,3,44,50,65,71,80,9,14,11},{21,3,45,51,60,74,83,97,1,11}};
 Cipher( in, out,w );
  //Aff(in);
 Aff(in);
}



