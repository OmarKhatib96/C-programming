



#include <unistd.h>  
#include <termios.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

#include "projet.h"

char getch(){//Cette fonction n'étant pas une fonction standard du C j'ai dû l'empreinter d'internet, elle permet de saisir un char sans appuyer sur entrer
    char buf=0;
    struct termios old={0};
    fflush(stdout);
    if(tcgetattr(0, &old)<0)
        perror("tcsetattr()");
    old.c_lflag&=~ICANON;
    old.c_lflag&=~ECHO;
    old.c_cc[VMIN]=1;
    old.c_cc[VTIME]=0;
    if(tcsetattr(0, TCSANOW, &old)<0)
        perror("tcsetattr ICANON");
    if(read(0,&buf,1)<0)
        perror("read()");
    old.c_lflag|=ICANON;
    old.c_lflag|=ECHO;
    if(tcsetattr(0, TCSADRAIN, &old)<0)
        perror ("tcsetattr ~ICANON");
    printf("%c",buf);
    return buf;
 }


int ConvDate(char D[128]){//elle permet de convertir la date originalement sous la forme de string(jj/mm/a) en un tableau d'entiers tab[]={j,j,m,m,a,a} pour mieux les manipuler.

	char temp[1];
	int jours;
	int mois;
	int an;
	int somme;
	int *Date=(int*)(malloc(sizeof(int)*128));
	int i=0;
	int indice;
	for(indice=0;indice<strlen(D);indice++){
		if(D[indice]!='/'){
			temp[0]=D[indice];
			Date[i]=atoi(temp);
			i++;
}
		
}		
jours=10*Date[0]+Date[1];
 mois=10*Date[2]+Date[3];
 an=10*Date[4]+Date[5];
somme=365*an+30*mois+jours;
	return somme;//fait la somme pondérée de la date

}

int ConvHeure(char H[128]){//même objectif que ConvDate
	char temp[1];
	int heures;
	int minutes;
	int secondes;
	int somme;
	int *Heure=(int*)(malloc(sizeof(int)*128));
	int i=0;
	int indice;
	for(indice=0;indice<strlen(H);indice++){
		if(H[indice]!=':'){
			temp[0]=H[indice];
			Heure[i]=atoi(temp);
			i++;
}
		
}		
heures=10*Heure[0]+Heure[1];
minutes=10*Heure[2]+Heure[3];
secondes=10*Heure[4]+Heure[5];
somme=heures*3600+minutes*60+secondes;
return somme;
}





void Trie(char Propositions[CAPACITE][40],Liste*liste){//Cette fonction utilise un algorithme de trie classqie:Elle permet de classer les propositions selon leur occurences d'abord, et dans le cas ou deux propositions ont le même nombre d'occurence, elle compare leur ordre chronologique,grace aux deux fonctions ConvHeure et ConvDate.
	
   int i;
   int j;
   char echange[40];
  Mot*mot1;
Mot*mot2;
int somme1,somme2;
   for(i=1;i<CAPACITE;i++){
        int min=i;
        for(j=i+1;j<CAPACITE;j++){
	    mot1=trouver(liste,Propositions[j]);
	    mot2=trouver(liste,Propositions[min]);
		if(mot1!=NULL && mot2!=NULL){
	    somme1=ConvDate(mot1->date)*365*24*3600+ConvHeure(mot1->heure);
	    somme2=ConvDate(mot2->date)*365*24*3600+ConvHeure(mot2->heure);
	   if(mot1->Occurence>mot2->Occurence)
		min=j;
	   else if(mot1->Occurence==mot2->Occurence){//s'ils ont le même nombre d'occurence...
		if(somme1>somme2)//On regarde qui est le plus récent des deux
			
			  min=j;}
				
            
        }}
        if(min!=i){
        strcpy(echange,Propositions[i]);
        strcpy(Propositions[i],Propositions[min]);
       strcpy( Propositions[min],echange);}
   }




        }




int convertir(int caractere){
	int i=caractere-'A';//A est doté du code ascii le plus petit il sera donc en indice 0
return i;
}



Arbre * initialisation(void)//initialise l'arbre en allouant dynamiquement un élement de type arbre
{

 
   Arbre* nouveau = (Arbre*)malloc(sizeof(Arbre));
 
    if (nouveau!=NULL)
    {
       

	int i;
 
       nouveau->MotComplet = false;
       nouveau->marquer=false;
	nouveau->visite=false;
        for (i = 0; i <TAILLETAB; i++)
            nouveau->fils[i] = NULL;
    }
 
    return nouveau;
}
 
void inserer(Arbre *DebutArbre, char mot[])//insère le mot dans le bon endroit de l'arbres
{
int k;
int taille = strlen(mot);
int i;
Arbre *CaractereActuel=DebutArbre;
for (k = 0; k <taille; k++)
{
	i = convertir(mot[k]);//i est l'indice où sera mis la k-ème lettre du mot 
	if (CaractereActuel->fils[i]==NULL)//quand le caractere actuel n'a pas une suite(donc est le dernier caractere du mot)	
		CaractereActuel->fils[i]=initialisation();//On lui attribue un caractere fils
		CaractereActuel = CaractereActuel->fils[i];
			}

	CaractereActuel->MotComplet=true;//le dernier caractere correspond à la fin du mot inséré
}






Arbre *stockageArbre(char *nomFichier){//stocke les mots du dictionnaire de français dans l'arbre.

FILE*fichier=NULL;

char mot[30];

int i,taille;


Arbre*DebutArbre= initialisation();
fichier=fopen(nomFichier,"r");
if(fichier==NULL)
	printf("Erreur d'ouverture de fichier\n");
else {

		while(fscanf(fichier,"%s \n",mot)==1){
		
		


			taille=strlen(mot);
			 for (i = 0; i <taille; i++)
				inserer(DebutArbre, mot);
						}
		fclose(fichier);


	}

return DebutArbre;// l'arbre qui est notre structure de données principale est désignée par sa source /racine DebutArbre.
}



Arbre *stockageArbre2(char *nomFichier){//sert à stocker les mots du dictionnaire de prédiction
FILE*fichier=NULL;

char mot[30];
char date[128];
char heure[128];
int i,taille;
Arbre*DebutArbre= initialisation();
fichier=fopen(nomFichier,"r");
if(fichier==NULL)
	printf("Erreur d'ouverture de fichier\n");
else {

		while(fscanf(fichier,"%s %s %s\n",mot,date,heure)==3){
		
		


			taille=strlen(mot);
			 for (i = 0; i <taille; i++)
				inserer(DebutArbre, mot);
//				printf("%s\n",mot);
						}
		fclose(fichier);


	}

return DebutArbre;
}



Arbre *Parcours(Arbre *DebutArbre , char debutMot[20]){//cette fonction envoie un pointeur sur l'élément de type arbre repérant la position (l'adresse) de debutMot dans l'arbre.
	int k=0, taille = strlen(debutMot);//initialisation taille
int i;
	
	Arbre *CaractereActuel=DebutArbre;
	if((char)(debutMot[k]-'A')>TAILLETAB || (char)(debutMot[k]-'A')<0)//Si l'indice de  première lettre du mot est supérieure à la taille du tableau (58) ou inférieure 0 on renvoie NULL.
			return NULL;
	i=convertir(debutMot[k]);//initaliser i pour entrer dans la boucle while
	if(CaractereActuel->fils[i]==NULL)//si la première lettre ne figure pas dans l'arbre le mot n'existe forcément pas dans l'arbre
		return NULL;
	while(CaractereActuel->fils[i]!=NULL){//tant qu'on atteint pas la fin du mot
		k++;//on passe au caractère suivant 
		CaractereActuel = CaractereActuel->fils[i];
		i = convertir(debutMot[k]);}


	 
	    

			char c=(char)(i+'A');

			if(debutMot[k]==c && k+1<=taille)//si c'est le caractere "c" qui a provoqué la sortie de la boucle
				return NULL;
			else
				return CaractereActuel;

	 	}


int p=0;//variable global pour éviter d'être réinitialisé à 0 après chaque appel récursif


int EcritureIntuitive(Arbre *depart,char debutMot[],Arbre *DebutArbre,Arbre *depart2,char Mot[],char proposition[CAPACITE][40] ){/*cette fonction va stocker les résultats de l'écriture intuitive dans proposition[CAPACITE][40].
En s'inspirant de l'algorithme de parcours en profondeur, EcritureIntuitive() utilise un double appel récursive pour atteindre tous les mots commençant par debutMot[]*/
	int d=0;

	int i;
	int k;
	char* car=calloc(2,sizeof(char)*2);
	char intuitive[40];
	strcpy(intuitive,debutMot);
	if(depart==NULL){
		return -1;
}

 Arbre *CaractereActuel=depart;

if(depart->MotComplet==true)
	strcpy(proposition[0],Mot);			
		
						


for(int j=0;j<TAILLETAB;j++){

	if(CaractereActuel->fils[j]!=NULL &&  !CaractereActuel->fils[j]->visite){//si l'élement suivant est non nul et n'a pas été visité

	

		char c=(char)(j+'A');
 	 	car[0]=c;
		strcat(intuitive,car);
		CaractereActuel->fils[j]->visite=true;//On le marque visite
		CaractereActuel=CaractereActuel->fils[j];

		if( CaractereActuel->MotComplet && !CaractereActuel->marquer){
														p++;
			if(p<=CAPACITE){//si on dépasse pas la taille CAPACITE
			strcpy(proposition[p],intuitive);

			CaractereActuel->marquer=true;

				}		

		}//fin if


		for(int k=0;k<TAILLETAB;k++){//Il faut exécuter ce bloc un nombre de fois égal à TAILLETAB pour bien passer sur toutes les lettres A....Z a..z
			if(CaractereActuel->fils[k]!=NULL)
				EcritureIntuitive(CaractereActuel,intuitive,DebutArbre,depart2,Mot,proposition);//1er appel récursive (exploration en profondeur)
			else

				d++;
				}//fin for
			if(d==TAILLETAB){//Si toutes les lettres suivantes sont nulles donc y a plus aucun mot à explorer.
				


					EcritureIntuitive(depart2,Mot,DebutArbre,depart2,Mot,proposition);// 2eme appel recursif,On reparcourt le graphe depuis le depart pour parcourir la deuxième lettre non encore explorée.		
			

	
}}}}
int compteur=0;//variable globale
void lancement(char  Proposition[CAPACITE][40],Liste*liste,int mode){//Cette fonction assure la gestion du choix des propositions ,en  
int choix;
char Choix[20];
char mot[20];
Arbre *DebutArbrePred=stockageArbre2(NOM_FIC2);
Arbre*depart;
Arbre *depart2;
Arbre* DebutArbreDico=stockageArbre(NOM_FIC);

if (mode==0){//si on choisit le mode normal,l'utilisateur saisira une partie du mot puis appuiera sur entrée pour obtenir les 3 propositions
	printf("Saisir mot\n");
 	scanf("%s",mot);}
else if(mode==1){//si on choisit le mode rapide , les propositions seront faites à l'utilisateur immédiatemnt après avoir tapé 3 lettres
	printf("\nDes propositions vous seront fournis immédiatement après avoir tapé 3 mots\n\n");
	printf("Saisir mot\n\n");
	mot[0]=getch();
	mot[1]=getch();
	mot[2]=getch();
}


printf("(%d) %s\n",CAPACITE+2,mot);
depart2=Parcours(DebutArbrePred ,mot);
depart=Parcours(DebutArbreDico ,mot);
FILE*file=fopen(NOM_FIC2,"a");
if(file==NULL)
	printf("Erreur d'ouverture du fichier!\n");
else{

if(EcritureIntuitive(depart2 ,mot,DebutArbrePred,depart2,mot,Proposition)!=-1){
		Trie(Proposition,liste);//On trie la liste de propositions selon occurence/chronologique
	for(int i=0;i<NBR_PROPOSITION;i++){
		if(Parcours(DebutArbrePred,Proposition[i+1])!=NULL){
				
						printf("(%d) %s\n",i+1,Proposition[i+1]);
					compteur++;
						}//fin if
				

}//fin for

int marqueur=0;//repere qu'on a pris completer du dictionnaire pour ensuite ajuster les indice des choix
int marqueur2=0;
int k=compteur;
int x=compteur;
	if(compteur<NBR_PROPOSITION && compteur>=1){//S'il n y a pas exactement 3 propositions...
		marqueur=1;
		while(k<3 && x<3){//tant qu'on a pas exactement 3 mots

				EcritureIntuitive(depart ,mot,DebutArbreDico,depart,mot,Proposition);
			if( Parcours(DebutArbreDico,Proposition[compteur+k+1 ]) !=NULL ){

if( strcmp(Proposition[compteur+k ],Proposition[1])!=0 || strcmp(Proposition[compteur+k+1],Proposition[2])){

					printf("(%d) %s(!New!)\n",k+1,Proposition[compteur+k+1 ]);
					k++;
				}//fin if(derniere modification)
}//fin if
			else{
				marqueur2++;//montre qu'on a pas rempli exactement 3 choix
				x++;}//Pour sortir de la boucle dans le cas où on trouve pas de mots 


}//fin while

	

	}//fin if

	printf("Fin des proposition!\n");
	choix=getch()-'0';	

		

	if(choix==CAPACITE+2){
			printf("Choix=%s\n",mot);
			fprintf(file,"%s %s %s \n",mot,date(),heure());}
else{
	if(marqueur2==0){
		printf("Choix=%s\n",Proposition[choix+compteur*marqueur]);
		fprintf(file,"%s %s %s \n",Proposition[choix+compteur*marqueur],date(),heure());}

	if(marqueur2==1){
		printf("Choix=%s\n",Proposition[choix+compteur*marqueur-2*marqueur2]);
		fprintf(file,"%s %s %s \n",Proposition[choix+compteur*marqueur-2*marqueur2],date(),heure());}

char reponse[40];
	if(marqueur2==2){
		if(choix==1)
			strcpy(reponse,Proposition[1]);
		if(choix==2)
			strcpy(reponse,Proposition[3]);
		if(choix==3)
			strcpy(reponse,Proposition[4]);
		printf("Choix=%s\n",reponse);
		fprintf(file,"%s %s %s\n",reponse,date(),heure());}
	}

}//fin if ecritureIntuitive(depart2

else{//on cherche dans le dictionnaire
		if(EcritureIntuitive(depart ,mot,DebutArbreDico,depart,mot,Proposition)!=-1){
			int choix=0;
			int tour=0;
			int i=0;

			while(choix==0){
				while(i<NBR_PROPOSITION+tour*NBR_PROPOSITION){
					if(i>=0 && i <=CAPACITE){
						if( Parcours(DebutArbreDico,Proposition[i+1])!=NULL)
						printf("(%d) %s\n",i+1,Proposition[i+1]);
						else
							printf("Fin des propositions\n ");


						}
			
						
					i++;
					}//fin while
										if( Parcours(DebutArbreDico,Proposition[i+1])!=NULL)
						printf("Saisir 0 pour afficher la suite------->\n");
				

			
			//scanf("%d",&choix);
																		  
		scanf("%d",&choix);


							tour++;
				
			}//fin while



if(choix==CAPACITE+2){
			printf("Choix=%s\n",mot);
			fprintf(file,"%s %s %s \n",mot,date(),heure());}

else{
				printf("Le mot \"%s\" a ete ajoute au dictionnaire predictif\n",Proposition[choix]);
				fprintf(file,"%s %s %s\n",Proposition[choix],date(),heure());			



}//fin else
}//fin if

		
}//fin else

	fclose(file);

}//fin else


free(DebutArbreDico);
free(depart2);
free(DebutArbrePred);
free(depart);

}//fin fonction

int main()
{
int mode;
int choix;
char MotAsupprimer[40];
char MotAmodifier[40];
char MotRemp[40];
Liste*liste=initialisation2();

LectureFichier(liste);

MiseAjour(liste);
printf("Bonjour,que voulez-vous faire?\n\n1) Saisir un mot\n\n2) Supprimer un mot du dictionnaire de prediction\n\n3) Modifier un mot\n\n");
scanf("%d",&choix);
switch(choix){

	case(1):
		printf("choisissez entre le mode d'écriture intuitive qui vous convient\n\n");

		printf("0) Désactiver le mode rapide \n\n1) Activer le mode rapide\n\n");

		mode=getch()-'0';
		char Proposition[CAPACITE][40];

		lancement(Proposition,liste,mode);
		break;

	case(2):
		
		printf("Saisir le mot a supprimer\n");
		scanf("%s",MotAsupprimer);
		Suppression(NOM_FIC2,MotAsupprimer);
	

		break;

	case(3):
		printf("Saisir le mot a modifier\n");
		scanf("%s",MotAmodifier);
		printf("Saisir le nouveau mot\n");
		scanf("%s",MotRemp);
		ModificationMot(NOM_FIC2,MotAmodifier,MotRemp);
	

		break;

	default:
		printf("Votre choix ne correspond à aucune proposition!\n");
}	
free(liste);



return 0;
} 

