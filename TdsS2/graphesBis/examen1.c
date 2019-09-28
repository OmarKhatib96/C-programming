#include <stdio.h>
#include <stdlib.h>


int** graph_matrice(void);
void afficher(int ** mat,int n);
int **allocate_board(int n);

//détermine le nombre de sommets    
int nbr_sommet(void){

    int nbr_sommets;
    FILE*fichier;
    fichier=fopen("graph.txt","r");
    if (fichier==NULL){
        printf("ERROR");
    }

    else{

        fscanf(fichier,"%d\n",&nbr_sommets);}
fclose(fichier);
return nbr_sommets;
	}
        



void afficher(int ** mat,int n){
    int i;
    int j;
    for (i=1;i<n+1;i++){

        for (j=1;j<n+1;j++){
            printf("%d ",mat[i-1][j-1]);


        }
printf("\n");//sauter de ligne à la fin de chaque ligne de matrice.
    }


}





int **allocate_board(int n)
{

    int **board = (int**)malloc(n * sizeof(int *));
    int row;


    for (row = 0; row < n; row++) {
        board[row] = (int *)malloc(n * sizeof(int));
    }

    return board;
}




int** graph_matrice(void){
    int nbr_sommets;
    int nbr_arretes;
    int i;
    int j;

    FILE*fichier;
    fichier=fopen("graph.txt","r");
    if (fichier==NULL){
        printf("ERROR");
    }

    else{

        fscanf(fichier,"%d\n",&nbr_sommets);
        fscanf(fichier,"%d\n",&nbr_arretes);

    }
        int** mat=allocate_board(nbr_sommets);
        while(!feof(fichier)){
            fscanf(fichier,"%d %d\n",&i,&j);
            mat[i-1][j-1]=1;








    }
    fclose(fichier);


    for(i=1;i<nbr_sommets+1;i++){
        for(j=1;j<nbr_sommets+1;j++){
            if((mat[i-1][j-1]!=1)){
                mat[i-1][j-1]=0;}
        }}

    return mat;
}









   
    








int  main(){

int** MatriceAdjacence=graph_matrice();
printf("La matrice représentant  ce graphe est:\n\n");

afficher(MatriceAdjacence,nbr_sommet());



    return 0;
}
