#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "dic.h"
#include "assert.h"

int main(int argc, char* argv[])
{
    assert(argc == 3); // 3 paramète d'après la consigne -------------------------------------------------
	
	dico dic = dictionnaire_vide();
    // FILE* fd = fopen("./fr-reforme1990_court_sans.dic", "r");
    FILE* fd = fopen(argv[1], "r");
    if (fd == NULL) {
        printf("Erreur lors de l'ouverture du fichier fr-reforme1990_court_sans.dic");
        return 1;
    }
    int nb_mots = 0;
    fscanf(fd, "%d\n", &nb_mots);

    char string[100];
    char poubelle[100];

    fscanf(fd, "%s\n", poubelle);
    while (fscanf(fd, "%s", string) == 1) {
        //ajout de du test de verbe ici -------------------------------------------------
        if est_un_verbe(string){
            ajouter_mot(dic, string);
        }
    }
    fclose(fd);

    // FILE* correct = fopen(argv[1], "r");
    // errno = 0;
    // if (correct == NULL) {
        // printf ("Erreur lors de l'ouverture du fichier %s : %d (%s)\n", argv[1] , errno , strerror(errno));
        // return 1;
    // }

    FILE *file_ptr;
    file_ptr = fopen("a_corriger.txt", "w");

    int ok = 1;
    while (ok) {
      scanf("%s", string);
      // printf("chaine lue %s\n", string);
      if (strcmp(string, "STOP") == 0) {
	// printf("coucou %s\n", string);
	// sortie de la boucle principale
	// break;
	ok = 0;
      } else if (!chercher_mot(dic, string)) {
            // fputs(string, file_ptr);
	    fprintf(file_ptr, "%s\n", string);
        }
    }
    printf("\n");
	return 0;
}

//fonction qui prend en paramètre un mot et revoie true si le mot est un verbe
bool est_un_verbe(char mot[100]){
    int i = 0;
	while(mot[i] != '/')
	{
        if (mot[i] == '\0'){return false;}
		i++;
	}
    return (mot[i + 1]>='a' && mot[i + 1]<='z');
}

//tkt ça marche 
char* conjuge(char* verbe, int pronom){
    char* Verbe_conjuge = (char*)malloc(sizeof(char*) * 100);
    int i = 0;
    while (verbe[i + 2] != '\0'){
        Verbe_conjuge[i] = verbe[i];
        i++;
    }
    if (verbe[i] == 'e'){
        if (pronom == 0 || pronom == 1 || pronom == 2 || pronom == 4 || pronom == 5){
            Verbe_conjuge[i] = 'e';
        }
        else{
            Verbe_conjuge[i] = 'o';
        }
        i++;
        if (pronom == 3 || pronom == 5){
            Verbe_conjuge[i] = 'n';
        }
        if (pronom == 1){
            Verbe_conjuge[i] = 's';
        }
        if (pronom == 4){
            Verbe_conjuge[i] = 'z';
        }
        i++;
        if (pronom == 3){
            Verbe_conjuge[i] = 's';
        }
        if (pronom == 5){
            Verbe_conjuge[i] = 't';
        }
    }else{
        Verbe_conjuge[i] = 'i';
        i++;
        if (pronom == 0 || pronom == 1 || pronom == 3 || pronom == 4 || pronom == 5){
            Verbe_conjuge[i] = 's';
        }
        else{
            Verbe_conjuge[i] = 't';
        }
        i++;
        if (pronom == 3 || pronom == 4 || pronom == 5){
            Verbe_conjuge[i] = 's';
        }
        i++;
        if (pronom == 4 || pronom == 5){
            Verbe_conjuge[i] = 'e';
        }
        if (pronom == 3 ){
            Verbe_conjuge[i] = 'o';
        }
        i++;
        if (pronom == 3 || pronom == 5){
            Verbe_conjuge[i] = 'n';
        }
        if (pronom == 4 ){
            Verbe_conjuge[i] = 'z';
        }
        i++;
        if (pronom == 5){
            Verbe_conjuge[i] = 't';
        }
        if (pronom == 3){
            Verbe_conjuge[i] = 's';
        }
    }
    return Verbe_conjuge;
}
