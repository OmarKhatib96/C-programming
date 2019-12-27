#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

const int INF=15000000;

#include "insertionSommet.h"
#include "listeAdjacence.h"

#include "AffichagesSommets.h"
//Prototypes des fonctions:






//Prototypes des fonctions:
typedef struct Sommet1 Sommet1;
struct Sommet1
{
    int numero;
    Sommet1 *suivant;
    
};



typedef struct File File;
struct File
{
    
    Sommet1 *premier;
   
};

Liste* ListeAdjacence(void);
int  echange(File *file,int i);
int ParcoursFile(File * file,int i);
void Enfilement(File *file, int nvNombre);
int Defilement(File *file);
File *initialisation2(void);
void afficher(int ** mat,int n);
void Resultat(int *marquer1,int *distance);
int  echange(File *file,int i);
void Afficherf(File *file);
int nbr_sommet(void);
int  minmax(int *t, int n,int *marquer2,File *file);

int * PlusCourtChemin(Liste *adjacence,int s,int *distance,int *marquer1,int *chemin);



