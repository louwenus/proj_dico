#include <stdio.h>
#include <stdlib.h>
#include "dic.h"

int main(int argc, char* argv[])
{
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
    fscanf(fd, "%d", &nb_mots);

    char string[100];
    char poubelle[100];

    fscanf(fd, "-");
    for (int i = 0; i < nb_mots; ++i) {
        fscanf(fd, "%s/%s", string, poubelle);
        ajouter_mot(dic, string);
        printf("%s\n", string);
    }
    fclose(fd);

	return 0;
}
