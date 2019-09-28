
#include "listeAdjacence.h"
#include "insertionSommet.h"
#include "AffichagesSommets.h"
#include "file.h"
#include "td1.h"


	

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





	int **allocate_board(int n)
	{

	    int **board = (int**)calloc(n,n * sizeof(int *));
	    int row;


	    for (row = 0; row < n; row++) {
		board[row] = (int *)calloc(n,n * sizeof(int));
	    }

	    return board;
	}




int** graph_adjacency_matrix(void){
	    int nbr_sommets;
	    int nbr_arretes;
	    int i=0;
	    int j=0;

	    FILE*fichier;
	    fichier=fopen("graph4.txt","r");
	    if (fichier==NULL){
		printf("ERROR");
	    }

	    else{

		fscanf(fichier,"%d\n",&nbr_sommets);
		fscanf(fichier,"%d\n",&nbr_arretes);	    
		int ** mat=allocate_board(nbr_sommets);
		for(int compteur=0;compteur<nbr_arretes;compteur++){
		    fscanf(fichier,"%d %d\n",&i,&j);
		    mat[i-1][j-1]=1;








	    }
	    fclose(fichier);



	    return mat;}
	}




Liste* ListeAdjacence(void){

	    int i;
	    int j;
	    int nbr_sommets;
	    int nbr_arretes;
	    FILE*fichier;
	    fichier=fopen("graph4.txt","r");
	    if (fichier==NULL){
		printf("ERROR");

	    }
	    else{
		fscanf(fichier,"%d %d",&nbr_sommets,&nbr_arretes);
		}
	    fclose(fichier);


	    int** matriceAdjacence=graph_adjacency_matrix();
	    Liste *listeadjacence=initialisation();

	    for (i=1;i<nbr_sommets+1;i++){
		int compteurs=0;
	    	Sommet*sommetamodifier= insertion(listeadjacence,i);


		for(j=1;j<nbr_sommets+1;j++){

		    if(matriceAdjacence[i-1][j-1]==1){
		   	 insertion2(sommetamodifier,j,compteurs);
		   	 compteurs++;
		    }
		    else
		    	insertion2(sommetamodifier,-2,compteurs);
	    




	    }}
	    AfficherListe(listeadjacence,nbr_sommets);
	    printf("\n");
	return listeadjacence;
	}


int nbr_sommet(void){

	    int nbr_sommets;
	    FILE*fichier;
	    fichier=fopen("graph4.txt","r");
	    if (fichier==NULL){
		printf("ERROR");
	    }

	    else{

		fscanf(fichier,"%d\n",&nbr_sommets);}
		fclose(fichier);
		return nbr_sommets;
		}








int rechercheElement(int * liste,int element){
	int i=0;
	int position=0;

	for(i=0; i<=nbr_sommet(); i++)
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
	int compteur=0;


void  parcoursLargeur(int **matriceAdjacence,int s,int Coloriation[]){
	int i;

	File*file=initialisation2();

	int *marquer1=(int *)malloc(sizeof(int)*(nbr_sommet()+1));
	Enfilement(file,s);
	Coloriation[s-1]=1;

	marquer1[s-1]=1;
	int origine;

	while(file!=NULL && origine !=0){


		origine=Defilement(file);
		if(origine!=0)
			printf("%d ",origine);
		for(i=1;i<=nbr_sommet();i++){
			if(origine!=0){
				if(matriceAdjacence[origine-1][i-1]){
					if (marquer1[i-1]!=1){



						Enfilement(file,i);

		 				Coloriation[i-1]=1-Coloriation[origine-1];
						marquer1[i-1]=1;



	}

	}}
	}

	}
	printf("**********************\n\n");

	}



	/********************************Parcours en profondeur******************************************/

	void parcoursProfondeur(int **matriceAdjacence,int s,int marquer2[]){

		int j;
		printf("%d ",s);
		marquer2[s-1]=1;

		for(j=1;j<=nbr_sommet();j++){

			if(marquer2[j-1]==0 && matriceAdjacence[s-1][j-1]){
				parcoursProfondeur(matriceAdjacence,j,marquer2);}
		}

	}


	

		
/*********************************************************/

bool TestBiparti(int  ListeColor1[],int **MatriceAdjacence){
	int i;
	int j;
	for(i=1;i<nbr_sommet()+1;i++){
		for(j=1;j<nbr_sommet()+1;j++){
			if(MatriceAdjacence[i-1][j-1]){

				if(ListeColor1[i-1]==ListeColor1[j-1]){

					printf("\n\n\nLe graphe n'est pas biparti!\n");
					return false;}
}}}
	printf("\nLe graphe est biparti!\n");
	return true;
		}




int  main(){

	int** MatriceAdjacence=graph_adjacency_matrix();
	printf("**********\n\n");
	Liste * liste=ListeAdjacence();
	printf("**********\n\n");
		int n=nbr_sommet();
	printf("La matrice d'adjacence de ce graphe est:\n\n");
	afficher(MatriceAdjacence,nbr_sommet());
	printf("\n");
	 	int Coloriation[n];
	printf("\n\nLes sommets visités en largeur sont:\n");

	parcoursLargeur(MatriceAdjacence,3,Coloriation);

	int marquer2[n];


	//for(int i=0;i<nbr_sommet();i++)
	//	marquer2[i]=0;

	//printf("\n\nLes sommets visités en profondeur sont:\n");
	//parcoursProfondeur(MatriceAdjacence,4,marquer2);
	
	printf("**********************\n\n");
	TestBiparti(Coloriation,MatriceAdjacence);

	    return 0;
	}
