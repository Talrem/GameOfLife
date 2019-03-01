#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define maxVoisin 3
#define voisNaissance 3
#define minVoisin 2
#define maxRange 105
#define maxRange2 50

void innitMatrice(FILE * fichier,int jeu[maxRange2][maxRange]){
  for(int i=0; i<maxRange2;i++){
    for(int j=0; j<maxRange;j++){
      jeu[i][j]=0;
    }
  }
  int x;
  int y;
  while(!feof(fichier)){
    fscanf(fichier,"%i",&x);
    fscanf(fichier,"%i",&y);
    jeu[x][y]=1;
  }
}

void generation(int jeu[maxRange2][maxRange],int voisins[maxRange2][maxRange]){
  for(int i = 0; i < maxRange2 ; i++){
    for(int j = 0; j < maxRange ; j++){
        if(voisins[i][j] > maxVoisin || voisins[i][j] < minVoisin){ //mort par surpopulation
          jeu[i][j]= 0;
        }
        if(voisins[i][j] == voisNaissance && jeu[i][j] == 0){ //naissance
          jeu[i][j]= 1;
        }
    }
  }
}

int estValide(int x, int y){
  return(x >=0 && y >=0 && x < maxRange2 && y < maxRange);
}

int parcoursVoisins(int jeu[maxRange2][maxRange], int i, int j){
  int nbVoisin = 0;
  if(estValide(i-1,j-1)){
    nbVoisin+=jeu[i-1][j-1];
  }
  if(estValide(i-1,j)){
    nbVoisin+=jeu[i-1][j];
  }
  if(estValide(i-1,j+1)){
    nbVoisin+=jeu[i-1][j+1];
  }
  if(estValide(i,j-1)){
    nbVoisin+=jeu[i][j-1];
  }
  if(estValide(i,j+1)){
    nbVoisin+=jeu[i][j+1];
  }
  if(estValide(i+1,j-1)){
    nbVoisin+=jeu[i+1][j-1];
  }
  if(estValide(i+1,j)){
    nbVoisin+=jeu[i+1][j];
  }
  if(estValide(i+1,j+1)){
    nbVoisin+=jeu[i+1][j+1];
  }
  return nbVoisin;
}

void nbVoisins(int jeu[maxRange2][maxRange],int voisins[maxRange2][maxRange]){
  for(int i=0; i<maxRange2;i++){
    for(int j=0; j<maxRange;j++){
      voisins[i][j]=parcoursVoisins(jeu,i,j);
    }
  }
}

void afficherMatrice(int jeu[maxRange2][maxRange]){
  for(int i=0; i<maxRange2;i++){
    for(int j=0; j<maxRange;j++){
      if(jeu[i][j]){
        printf("* ");
      }else{
        printf("  ");
      }
    }printf("\n");
  }
}

int main(){
  int jeu[maxRange2][maxRange];
  int voisins[maxRange2][maxRange];
  FILE * fichier;
  int X = 2000;
  fichier = fopen("i.txt","r");
  innitMatrice(fichier,jeu);
  for(int i = 0; i < X; i++){
    system("clear");
    printf("Generation  : %i\n\n", i);
    afficherMatrice(jeu);
    usleep(100000);
    nbVoisins(jeu, voisins);
    generation(jeu, voisins);
  }

  return 0;
}
