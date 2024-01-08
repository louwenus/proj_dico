#include <stdbool.h>

#ifndef DIC_H
#define DIC_H

struct lettre_s {
	bool lettre;
	struct lettre_s* succ[256];
};
typedef struct lettre_s* dico;

/*
 * Crée un dictionnaire en initialisant ses valeurs de base ; lettre = true, et tous ses successeurs sont à false.
 */
dico creer_dico();

/*
 * Ajoute un mot au dictionnaire en créant les structures nécessaires.
 * Entrees : dic, dictionnaire ENTIER.
 * 			 mot, chaine de caractère, mot à ajouter.
 */
void ajouter_mot(dico dic, char* mot);

#endif
