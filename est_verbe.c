#include <stdio.h>
#include "fr-reforme1990_court_sans.dic"
#include <stdbool.h>

void est_verbe(v) {
    if (v[1]=='f' && v[2]==0)
    {    
        v.type =2;
    }
    else
    {
        v.type=1;
    }
}
