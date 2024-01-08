#include <stdio.h>
#include <stdlib.h>
#include "dic.h"

int main(int argc, char* argv[])
{
	if(argc == 1)
	{
		exit(EXIT_FAILURE);
	}
	
	dico dic = dictionnaire_vide();
    fopen("fr-reforme1990_court_sans.dic", "r");
	
	exit(EXIT_SUCCESS);
}
