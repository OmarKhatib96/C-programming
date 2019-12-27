#include "PCC.h"


int nbr_sommet(void){

    int nbr_sommets;
    FILE*fichier;
    fichier=fopen("graph1.txt","r");
    if (fichier==NULL){
        printf("ERROR");
    }

    else{

        fscanf(fichier,"%d\n",&nbr_sommets);}
    fclose(fichier);
    return nbr_sommets;
	}


//**********



int sommeElement(int *t1,int n){
 int somme=0;
 int i;
 for(i=0;i<n;i++){
	somme=somme+t1[i];
}
 return somme;

}


//************
int  minmax(int *t, int n,int *marquer2){

	int i;
	int min=INF;
	int indicemin;


	  for(i=0;i<n;i++)
	    {

	      if (t[i]< min  && marquer2[i]!=1){

			min=t[i];
			indicemin=i;
	}}

	marquer2[indicemin]=1;
	  return indicemin;
}




//*******************



void afficher(int ** mat,int n){
    int i;
    int j;
    for (i=1;i<n+1;i++){

        for (j=1;j<n+1;j++){
            printf("%d ",mat[i-1][j-1]);


        }
printf("\n");
    }


}







//*********************

int **allocate_board(int n)
{

    int **board = (int **)malloc(n * sizeof(int *));
    int row;


    for (row = 0; row < n; row++) {
        board[row] = (int *)malloc(n * sizeof(int));
    }

    return board;
}



//*************************
int** distance_matrix(void){
    int nbr_sommets;
    int nbr_arretes;
    int valeur;
    int i;
    int j;

    FILE*fichier;
    fichier=fopen("graph1.txt","r");
    if (fichier==NULL){
        printf("ERROR");
    }

    else{

        fscanf(fichier,"%d\n",&nbr_sommets);
        fscanf(fichier,"%d\n",&nbr_arretes);

    }
        int** mat=allocate_board(nbr_sommets);
        while(!feof(fichier)){
            fscanf(fichier,"%d %d %d\n",&i,&j,&valeur);
            mat[i-1][j-1]=valeur;








    }
    fclose(fichier);


    for(i=1;i<nbr_sommets+1;i++){
        for(j=1;j<nbr_sommets+1;j++){
            if((mat[i-1][j-1]>33)){
                mat[i-1][j-1]=0;}
        }}

    return mat;
}

//****************************

bool voisins(int i,int j,int  **MatriceAdjacence){
		if (i>0 &&i<nbr_sommet()+1 && j>0 && i<nbr_sommet()+1){
			if( MatriceAdjacence[i-1][j-1]!=0){

				return true;
	}
			else{

				return false;

	}}
		else

			return 2;

}







//***************************************

int rechercheElement(int * liste,int element){

	int i;
	int position;

	for(i=0; i<nbr_sommet(); i++)
		{
		if(liste[i]==element)
		        {
		        position=i+1;
		        i=2*nbr_sommet();
		        }
		}
	if(i==(2*nbr_sommet())+1)
		{

		return 1;
		}
	else
		{

	return 0;
		}

}
//************************
int * PlusCourtChemin(int **matriceAdjacence,int s){
	int compteur=0;
	int j;

	int *marquer2=(int*)malloc(sizeof(int)*(nbr_sommet()));
	for(j=0;j<nbr_sommet();j++){
		marquer2[j]=0;
	}

	int i;
	int *marquer1=(int *)malloc(sizeof(int)*(nbr_sommet()));
	for(j=0;j<nbr_sommet();j++){
		marquer1[j]=0;
	}

	int *distance=(int *)malloc(sizeof(int)*(nbr_sommet()));

	int indiceMin;



	distance[s-1]=0;




	for(i=1;i<=nbr_sommet();i++){

		if(i!=s){
				distance[i-1]=INF;}}//end for,tous les sommets a part s sont initialisés comme non marqués.

	//********************
	int nbr=nbr_sommets();
	/*if(s==1){
	nbr=6;}
	if(s==6){
	nbr=1;}

	if(s==2){
	nbr=5;}
	if(s==3){
	nbr=5;}
	if(s==4){
	nbr=5;}
	if(s==5){
	nbr=5;}*/
	while(sommeElement(marquer2,nbr_sommet())<nbr){



			indiceMin=minmax(distance,nbr_sommet(),marquer2);









			int SommetMin=indiceMin+1;

				//On prend le sommets de plus petit label
				marquer1[compteur]=SommetMin;//et on le marque



				compteur++;





				int j;

				for(j=1;j<=nbr_sommet();j++){//Pour tous les voisins i

					if(voisins(SommetMin,j,matriceAdjacence)==1){//de d

						if( rechercheElement(marquer1,j)==0){//si y est non marqué...
							if(distance[SommetMin-1]+matriceAdjacence[SommetMin-1][j-1]<distance[j-1]){
								distance[j-1]=distance[SommetMin-1]+matriceAdjacence[SommetMin-1][j-1];



	}}}

	}

	}
//******************************
	
	//distance[i-1] prend la valeur de la plus petite valeur.-1


	int k;

	printf("Pour un trajet de distance minimale les sommets seront parcourus dans l'ordre suivant:\n");

	for (i=0;i<nbr_sommet();i++){
		if (marquer1[i]!=0)

		printf("%d ",marquer1[i]);
	}
	FILE*fichier;

	fichier=fopen("PlusCourtChemin.txt","w");
	if(fichier==NULL)
		printf("Erreur d'ouverture du fichier");
	else{
			fprintf(fichier,"Les sommets correspondant aux plus court chemins sont : \n");
			for (k=0;k<nbr_sommet();k++){
				if(marquer1[k]!=0){
				
				fprintf(fichier,"%d ",marquer1[k]);}
	}}

	fclose(fichier);
	printf("\n");
	printf("La valeur du plus court chemin pour atteindre chaque sommet est : \n");

	for (i=0;i<nbr_sommet();i++){
		printf("%d ",distance[i]);
	}
	printf("\n");

	return distance;
}
/*char *Correspondance(int sommet){
	char *caractere;

			if (sommet==1)
			caractere="A";

			if (sommet==2)


			caractere="B";


			if (sommet==3)

			caractere="C";

				if (sommet==4)


			caractere="D";

				if (sommet==5)

			caractere="E";

				if (sommet==6)
			caractere="F";
	return caractere;

	}*/

//****************************
int Export(int s,int **MatriceDistance){
	FILE*fichier;
	int *distance1=PlusCourtChemin(MatriceDistance,s);
	fichier=fopen("PlusCourtChemin.txt","a");
	if(fichier==NULL)
		printf("Erreur d'ouverture du fichier");
	else{
		fprintf(fichier,"\nLes valeurs des plus chemins du sommet %d vers tous les autres sommets dans l'ordre A,B,C,D,E,F sont:\n",s);
		int i;
		for( i=0;i<nbr_sommet();i++){
			fprintf(fichier,"%d ",distance1[i]);
	}
	}
	return 0;
}
//******************************
int  main(){


int** MatriceDistance=distance_matrix();
	printf("La matrice de distance de ce graphe est:\n");
	afficher(MatriceDistance,nbr_sommet());
	int distance[nbr_sommet()];
	printf("Entrez le sommet de depart\n");
	int s;
	scanf("%d",&s);
	PlusCourtChemin(MatriceDistance,s);
	//Export( s,MatriceDistance);
	return 0;
}

