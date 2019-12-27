#include <stdlib.h> 
#include <stdio.h>
#include <stdbool.h>


int j=1;

int fonction1(int n);
int fonction2(int n);
int fonction3(int n);
int fonction4(int n);
/*Pour chacune des questions ci-dessous on indiquera la complexité de l’algorithme.

Soit la fonction : f (n) = 3n2 + n + 1 si n ≥ 1, 0 sinon.

a)	Écrire une fonction f qui prend en paramètre un entier n et calcule f (n).

b)	Écrire une fonction qui prend en paramètre un entier n et calcule la somme :
Sn = f (n) + f (n − 1) + f (n − 2) + f (n − 3)  + · · ·
On arrêtera la somme lorsque la valeur f calculée est nulle.

c)	Écrire une fonction qui prend en paramètre un entier n et calcule la somme :
Tn = f (n) + f (n/22) + f (n/32) + f (n/42)  + · · ·
Les divisions sont des divisions euclidiennes. On arrêtera la somme lorsque la valeur f calculée est nulle.

d)	Écrire une fonction qui prend en paramètre un entier n et calcule la somme :
Un = f (n) + f (n/2) + f (n/4)  + f (n/8) + · · ·
Les divisions sont des divisions euclidiennes. On arrêtera la somme lorsque la valeur f calculée est nulle.

*/
int C1=0;
int C2=0;
int C3=0;
int C4=0;
int fonction1(int n){

	if (n==0){

		return 0;
}
else{
	C1=C1+5;
	printf("La complexité de cette fonction est :%d\n",C1);
	return 3*n*n+n+1;}
	
}


int fonction2(int n){
int S2=0;
if (n==0){
	
	return 0;}
else{
		C2=C1+C2;
			printf("LA complexité de cette fonction est :%d\n",C2);
		S2=fonction1(n)+fonction2(n-1);


}
return S2;
}

int fonction3(int n){



int S3=0;
if((n/j*j)==0){
	

	return 0;
}

else{
	

	
	C3=C3+1+C1;
				printf("LA complexité de cette fonction est :%d\n",C3);
	S3=S3+fonction1(n/((j)*(j)));
	j++;
}
return S3;
fonction3(n);



}
int fonction4(int n){
	int S4=0;
if(n==0){
	return 0;}
else{
	C4=C4+1+C1;
	S4=S4+fonction1(n/j);
	j++;
}
return S4;
printf("LA complexité de cette fonction est :%d\n",C4);
fonction4(n);
}
//Exercice 2:
int i=2;
bool premier(int n){

	if (n==0){
		return false;
	}
	if (n==1){
		return true;
	}
		if (i<n){
			if (n%i==0 ){
			
				return  false;
			
		}	
			else{
				i++;	
				premier(n);

	
			
	
}

}
if(i==n){
	return true;

}
else{
	return false;
}

}

void premier2(int n){

		
if(premier(n)==1){
				printf("oui \n");}
else{
	printf("non \n");
	}		
}

int main(){
	//printf("S1=%d\n ",fonction1(3));
	//printf("S2=%d\n  ",fonction2(23));
	
	//printf("S3=%d\n ",fonction3(20));
	//printf("S4=%d\n  ",fonction4(21));
//1709	1721	1723	1733	1741	1747	1753	1759	1777	1783	1787	1789	


premier2(9859	);
return 0;
}








