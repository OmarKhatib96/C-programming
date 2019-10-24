#include <stdlib.h>

#include <stdio.h>


#include "constantes.h"


 
#include "ShiftRows.h"


void ShiftRows(unsigned char Mat[NBR][NBR]){

unsigned char Remplacement[4][4];
for(int i=0;i<NBR;i++){

	for(int j=0;j<NBR;j++){

		Remplacement[i][j]=Mat[i][j];}}

for(int i=0;i<NBR;i++){
	for(int j=0;j<NBR;j++){

			
		Mat[i][j]=Remplacement[i][(j+i)%NBR];

}

}
}

void AfficherMatrice(unsigned char MAT[NBR][NBR]){
for(int i=0;i<NBR;i++){
	for(int j=0;j<NBR;j++)
		printf("%d ",MAT[i][j]);
		printf("\n");
	} }





















