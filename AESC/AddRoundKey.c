#include <stdlib.h>
#include <stdio.h>
#include "AddRoundKey.h"

#include "constantes.h"

void AddRoundKey(unsigned char state[NBR][NBR], unsigned char key )
{for (int i=0; i<NBR; i++){
	for (int j=0; j<NBR; j++)
	state[i][j]=state[i][j]^key;}
}

void Aff(unsigned char state[NBR][NBR])
{for (int i=0; i<NBR; i++){
	for (int j=0; j<NBR; j++){
		printf("%d ",state[i][j]);
		}printf("\n");}
}


