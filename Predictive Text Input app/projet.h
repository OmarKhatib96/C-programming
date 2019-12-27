#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "GestionPrediction.h"


# define TAILLETAB 58 //=26 lettres majuscules + 6 caracteres intermédiaire +26 lettre minuscules +1 pour - 
# define NOM_FIC "dictionnaire.txt"
# define NOM_FIC2 "prediction.txt"
# define NBR_PROPOSITION 3



typedef struct Arbre Arbre;
struct Arbre
{
	Arbre *fils[TAILLETAB];
	bool MotComplet;//si la lettre atteinte marque un mot complet ou pas
    	bool marquer;//si la lettre atteinte marque un mot complet ou pas
	bool visite;//si la lettre atteinte a été visitée ou pas
};




char getch();
int ConvDate(char D[128]);
int ConvHeure(char H[128]);
void Trie(char Propositions[CAPACITE][40],Liste*liste);
int convertir(int caractere);
Arbre * initialisation(void);
void inserer(Arbre *DebutArbre, char mot[]);
Arbre *stockageArbre(char *nomFichier);
Arbre *stockageArbre2(char *nomFichier);
Arbre *Parcours(Arbre *DebutArbre , char debutMot[20]);
int EcritureIntuitive(Arbre *depart,char debutMot[],Arbre *DebutArbre,Arbre *depart2,char Mot[],char proposition[CAPACITE][40] );
void lancement(char  Proposition[CAPACITE][40],Liste*liste,int mode);

