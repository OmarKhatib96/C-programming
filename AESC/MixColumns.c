
#include<stdio.h>
#include<stdlib.h>
#include "MixColumns.h"

#include "constantes.h"
unsigned char state [4][4];//ligne colonne

void MixColumns(unsigned char state [4][4]){
	unsigned char temp[4][4];
	char a,b,c,d, e, f, g , h, i2, j, k, l ,m ,n ,o, p;
	char temp1, temp2, temp3, temp4;
	for (int i =0; i<4 ; i++){
		a=2, b=3 ,c=1 ,d=1;
		e=1, f=2, g=3, h=1;
		i2=1, j=1, k=2, l=3;
		m=3, n=1, o=1, p=2;
		temp1 = a^state[0][i]+b^state[1][i]+c^state[2][i]+d^state[3][i];		
		temp2 =  e^state[0][i]+f^state[1][i]+g^state[2][i]+h^state[3][i];				
		temp3 =  i2^state[0][i]+j^state[1][i]+k^state[2][i]+l^state[3][i];
		temp4 = m^state[0][i]+n^state[1][i]+o^state[2][i]+p^state[3][i];
		state[0][i] = temp1;
		state[1][i] = temp2;
		state[2][i] = temp3;
		state[3][i] = temp4;	
	}
}



