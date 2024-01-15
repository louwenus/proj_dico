#include <stdbool.h>

#ifndef DIC_H
#define DIC_H



struct lettre_s {
	bool terminal;
	struct lettre_s* succ[26];
    char type[10];
};
typedef struct lettre_s* dico;

/**
 * Crée un dictionnaire en initialisant ses valeurs de base ; lettre = true, et tous ses successeurs sont à false.
 */
dico dictionnaire_vide(void);

/**
 * Rajoute un mot dans le dictionnaire
 * @param dic
 * @param mot
 */
void ajouter_mot(dico dic, char* mot);

/**
 * Recherche un mot dans le dictionnaire, et renvoie son sous-dictionnaire associé, si il éxiste, sinon, renvoie NULL
 * @param dic Dictionnaire dans lequel chercher
 * @param mot Mot a chercher
 */
dico chercher_mot(dico dic, char* mot);

/**
 * Supprime le dictionnaire
 * @param dic
 */
void supprimer_dictionnaire(dico dic);

#endif
