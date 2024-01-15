#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "conjugaison.h"
#include "dic.h"
#include "main.h"
#include "assert.h"

dico init_dico(const char * path){

    dico dic = dictionnaire_vide();
    FILE* fd = fopen(path, "r");
    if (fd == NULL) {
        printf("Erreur lors de l'ouverture du fichier fr-reforme1990_court_sans.dic");
        exit(1);
    }
    int nb_mots = 0;
    fscanf(fd, "%d\n", &nb_mots);

    char string[100];
    fscanf(fd, "%s\n", string);
    while (fscanf(fd, "%s\n", string) == 1) {
        ajouter_mot(dic, string);
    }
    fclose(fd);
    return dic; 
}

int main(int argc, char* argv[])
{
  if(argc != 4){
        printf("Usage: %s fichier_dico.dic fichier_entree.txt fichier_sortie.txt",argv[0]);
        exit(1);
    }

	dico dic = init_dico(argv[1]);	
    FILE* input = fopen(argv[2], "r");
    errno = 0;
    if (input == NULL) {
        printf ("Erreur lors de l'ouverture du fichier %s : %d (%s)\n", argv[1] , errno , strerror(errno));
        return 1;
    }

    FILE *output;
    output = fopen(argv[3], "w");

    
    char string[100];
    char minus[100];
    int index=0;
    char in='a';
    enum PERS last_pers=JE;

    while (true) {
        in=getc(input);
        if (in==EOF)break;
        if (isalpha(in)){
            string[index]=in;
            minus[index]=tolower(in);
            index++;
        } else {
            if (index>0){
            string[index]='\0';
            minus[index]='\0';
                
            int groupe=est_verbe(chercher_mot(dic, minus));
            if (groupe != 0){
                   //conjuger 
            } else {
                fputs(string, output);
            }

            last_pers=id_sujet(minus, dic);

            index=0;
            }
            //ensuite on copie le char spécial dans la sortie
            fputc(in,output);
        }
    }
    fclose(input);
    fclose(output);
	return 0;
}
