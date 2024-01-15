#include <stdio.h>
#include <stdbool.h>

void conju_grp1 (v,s,g) {
    assert(g)==1;
    while(v[i]=!'\0')
    {i++;}
    switch(s) {
        case(JE):
            v[i-1]='\0';
        break;
        case(TU):
            v[i-1]='s';
        break;
        case(PERS_SING):
            v[i-1]='e';
        break;
        case(NOUS):
            v[i-2]='o';
            v[i-1]='n';
            v[i]='s';
        break;
        case(VOUS):
            v[i-1]='z';
        break;
        case(PERS_PLUR):
            v[i]='n';
            v[i+1]='t';
        break;
    }
}


