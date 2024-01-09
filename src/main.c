#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "dic.h"
#include "assert.h"

int main(int argc, char* argv[])
{
  assert(argc == 2);
	
	dico dic = dictionnaire_vide();
    FILE* fd = fopen("./fr-reforme1990_court_sans.dic", "r");
    if (fd == NULL) {
        printf("Erreur lors de l'ouverture du fichier fr-reforme1990_court_sans.dic");
        return 1;
    }
    int nb_mots = 0;
    fscanf(fd, "%d\n", &nb_mots);

    char string[100];
    char poubelle[100];

    fscanf(fd, "%s\n", poubelle);
    while (fscanf(fd, "%s\n", string) == 1) {
        ajouter_mot(dic, string);
    }
    fclose(fd);

    FILE* input = fopen(argv[1], "r");
    errno = 0;
    if (input == NULL) {
        printf ("Erreur lors de l'ouverture du fichier %s : %d (%s)\n", argv[1] , errno , strerror(errno));
        return 1;
    }

    FILE *output;
    output = fopen("a_corriger.txt", "w");

    while (fscanf(input, "%s\n", string) == 1) {
        dico result=chercher_mot(dic,string );
        if (result == NULL || !result->terminal) {
            fputs(string, output);
            fputs("\n", output);
        }
    }
    fclose(input);
	return 0;
}
