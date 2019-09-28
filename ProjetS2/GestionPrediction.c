




#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#include "GestionPrediction.h"

int ModificationMot(const char* NomFichier,char nomAmodifier[30],char MotRemp[30]){//permet de modifier un mot dans le dictionnaire de prédiction
	char nom[30];
	char date[128];
	char heure[128];
	bool trouve=false;

	Liste *listeAmodifier=initialisation2();
	
	FILE*fichier=fopen(NomFichier,"r");
	if(fichier==NULL){
		printf("Erreur d'ouverture du fichier!\n");
		return 0;}

	else{

		while(fscanf(fichier,"%s %s %s\n",nom,date,heure)==3)

				insertion(listeAmodifier,nom,date,heure);

	
	}


fclose(fichier);
		Mot*actuel=listeAmodifier->premier;
	FILE*fichier2=fopen(NomFichier,"w");
	if(fichier2==NULL)
		printf("Erreur d'ouverture du fichier!\n");
	
	else{
		while(actuel->suivant!=NULL){
				//if(actuel->nom!=NULL)
				if(strcmp(actuel->nom,nomAmodifier)!=0)

					fprintf(fichier2,"%s %s %s \n",actuel->nom,actuel->date,actuel->heure);
				
				else if (strcmp(nomAmodifier,actuel->nom)==0){
					fprintf(fichier2,"%s %s %s\n",MotRemp,actuel->date,actuel->heure);
						trouve=true;}
			actuel=actuel->suivant;


}//fin while

}


	fclose(fichier2);
if(trouve==true)

	printf("\n\"%s\" a été remplacé !\n\n",nomAmodifier);
else
	printf("\n\"%s\" n'a pas été trouvé dans le dictionnaire de prédiction!\n\n",nomAmodifier);


free(listeAmodifier);



return 1;
}
		



int Suppression(const char* NomFichier,char nomAsupprimer[30]){//permet de supprimer un mot du dictionnaire de prédiction
	char nom[30];
	char date[128];
	char heure[128];
	bool trouve=false;
	Liste *listeAsupprimer=initialisation2();
	
	FILE*fichier=fopen(NomFichier,"r");
	if(fichier==NULL){
		printf("Erreur d'ouverture du fichier!\n");
		return 0;}

	else{

		while(fscanf(fichier,"%s %s %s\n",nom,date,heure)==3)
				insertion(listeAsupprimer,nom,date,heure);

	
	}


fclose(fichier);
		Mot*actuel=listeAsupprimer->premier;
	FILE*fichier2=fopen(NomFichier,"w");
	if(fichier2==NULL)
		printf("Erreur d'ouverture du fichier!\n");
	
	else{
		while(actuel->suivant!=NULL){
				//if(actuel->nom!=NULL)
				if(strcmp(actuel->nom,nomAsupprimer)!=0)

					fprintf(fichier2,"%s %s %s \n",actuel->nom,actuel->date,actuel->heure);
				 if (strcmp(actuel->nom,nomAsupprimer)==0)
					trouve=true;

			actuel=actuel->suivant;}//fin while

}


	fclose(fichier2);
if(trouve==true)
	printf("\n\"%s\" a été supprimé!\n\n",nomAsupprimer);
else
		printf("\n\"%s\" n'a pas été trouvé dans le dictionnaire de prediction!\n\n",nomAsupprimer);
	
	free(listeAsupprimer);



return 1;
}
	
char *date(void){//envoie la date sous forme de string au moment exacte du choix de l'utilisateur du mot à utilisers



 char* format=(char*)malloc(128*sizeof(format));
    time_t temps;
    struct tm date;

    // On récupère la date et l'heure actuelles.
    time(&temps);
    date=*localtime(&temps);

    // On remplit la chaîne avec le format choisi, puis on l'affiche.
    strftime(format, 128, "%x \n", &date);
    //puts(format);
	return format;

}

char*heure(void){//envoie l'heure sous forme de string au moment exacte du choix de l'utilisateur du mot à utilisers

 char* format=(char*)malloc(128*sizeof(format));
    time_t temps;
    struct tm date;

    // On récupère la date et l'heure actuelles.
    time(&temps);
    date=*localtime(&temps);

    // On remplit la chaîne avec le format choisi, puis on l'affiche.
    strftime(format, 128, "%X \n", &date);
    //puts(format);
	return format;

}


void MiseAjour(Liste*liste){//écrit dans un fichier MAJ les éléments de la liste chainées
FILE *file=NULL;

file=fopen("MAJ.txt","w");
if(file==NULL)
	printf("Erreur d'ouverture du fichier MAJ.txt!\n");
else{

	
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

   Mot *actuel = liste->premier;


    while (actuel != NULL  )
    {
	if(strcmp(actuel->nom,"")!=0)
       		 fprintf(file,"%s %d %s %s \n   ", actuel->nom,actuel->Occurence,actuel->date,actuel->heure);
        actuel = actuel->suivant;

    }


}

fclose(file);

}
Liste *initialisation2()
{
    Liste *liste = malloc(sizeof(*liste));
    Mot *mot = malloc(sizeof(*mot));

    if (liste == NULL || mot == NULL)
    {
        exit(EXIT_FAILURE);
    }

    strcpy(mot->nom,"");//pour initialiser
    mot->Occurence=0;//pour initialiser
    mot->suivant = NULL;
    liste->premier = mot;

    return liste;
}



void LectureFichier(Liste *liste){//Pour remplir la liste chaînée

FILE *fichier=NULL;
char mot[MAX_CAR];
char date[128];
char heure[128];
fichier=fopen(NOM_FIC1,"r");
if (fichier==NULL)
        printf("Erreur d'ouverture");


else{
    while(!feof(fichier)){
        fscanf(fichier,"%s %s %s \n",mot,date,heure);
	Mot*trouve=trouver(liste,mot);
	if(trouve==NULL)
       	 	insertion(liste,mot,date,heure);
	else{
		strcpy(trouve->date,date);
		strcpy(trouve->heure,heure);
		trouve->Occurence++;}

        }//fin  while
fclose(fichier);
}	//fin else


}

//ouverture fichier Prediction->et insere les mots en comptant leur occurences

void insertion(Liste *liste, char nvNom[MAX_CAR],char date[128],char heure[128])
{
    /* Création du nouvel élément */
    Mot *nouveau = malloc(sizeof(*nouveau));
    if (liste == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }
    strcpy(nouveau->nom,nvNom);

        nouveau->Occurence=1;
	strcpy(nouveau->date,date);
     strcpy(nouveau->heure,heure);
    /* Insertion de l'élément au début de la liste */
    nouveau->suivant = liste->premier;
    liste->premier = nouveau;
}


Mot* trouver(Liste* liste,char mot[MAX_CAR]){


if (liste == NULL)
    {

        exit(EXIT_FAILURE);
    }

   Mot *actuel = liste->premier;


	while(actuel!=NULL){


	if(strcmp(actuel->nom,mot)==0 ){
            Mot* trouve;
	trouve = actuel;
    strcpy(trouve->nom,mot);




    return trouve;




        }


 actuel=actuel->suivant;




}

return NULL;

}

void afficherListe(Liste *liste){

    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

   Mot *actuel = liste->premier;


    while (actuel != NULL  )
    {
	if(strcmp(actuel->nom,"")!=0)
       		 printf("  %s  (%d fois) %s %s  \n  ", actuel->nom,actuel->Occurence,actuel->date,actuel->heure);
        actuel = actuel->suivant;

    }


}
