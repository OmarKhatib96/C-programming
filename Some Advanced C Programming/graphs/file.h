

#ifndef H_FILE
#define H_FILE
#include <stdlib.h>
#include <stdio.h>




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

File *initialisation2(void);
void Enfilement(File *file, int nvNombre);
int Defilement(File *file);
void Afficherf(File *file);

#endif
