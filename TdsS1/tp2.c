#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int const NB_MAX=100;





int *allocation(int n);
void affiche(int *t,int n){
int i;
for(i=0;i<n;i++){
    
printf("t[%d]=%d\n",i,t[i]);

}


}

int * copie(int *t,int n){
int i;

int *s=(int *)malloc(NB_MAX* sizeof(int));

for(i=0;i<n;i++){
    s[i]=t[i];





}

return s;
}

int val_max(int *t,int n){
int max;
max=t[0];
int i;
for (i=0;i<n;i++){
    if (max<t[i]){
        max=t[i];
    }
}

return max;

}
int indice(int *t,int n){
int max;

max=t[0];
int i;
int indice1;

for (i=0;i<n;i++){
    if (max<t[i]){
        max=t[i];
	indice1=i;
    }
   
}

return indice1;

}





int * trie(int *t,int n){

int i=n;

int a;
int echange;

for (i=n;i>0;i--){

a=indice(t,i);
echange=t[i-1];
t[i-1]=val_max(t,i);
t[a]=echange;

}

return t;



}

int inserer(int *tab,int nb,int i,int m){
int *t1=copie(tab,nb);
int j;
t1[i]=m;
    for(j=i+1;j<nb;j++){
        t1[j]=t1[i++];


    }

return 0;

}

int sommeTableau(int *t,int n){
	int i;
	int S=0;
	for (i=0;i<n;i++){
		S=S+t[i];
}
return S;
}







int nbr_parfait(int nbr){
int S;
int tab_diviseur[nbr+1];
int i;
for (i=1;i<nbr+1;i++){
   if((nbr%i)==0){
    tab_diviseur[i-1]=i;

   }
   else{
   tab_diviseur[i-1]=0;
   }
}
tab_diviseur[nbr-1]=0;
affiche(tab_diviseur,nbr);
if (nbr==sommeTableau(tab_diviseur,nbr))

	printf("Le nombre %d est parfait\n",nbr);

else
	printf("Le nombre %d n'est pas parfait\n",nbr);

return 0;







}

int *allocation(int n){

int *t=(int*)malloc(n*sizeof(int));
return t;
}



int main(){

int t[10]={10,88,3,7,9,14,4,8,10,18};
//affiche(t,10);
//val_max(t,3);
//copie(t,10);
//indice(t,10);
//trie(t,10);
//affiche(trie(t,10),10);
//inserer(t,10,2,5);
nbr_parfait(6);
return 0;




}





