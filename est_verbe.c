#include <stdio.h>
#include "fr-reforme1990_court_sans.dic"
#include <stdbool.h>

void est_verbe(v) {
    if (v.type[1]=='a'&& v[2]==0 )
    {
        v.type =1;
    }
    if (v[1]=='f' && v[2]==0)
    {    
        v.type =2;
    }    
}
