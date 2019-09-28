#include <stdio.h>
#include <stdlib.h>
#include <math.h>
const int g=9.81;
int somme(void){


int S;
int i;
int N;
scanf("%d",&N);
S=0;
for (i=0;i<N+1;i++){
S=S+i;

}
printf("%d \n",S);
if(S==(N*(N+1))/2){
printf("C'est bon \n");
}
else{
    printf("C'est pas bon \n");
}

    return S;

}

int distance(void){
int t;
float d;
for (t=0;t<11;t++){
d=0.5*g*(t*t);
printf("La distance parcourue pendant %d secondes est égale à: %f\n",t,d);


}
return 1;



}

void chaine(void){
char c=0;

scanf("%c",&c);
printf("\n %d",c);






}

void inverse(void){
int d;

scanf("%d",&d);

printf("%c",d);



}
int conversion(){
float montant;
float f1;

scanf("%f",&montant);
int f=floor(montant);
float o=montant-f;
f1=f;
int n;
n=0;

while (o!=0){

montant = montant*10;

f=floor(montant);

o=montant-f;
n=n+1;
}
printf(" \n Le montant est de %f centimes \n ",montant);
float centimes;
centimes=montant-f1*(pow(10,n));
printf("Le montant saisi est de %.0f euros et %.0f centimes",f1,centimes);
 


return montant;
}


int main(){
somme();
distance();
chaine();
inverse();
conversion();
return 0;

}

//exercice 4:



