
#include "conjugaison.h"

/* Fonction qui prend en argument le texte à tester et l'indice du verbe à conjuguer et identifie le sujet du verbe 
    et renvoie un entier lui correspondant.

    0: je
    1: tu
    2: il/elle/on
    3: nous
    4: vous
    5: ils/elles

    Si le sujet est un nom commun -> 3 pers du singulier s'il est dans le dictionnaire, pluriel sinon
    (on part du principe que le mot précédant le verbe est le sujet et qu'il ne s'agit pas d'un adjectif)

    (seuls je, tu, il, on sont traités désolé <3)
*/
enum PERS id_sujet(char *mot, dico dict) {
    if (strcmp(mot, "je")) {
        return JE;
    }

    if (strcmp(mot, "tu")) {
        return TU;
    }

    if (strcmp(mot, "il") || strcmp(mot, "elle") || strcmp(mot, "on")) {
        return PERS_SING;
    }

    if (strcmp(mot, "nous")) {
        return NOUS;
    }

    if (strcmp(mot, "vous")) {
        return VOUS;
    }

    if (strcmp(mot, "il") || strcmp(mot, "elle") || strcmp(mot, "on")) {
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

int est_verbe(dico v) {
    if (islower(v->type[0])) {
        if (v->type[0] == 'f') {
            return 2;
        }
        return 1;
    } else {
        return 0;
    }
}