#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define TAILLE 3




int pgcdR( int a,int b);
int pgcdI(int a, int  b);
int *TriFusion(int * tab, int n);
int * Separation1(int *t, int n);
int * Separation2(int *t, int n);
int *fusion(int *tab1,int *tab2,int n1,int n2);
int fibonacciR(int n);
int fibonacciI(int n);

//Exercice1:;
int pgcdR( int a,int b){

	if(b==0 && a!=0){
		return a;
}
	if(a==0 && b!=0){
		return b;
}
	if(a<b ){
		return 1;
}
	if(a==0||a==b){
		return b;

	}
	if (a>b && b!=0){

		pgcdR(b,a%b);
	}

};





int pgcdI(int a, int  b){
int reste=b;


	if(b==0 && a!=0){
		return a;
}
	if(a==0 && b!=0){
		return b;
}
	if(a<b ){
		return 1;
}
	if(a==0||a==b){
		return b;
}
while(reste!=0){
	reste=a%b;
	a=b;
	b=reste;
}
return a;
}




//Exercice2;


int * Separation1(int *t, int n){
int milieu=n/2;
int i;
int *t1=(int *)malloc(sizeof(int)*n/2);


for (i=0;i<n/2;i++){
	t1[i]=t[i];
}
return t1;
}

int * Separation2(int *t, int n){
int milieu=n/2;
int i;
int *t2=(int *)malloc(sizeof(int)*n/2);


for (i=milieu;i<n;i++){
	t2[i-milieu]=t[i];
}
return t2;
}
int *fusion(int *tab1,int *tab2,int n1,int n2){
int i;
int j;
int echange;
int *tab=(int *)malloc(sizeof(int)*(n1+n2));


for (i=0;i<n1;i++){
	tab[i]=tab1[i];}




	/*for (j=0;j<n1-1;j++){
		if (tab[j]>=tab[j+1]){
			echange=tab[j+1];
			tab[j+1]=tab[j];
			tab[j]=echange;
}


}*/

for(i=0;i<n2;i++){
	tab[i+n1]=tab2[i];
}
int k;
int m;
for( k=0;k<n1+n1;k++){

	for(m=0;m<n1+n2;m++){
		if(tab[k]>tab[m]){
			int echange1=tab[k];
			tab[k]=tab[m];
			tab[m]=echange1;

			}

}}



/*for k de g à d do
9: if R[i] < R[j] then
10: T[k] = R[i], i = i + 1
11: else
12: T[k] = R[j], j = j − 1
13: end if
14: end for
*/





/*for (j=n1;j<n2+n1-1;j++){
		if (tab[j]>=tab[j+1]){
			echange=tab[j+1];
			tab[j+1]=tab[j];
			tab[j]=echange;
}

}
*/

return tab;
}

int *TriFusion(int * tab, int n){

	if (n==1){
		return tab;
}
	if (n==2){
		if (tab[1]<tab[0]){

			int a=tab[1];
			tab[1]=tab[0];
			tab[0]=a;
			return tab;

}
		if (tab[0]<tab[1]){


			return tab;

}}
	else{


	int *t1=TriFusion(Separation1(tab,n),n/2);
	int *t2=TriFusion(Separation2(tab,n),n-n/2);


	int *t3=fusion(t1,t2,n/2,n-n/2);

	return t3;


}

}




//Exercice 3:
int fibonacciR(int n){
int S=0;

	if (n==0){
		return 0;
}
	if (n==1){
		return 1;
}
	else{
		S=S+fibonacciR(n-1)+fibonacciR(n-2);

		return S;
}


}
int fibonacciI(int n){
	int S1=0;
	int S2=1;
	int S=0;
	int complexiteI=0;

	if (n==0){
		return 0;
}
	if (n==1){
		return 1;
}
	else{
		while(n>1){
		//un = un−1 + un−2 pour n ≥ 2, U4=(U3+U2)=((U2+U1)+(U1+U0));

			S=S1+S2;
			S1=S2;
			S2=S;
			n--;
			complexiteI+=4;

}}
printf("La complexite de cet algorithme est de %d \n",complexiteI);
return S;
}


int main(){

printf("%d\n",pgcdR(151562,52));
printf("%d\n",pgcdI(151563,52));
int t[16]={3, 2, 6, 7, 20, 18, 9, 8, 1, 5,105,54,37,38,39,1051};
int *TableauTrie;
TableauTrie=TriFusion(t,16);
int j;
for (j=0;j<16;j++){
	printf("%d ",TableauTrie[j]);
}
printf("\n");

printf("%d \n",fibonacciR(40));
printf("%d\n",fibonacciI(40));
}






