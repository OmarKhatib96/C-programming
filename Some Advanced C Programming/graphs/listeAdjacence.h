#ifndef H_ADJ
#define H_ADJ
#include <stdlib.h>
#include <stdio.h>


typedef struct Sommet Sommet;
struct Sommet
{
    int numero;
    int voisins[40000];
    Sommet *suivant;
};

typedef struct Liste Liste;
struct Liste
{
    Sommet *premier;
};


Liste *initialisation();







#endif
