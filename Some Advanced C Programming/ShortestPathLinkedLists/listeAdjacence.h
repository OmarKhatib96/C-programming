#ifndef H_ADJ
#define H_ADJ
#include <stdlib.h>
#include <stdio.h>


typedef struct Sommet Sommet;//structure Sommet
struct Sommet
{
    int numero;

    Sommet *suivant;
 int distance;

};


typedef struct Liste2 Liste2;//liste chainées des voisins
struct Liste2
{
	Sommet *premier;

	
};

typedef struct Sommet2 Sommet2;//structure Sommet2 pour les voisins
struct Sommet2
{
    int numero;

    Sommet2 *suivant;

Liste2 *voisins;
};




typedef struct Liste Liste;//liste chainée des sommets
struct Liste
{
    Sommet2 *premier;

};


Liste *initialisation();
Sommet2 *ParcoursListe(Liste * liste,int i);
Liste2 *initialisation3();





#endif
