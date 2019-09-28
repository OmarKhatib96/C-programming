
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include "hachage.h"
#include "StructureDonnees.h"
#include "AffichagesCollisions.h"
#include "InsertionClef.h"



int  nbr_mots(void){

FILE*fichier=NULL;

fichier=fopen("dictionnaire.txt","r");
char nom[40];

int i=0;

while(!feof(fichier)){
	fscanf(fichier,"%s\n",nom);
  	i++;
}
return i;

}
	

int Codage (char * mot,int taille  ){
	int code=0;
	int tailleMot=strlen(mot);
	for (int i=0;i<tailleMot;i++){
		code=code+mot[i]*pow(2,i);
	}

	return code;}


	
Liste * CreationTable(int taille){

    Liste * table=(Liste *)malloc(sizeof(Liste)*taille);
	
	return table;
}

Liste * lectureFichier(int taille){

FILE*fichier=NULL;

fichier=fopen("dictionnaire.txt","r");
char Nom[40];
int clef;
int sousClef=1;
int i=1;

Liste *table=CreationTable(taille);
while(!feof(fichier)){
	fscanf(fichier,"%s\n",Nom);

	clef=Codage(Nom,taille)%(taille);

	 table[clef]=initialisation();
	 insertion(table, sousClef,clef);

	strcpy(table[clef].premier->mot,Nom);

		++i;


} 
printf("le nombre de mots se trouvant seuls dans les listes chaînées est %d\n",i-1);
if(i-1==taille)
	printf("Il n'y a pas eu de collision!\n");
else
	printf("IL y a eu au moins une collision\n");

fclose(fichier);
return table;
}

bool ChercherMot(Liste *tab,char mot[40],int taille){
int clef=Codage(mot,taille)%(taille);

return true;
}

int main(){

int taille=nbr_mots();

Liste *tab=lectureFichier(taille);
char chaine[40]="soulevee";
ChercherMot(tab,chaine,taille);
int n=Codage(chaine,taille)%(taille);

AfficherListe(tab[n]);
return 1;
}

	

