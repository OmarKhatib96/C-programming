#include "PCC.h"
#define NOM_FIC  "Rome.txt"


void ModiFichier(void){
int sommet,arrete;
FILE*fichier=fopen("g","r");
if(fichier==NULL)
	printf("ERROR\n");

else{
	FILE*fichier2=fopen(NOM_FIC,"w");
	if (fichier2==NULL)
		printf("ERROR2\n");
	else{
		int i,j, distance;
		fscanf(fichier,"%d %d\n",&sommet,&arrete);
		fprintf(fichier2,"%d\n%d\n",sommet,arrete);
		while(!feof(fichier)){
			fscanf(fichier,"%d %d %d\n",&i,&j,&distance);
			fprintf(fichier2,"%d %d %d\n",i+1,j+1,distance);
			}
		fclose(fichier);

	

}
	fclose(fichier2);
}

}
	
		
		

Liste* ListeAdjacence(void){
	
	    int i;
	    int j;
	    int nbr_sommets;
	    int nbr_arretes;
	    int distance;
	  // int compteurs[nbr_sommets];
		//for (int k=0;k<nbr_sommets;k++)
		//compteurs[k]=1;
	    Liste *listeadjacence=initialisation();
	    FILE*fichier=NULL;
	    fichier=fopen(NOM_FIC,"r");
	    if (fichier==NULL){
		printf("ERROR");
		return NULL;
	    }
	    else{
		 
		fscanf(fichier,"%d %d ",&nbr_sommets,&nbr_arretes);
		
		int marquer[nbr_sommets];
		for (int k=0;k<nbr_sommets;k++)
			marquer[k]=0;
	    	while(!(feof(fichier))){
			fscanf(fichier,"%d %d %d\n",&i,&j,&distance);
			if(marquer[i-1]==0){//S'il n'a pas déja été inséré dans la liste..
	    			Sommet2* sommetamodifier= insertion(listeadjacence,i);
				//printf("sommetamodifier->numero=%d\n",sommetamodifier->numero);
				marquer[i-1]=1;
				sommetamodifier->voisins=initialisation3();


			
   	 	//insertion2(sommetamodifier,j,compteurs[i-1]);
				insertion2(sommetamodifier,distance,j);


				//printf("sommetamodifier->voisins=%d\n",sommetamodifier->voisins->premier->numero);
	}
			//printf("oui\n");
		//compteurs[i-1]++;	



			else{//sinon il est déja inséré 

				Sommet2* sommet=ParcoursListe(listeadjacence,i);
				//printf("sommet->numero=%d\n",sommet->numero);
		//insertion2(sommet,j,compteurs[i-1]);
				insertion2(sommet,distance,j);

		//compteurs[i-1]++;


}
		}
			fclose(fichier);
}
	
	   //AfficherListe(listeadjacence,nbr_sommets+1);
	    printf("\n");
	return listeadjacence;
	}
//*******************************

int  echange(File *file,int i){
	if (file== NULL)
    {
        exit(EXIT_FAILURE);
    }
   int j;
   Sommet1 *actuel = file->premier;
	if(file->premier->numero==i){
		return 2;}
else{
    	while (actuel != NULL)
    {

		if(actuel->numero==i){
			j=file->premier->numero;
			file->premier->numero=i;
			actuel->numero=j;
			return 1;
	}
       else{
		actuel=actuel->suivant;

	}

   }
	return 0;
}


}


int ParcoursFile(File * file,int i){

	if (file== NULL)
    {
        exit(EXIT_FAILURE);
    }

   Sommet1 *actuel = file->premier;

    while (actuel != NULL)
    {
	
	if(actuel->numero==i)
		return 1;
       else
	actuel=actuel->suivant;



   }
		return 0;



}








void Enfilement(File *file, int nvNombre)
{
    Sommet1 *nouveau = malloc(sizeof(*nouveau));
    if (file == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }

    nouveau->numero = nvNombre;
    nouveau->suivant = NULL;

    if (file->premier != NULL) /* La file n'est pas vide */
    {
        /* On se positionne à la fin de la file */
        Sommet1 *elementActuel = file->premier;
        while (elementActuel->suivant != NULL)
        {
            elementActuel = elementActuel->suivant;
        }
        elementActuel->suivant = nouveau;
    }
    else /* La file est vide, notre élément est le premier */
    {
        file->premier = nouveau;
    }
}




int Defilement(File *file)
{
    if (file == NULL)
    {
        exit(EXIT_FAILURE);
    }

  int nombreDefile=0;

    /* On vérifie s'il y a quelque chose à défiler */
    if (file->premier != NULL)
    {
        Sommet1 *elementDefile = file->premier;

        nombreDefile = elementDefile->numero;
        file->premier = elementDefile->suivant;
        free(elementDefile);
    }

return 1;
}

File *initialisation2(void)
{
    File *file = malloc(sizeof(*file));
    file->premier = NULL;

    return file;
}








void Afficherf(File *file)
{
    if (file == NULL)
    {
        exit(EXIT_FAILURE);
    }

    Sommet1 *sommet = file->premier;

    while (sommet != NULL)
    {
        printf("%d ", sommet->numero);
        sommet = sommet->suivant;
    }

    printf("\n");
}













int nbr_sommet(void){

    int nbr_sommets;
    FILE*fichier;
    fichier=fopen(NOM_FIC,"r");
    if (fichier==NULL){
        printf("ERROR");
    }

    else{

        fscanf(fichier,"%d\n",&nbr_sommets);}
    fclose(fichier);
    return nbr_sommets;
	}


//**********




//************
int  minmax(int *t, int n,int *marquer2,File *file){

	int i;
	int min=INF;
	int indicemin=-1;


	  for(i=0;i<n;i++)
	    {

	      if (t[i]< min  && marquer2[i]==0 && ParcoursFile(file,i+1) ){//marquer2[i] contient les sommets qui ont déja été pris en compte dans le calcul du min , on les marque pour qu'ils n'influencie pas sur le calcul des min.

			min=t[i];

			indicemin=i;
	}}

	if (min<INF && indicemin>=0){
	marquer2[indicemin]=1;//on le marque

	  return indicemin;}
	else{
		return -1;}
}




//*******************








int * PlusCourtChemin(Liste *adjacence,int s,int *distance,int *marquer1,int *chemin){
	int compteur=0;
	int j;
	File *file=initialisation2();
	int *marquer2=(int*)malloc(sizeof(int)*(nbr_sommet()));
	for(j=0;j<nbr_sommet();j++){
		marquer2[j]=0;
	}

	int i;

	for(j=0;j<nbr_sommet();j++){
		marquer1[j]=0;
	}



	int indiceMin;


	Enfilement(file,s);





	for(i=1;i<=nbr_sommet();i++){


				distance[i-1]=INF;}//end for,tous les sommets a part s sont initialisés comme non marqués.

	//********************
	distance[s-1]=0;
	int nbr=nbr_sommet();
	int k=0;
	while(file!=NULL){

	//printf("les sommets presents dans la file sont :\n");

			//Afficherf(file);

			indiceMin=minmax(distance,nbr_sommet(),marquer2,file);//On cherche le sommet qui est à plus petite distance
			
			if (indiceMin==-1){

				/*for (int i=0;i<nbr_sommet();i++){
					
					printf("Pour atteindre le sommet %d on va parcourir une distance %d \n",i+1,distance[i]);
						}*/
	


			return NULL;}

			echange(file,indiceMin+1);//On l'échange avec le premier de la file

			Defilement(file);//On le défile








			int SommetMin=indiceMin+1;
			chemin[k]=SommetMin;
			k++;
			//printf(" %d ",SommetMin);
				//On prend le sommets de plus petit label
			marquer1[SommetMin-1]=1;//et on le marque

			Sommet2*sommet=ParcoursListe(adjacence,SommetMin);//On séléctionne le sommet dans la liste d'adjacence

		//printf("sommet=%d\n",sommet->numero);


			if(sommet!=NULL){
				
			Sommet *sommet3=sommet->voisins->premier;//On sélectionne
			

			while(sommet3!=NULL){//Pour tous les voisins i

					if(sommet3->numero>0 && sommet3->numero<=nbr_sommet() && sommet3->numero!=sommet->numero){//de d


							if(distance[SommetMin-1]+sommet3->distance<distance[sommet3->numero-1]){//juste
								distance[sommet3->numero-1]=distance[SommetMin-1]+sommet3->distance;

							if(marquer1[sommet3->numero-1]==0){//si j est non marqué...

								Enfilement(file,sommet3->numero);//On l'enfile
								marquer1[sommet3->numero-1]=1;//On le marque

													


}//fin if

}//fin if

}//fin if
		sommet3=sommet3->suivant;

}//fin while
}//FIN IF
	}//fin while

}//fin fonction



//*********************

int  main(){
	ModiFichier();
	Liste *listeadjacence=ListeAdjacence();

	int *distance=(int *)malloc(sizeof(int)*(nbr_sommet()));
	int *chemin=(int *)calloc(nbr_sommet(),sizeof(int)*(nbr_sommet()));




	int s;
	int a;
	int i=0;
	int *marquer1=(int *)malloc(sizeof(int)*(nbr_sommet()));


	 while(s!=-1){
	printf("Entrez un sommet de depart (entre 1 et %d)\n",nbr_sommet());
	scanf("%d",&s);
	//printf("Entrez un sommet d'arrivee (entre 1 et %d)\n",nbr_sommet());
	//scanf("%d",&a);
	printf("\nPour un trajet de distance minimale les sommets seront parcourus dans l'ordre suivant:\n");
        PlusCourtChemin(listeadjacence,s,distance,marquer1,chemin);
	for (int i=0;i<nbr_sommet();i++){
							if(chemin[i]>0)
					
							printf(" %d ",chemin[i]);
						}


					/*while( chemin[i]!=a){
						printf(" %d ",chemin[i]);
						i++;
						}
					if(chemin[i]!=a)
						printf("il n' y pas de chemin entre %d et %d",s,a);
	

					else 
						printf(" %d ",chemin[i]);*/
		printf("fin\n");				
}
	AfficherListe(listeadjacence);
	free(distance);
	free(marquer1);
	free(listeadjacence);
	
	return 0;
}

