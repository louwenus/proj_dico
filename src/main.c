#include <stdio.h>
#include <stdlib.h>
#include "dic.h"
#include "assert.h"

int main(int argc, char* argv[])
{
    //assert(argc == 2);
	/*if(argc == 1)
	{
		exit(EXIT_FAILURE);
	}*/
	
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
    for (int i = 0; i < nb_mots; ++i) {
        fscanf(fd, "%[^/]%s\n", string, poubelle);
//        fscanf(fd, "%s", poubelle);
        printf("%s\n", string);
        ajouter_mot(dic, string);
    }
    fclose(fd);

    //FILE* correct = fopen(argv[1], "r");

	return 0;
}
