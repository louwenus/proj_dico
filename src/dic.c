#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "dic.h"

dico dictionnaire_vide()
{
	dico tmp = (dico)malloc(sizeof(struct lettre_s));
	tmp->lettre = false;
	for(int i=0; i<26; i++)
	{
		(tmp->succ)[i] = NULL;
	}
	return tmp;
}

void ajouter_mot(dico dic, char* mot)  // Non fini. Problemes avec le NULL, possibles erreurs. normalement dictionnaire_vide() marche. Désolé <3
{
	dico tmp = dic;
	int i = 0;
	while(mot[i] != '\0')
	{
		int succ_a_changer = mot[i]-'a';
		if((tmp->succ)[succ_a_changer] != NULL)
		{
			tmp = (tmp->succ)[succ_a_changer];
		}
		else
		{
			(tmp->succ)[succ_a_changer] = dictionnaire_vide();
			tmp = (tmp->succ)[succ_a_changer];
		}
	i++;
	}
	tmp->lettre = true;
}

dico chercher(dico dic,char* mot){
	dico tmp = dic;
	int i = 0;
	while(mot[i] != '\0')
	{
		int succ = mot[i]-'a';
		if((tmp->succ)[succ] != NULL)
		{
			tmp = (tmp->succ)[succ];
		}
		else
		{
			return NULL;
		}
	i++;
	}
	return tmp;
}
