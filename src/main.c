#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
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
    while (fscanf(fd, "%s\n", string) == 1) {
//        fscanf(fd, "%s", poubelle);
        printf("%s\n", string);
        ajouter_mot(dic, string);
    }
    fclose(fd);

    //FILE* correct = fopen(argv[1], "r");
//    errno = 0;
//    if (correct == NULL) {
//        printf ("Erreur lors de l'ouverture du fichier %s : %d (%s)\n", argv[1] , errno , strerror(errno));
//        return 1;
//    }




	return 0;
}
