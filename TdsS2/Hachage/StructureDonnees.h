#ifndef H_ADJ
#define H_ADJ
#include <stdlib.h>
#include <stdio.h>


typedef struct Clef Clef;
typedef struct Clef
{
    int SousClef;
    int clef;
    char mot[50];

    Clef *suivant;
} Clef;


typedef struct Liste Liste;
typedef struct Liste
{
Clef *premier;

}Liste;

Liste *initialisation();
	



#endif
