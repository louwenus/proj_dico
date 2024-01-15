#ifndef CONJUGAISONH
#define CONJUGAISONH

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "string.h"
#include "dic.h"
enum PERS {
    JE,
    TU,
    PERS_SING,
    NOUS,
    VOUS,
    PERS_PLUR,
};


/** Fonction qui prend en argument le texte à tester et l'indice du verbe à conjuguer et identifie le sujet du verbe
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
int id_sujet(char *mot, dico dict);

#endif //ifndef CUNJUGAISONH
