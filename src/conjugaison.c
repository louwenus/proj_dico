#include "conjugaison.h"

/* Fonction qui prend en argument le texte à tester et l'indice du verbe à conjuguer et identifie le sujet du verbe 
    et renvoie un entier lui correspondant.

    0: je
    1: tu
    2: il/elle/on
    3: nous
    4: vous
    5: ils/elles

    Si le sujet est un nom commun -> 3 pers du singulier sujet'il est dans le dictionnaire, pluriel sinon
    (on part du principe que le mot précédant le verbe est le sujet et qu'il ne sujet'agit pas d'un adjectif)

    (seuls je, tu, il, on sont traités désolé <3)
*/
enum PERS id_sujet(char *mot, dico dict) {
    if (strcmp(mot, "je") == 0) {
        return JE;
    }

    if (strcmp(mot, "tu") == 0) {
        return TU;
    }

    if (strcmp(mot, "il") == 0 || strcmp(mot, "elle") == 0 || strcmp(mot, "on") == 0) {
        return PERS_SING;
    }

    if (strcmp(mot, "nous") == 0) {
        return NOUS;
    }

    if (strcmp(mot, "vous") == 0) {
        return VOUS;
    }

    if (strcmp(mot, "il") == 0 || strcmp(mot, "elle") == 0 || strcmp(mot, "on") == 0) {
        return PERS_PLUR;
    }

    dico result = chercher_mot(dict, mot);
    if (result == NULL || !result->terminal) {
        return PERS_PLUR;
    } else if (result->terminal) {
        return PERS_SING;
    }

    return ERROR;
}

int est_verbe(dico verbe) {
    if (verbe == NULL) {
        return 0;
    }
    if (islower(verbe->type[0])) {
        if (verbe->type[0] == 'f') {
            return 2;
        }
        return 1;
    } else {
        return 0;
    }
}

static void conju_grp2(char* verbe, enum PERS sujet) {;
    int i = 0;
    while(verbe[i] != '\0') { i++; }
    switch(sujet) {
        case(JE):
        case(TU):
            verbe[i-2]='i';
            verbe[i-1]='s';
            verbe[i] = '\0';
            break;
        case(PERS_SING):
            verbe[i-2]='i';
            verbe[i-1]='t';
            verbe[i] = '\0';
            break;
        case(NOUS):
            verbe[i-2]='i';
            verbe[i-1]='s';
            verbe[i]='s';
            verbe[i+1]='o';
            verbe[i+2]='n';
            verbe[i+3]='s';
            verbe[i+4] = '\0';
            break;
        case(VOUS):
            verbe[i-2]='i';
            verbe[i-1]='s';
            verbe[i]='s';
            verbe[i+1]='e';
            verbe[i+2]='z';
            verbe[i+3] = '\0';
            break;
        case(PERS_PLUR):
            verbe[i-2]='i';
            verbe[i-1]='s';
            verbe[i]='s';
            verbe[i+1]='e';
            verbe[i+2]='n';
            verbe[i+3]='t';
            verbe[i+4] = '\0';
            break;
        case ERROR:
            break;
    }
}

static void conju_grp1(char* verbe, enum PERS sujet) {
    int i = 0;
    while(verbe[i]!='\0'){i++;}
    switch(sujet) {
        case(JE):
            verbe[i-1]='\0';
            break;
        case(TU):
            verbe[i-1]='s';
            verbe[i] = '\0';
            break;
        case(PERS_SING):
            verbe[i-1]='e';
            verbe[i] = '\0';
            break;
        case(NOUS):
            verbe[i-2]='o';
            verbe[i-1]='n';
            verbe[i]='s';
            verbe[i + 1] = '\0';
            break;
        case(VOUS):
            verbe[i-1]='z';
            verbe[i] = '\0';
            break;
        case(PERS_PLUR):
            verbe[i]='n';
            verbe[i+1]='t';
            verbe[i + 2] = '\0';
            break;
        case ERROR:
            break;
    }
}

void conjug_verbe(char* verbe, enum PERS sujet, int groupe) {
    if (groupe == 1) {
        conju_grp1(verbe, sujet);
    } else if (groupe == 2) {
        conju_grp2(verbe, sujet);
    } else {
        printf("Tentative de conjugaison d'un non verbe !");
        exit(EXIT_FAILURE);
    }
}
