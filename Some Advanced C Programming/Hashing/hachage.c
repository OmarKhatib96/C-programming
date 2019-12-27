
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
		printf("%s\n",nom);
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

	return code%taille;
}


	


void lectureFichier(int taille,Liste *tab[]){

	FILE*fichier=NULL;

	fichier=fopen("dictionnaire.txt","r");
	char Nom[40];
	int clef;
	int sousClef=1;
	int i=1;


	while(!feof(fichier)){
		fscanf(fichier,"%s\n",Nom);

		clef=Codage(Nom,taille);


		 Clef*cle=insertion(tab[clef], clef,Nom);


			


	} 
	
	fclose(fichier);

}

bool ChercherMot(Liste *tab[],char mot[40],int taille){
	int clef=Codage(mot,taille);
	Clef *actuel=tab[clef]->premier;
	while(actuel!=NULL){
		if (!strcmp(mot,actuel->mot)){
			printf("le mot \"%s\" figure sur la table de hachage! \n ",actuel->mot);
			return true;
		}
		else
			actuel=actuel->suivant;
	}


		printf(" Désolé,le mot recherché ne figure pas sur la table de hachage! \n");
		return false;
}

int main(){

	int taille=nbr_mots();
	Liste * table[taille];
	for(int j=0;j<taille;j++)
	table[j]=initialisation();
	lectureFichier(taille,table);
	char mot[40];
	printf("Entrez le mot à chercher \n");
	scanf("%s",mot);
	ChercherMot(table,mot,taille);
	int n=Codage(mot,taille);
	AfficherListe(table[n]);
	return 1;
}

	

