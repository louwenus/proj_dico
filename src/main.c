#include <stdio.h>
#include <stdlib.h>
#include "dic.h"

int main(int argc, char* argv[])
{
	if(argc != 1)
	{
		exit(EXIT_FAILURE);
	}
	
	dico dic = creer_dico();
	
	exit(EXIT_SUCCESS);
}
