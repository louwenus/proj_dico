#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "dic.h"

dico creer_dico()
{
	dico tmp = (dico)malloc(sizeof(struct lettre_s));
	tmp->lettre = false;
	for(int i=0; i<256; i++)
	{
		(tmp->succ)[i] = NULL;
	}
	return tmp;
}

void ajouter_mot(dico dic, char* mot)  // Non fini. Problemes avec le NULL, possibles erreurs. normalement creer_dico() marche. Désolé <3
{
	dico tmp = dic;
	int i = 0;
	while(mot[i] != '\0')
	{
		int succ_a_changer = mot[i] - 'a';  //ici on obtient un int de 0 a 25
		if((tmp->succ)[succ_a_changer]->lettre == true)
		{
			tmp = (tmp->succ)[succ_a_changer];
		}
		else
		{
			(tmp->succ)[succ_a_changer] = creer_dico();
			tmp = (tmp->succ)[succ_a_changer];
		}
	}
	tmp->succ[26] = true;
}
