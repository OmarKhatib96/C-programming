#ifndef H_EXAM
#define H_EXAM
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
void afficher(int ** mat,int n);
int **allocate_board(int n);
int** graph_adjacency_matrix(void);
Liste*  ListeAdjacence(void);
int nbr_sommet(void);
bool voisins(int i,int j,int  **MatriceAdjacence);
void  parcoursLargeur(int **matriceAdjacence,int s,int Coloriation[]);
int rechercheElement(int * liste,int element);
bool TestBiparti(int * ListeColor1,int **MatriceAdjacence);

#endif
