#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
int id_sujet(char* texte, int ind_verbe)
{
   int ind_sujet = ind_verbe -2;
   while(ind_sujet >=0 && texte[ind_sujet] != ' ')
   {
    ind_sujet --;
   }

   if((texte[ind_sujet] == 'j' || texte[ind_sujet] == 'J') && texte[ind_sujet + 1] == 'e')
   {
    return 0;
   }

   if((texte[ind_sujet] == 't' || texte[ind_sujet] == 'T') && texte[ind_sujet + 1] == 'u')
   {
    return 1;
   }

   if((texte[ind_sujet] == 'o' || texte[ind_sujet] == 'O') && texte[ind_sujet + 1] == 'n')
   {
    return 3;
   }

   if((texte[ind_sujet] == 'i' || texte[ind_sujet] == 'I') && texte[ind_sujet + 1] == 'l' && texte[ind_sujet + 2] == ' ')
   {
    return 3;
   }
}