#ifndef CONJUGAISONH
#define CONJUGAISONH

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "string.h"
#include "dic.h"
#include "assert.h"


enum PERS {
    JE,
    TU,
    PERS_SING,
    NOUS,
    VOUS,
    PERS_PLUR,
    ERROR
};


/**
 * Prend un mot considéré comme le sujet et donne l'identifiant correspondant à la personne à conjuguer le verbe
 * @param mot le sujet de la phrase
 * @param dict le dictionnaire créé avant
 * @return l'identifiant de la personne à conjuguer
 */
enum PERS id_sujet(char *mot, dico dict);

/**
 * Prends un mot sous forme de dictionnaire et renvoie le groupe du verbe si s'en est un
 * @param v
 * @return
 */
int est_verbe(dico v);

void conjug_verbe(char* verbe, enum PERS sujet, int groupe);
#endif //ifndef CONJUGAISONH
