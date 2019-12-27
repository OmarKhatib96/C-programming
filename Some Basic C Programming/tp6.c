#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
int nbrVoyelles(char chaine[20]);
int occurence(char chaine[],int c);
int remplir(char   c,char  caractere);
int conjug(void);

bool palindrome(char chaine[30]);
int  chaineCaracteres(void){
char  car1[30];
char car2[30];
scanf("%s",car1);
scanf("%s",car2);
printf("Le nombre de caracteres de car1 est : %lu et celui de car2 est : %lu \n",strlen(car1),strlen(car2));
strcat(car1,   car2);
printf("La chaine concatenee est egale a : %s \n ",car1);

int min;
if (strlen(car1)<=strlen(car2) )
    min=strlen(car1);
else
    min=strlen(car2);
if (strcmp(car1,car2)==0){

    printf("Elles sont identiques");
}
else{
    int i;
    for (i=0;i<min+1;i++)
    {
        if (car1[i]<car2[i]){

            printf("car1 est classe avant alphabetiquement");
            return 1;}
        if(car1[i]>car2[i]){
            printf("car2 est classe avant alphabetiquement");
            return 2;}
    }
}}
int main(){

//chaineCaracteres();
//palindrome("callac");
//nbrVoyelles("omarou");
//occurence("aaaaa",'a');

//remplir('a','b');
conjug();


return 1;


}
/**********exercice2**********/
bool palindrome(char chaine[30]){
int taille=strlen(chaine);
int i;
char inverse[30];
for (i=0;i<taille+1;i++){
    inverse[i]=chaine[taille-i-1];
}
if (strcmp(inverse,chaine)==0){
            printf("Oui c'est un palindrome\n");

    return true;}
else{
                printf("Non ce n'est pas  un palindrome\n");

    return false;}


}
/******exercice3********/

int nbrVoyelles(char chaine[20]){
char listeVoyelles[7]="aeiouy";
int nbr_Voyelles=0;
int i=0;
int j=0;
/*for (j=0;j<strlen(listeVoyelles);j++){
    if(strchr(chaine, listeVoyelles[j])!=NULL)

        i++;

}*/
for (j=0;j<strlen(listeVoyelles);j++){

    for(i=0;i<strlen(chaine);i++){

        if(listeVoyelles[j]==chaine[i]){

            nbr_Voyelles++;


        }

    }

}

printf("le nombre de voyelle dans cette chaine de caracteres est :%d",nbr_Voyelles);
return i;




}

int occurence(char chaine[],int c){
int nbr_occurence=0;
int i;
for (i=0;i<strlen(chaine);i++){
    if(chaine[i]==c)
    nbr_occurence++;
}

printf("Le caractere %c est present dans la chaine %d fois\n",c,nbr_occurence);
return nbr_occurence;



}

int remplir(char c,char caractere){
char chaine[]="omar";
int i;
for (i=0;i<strlen(chaine);i++){
    if(chaine[i]==c){

        chaine[i]=caractere;
    }
    }


printf("%s",chaine);
return 1;
}

/**********exercice 4**********/

int conjug(void){
char verbe[15];
scanf("%s",verbe);
int taille=strlen(verbe);

int i;
char radical[taille-3];

if(verbe[taille-1]=='r'&& verbe[taille-2]=='e')
{
    for (i=0;i<taille-2;i++){
        radical[i]=verbe[i];
    }



printf("\n\nJe %se\n",radical);

   
printf("\n\nTu %ses\n",radical);
printf("\n\nIl/Elle %se\n",radical);

printf("\n\nNous %sons\n",radical);
printf("\n\nVous %sez\n",radical);
printf("\n\nIls/Elles %sent\n",radical);

}


return 1;




}

