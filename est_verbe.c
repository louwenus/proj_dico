#include <stdio.h>
#include "fr-reforme1990_court_sans.dic"
#include <stdbool.h>

int est_verbe(v) {
    if (v.type[1]=='f')
    {    
       return 2;
    }
    else
    {
       return 1;
    }
}
