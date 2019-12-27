#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "StructureDonnees.h"

#include "InsertionClef.h"
#include "AffichagesCollisions.h"



void AfficherListe(Liste   *liste){
	if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

   Clef *actuel = liste->premier;
   printf("Les mots possédant la  clef %d sont :  \n ", actuel->clef);
    while (actuel != NULL)
    {


           printf("%s  \n " ,actuel->mot);
       
       
 actuel = actuel->suivant;
}



}
