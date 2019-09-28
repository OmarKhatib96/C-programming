
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NOM_FIC1     "prediction.txt"
#define MAX_CAR     30
# define CAPACITE 80


typedef struct Mot Mot;
struct Mot
{
    char nom[MAX_CAR];
    int Occurence;
   char date[128];
 char heure[128];
    Mot *suivant;

};



typedef struct Liste Liste;
struct Liste
{
    Mot *premier;
};

char*date(void);
char*heure(void);
void MiseAjour(Liste*liste);//écrit dans un fichier MAJ les éléments de la liste chainées
Liste *initialisation2();
void LectureFichier(Liste *liste);
char*date(void);
void insertion(Liste *liste, char nvNom[MAX_CAR],char date[128],char heure[128]);
Mot* trouver(Liste* liste,char mot[MAX_CAR]);
void afficherListe(Liste *liste);
int Suppression(const char* NomFichier,char nomAsupprimer[30]);
int ModificationMot(const char* NomFichier,char nomAmodifier[30],char MotRemp[30]);
