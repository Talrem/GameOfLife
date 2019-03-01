#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#define maxRange 105
#define maxRange2 50

void generation(FILE * fichier){
  int x, y;
  x = rand()%maxRange2;
  y = rand()%maxRange;
  fprintf(fichier,"%i %i ",x,y);
}

int main(){
  srand(time(NULL));
  FILE * fichier;
  int X = 0; //nombre de générations à afficher
  printf("saisissez le nombre de cases à générer : ");
  while(X < 1){
    scanf("%i",&X);
  }
  fichier = fopen("i.txt","w");
  for(int i = 0; i < X; i++){
    generation(fichier);
  }
  fclose(fichier);
  system("./jeu.exe");
  return 0;
}
