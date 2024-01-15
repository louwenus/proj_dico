#include <stdio.h>
#include <stdbool.h>

void conju_grp2 (v,s,g) {
    assert(g)==2;
    while(v[i]=!'\0')
    {i++;}
    switch(s) {
        case(JE):
            v[i-2]='i';
            v[i-1]='s';
        break;
        case(TU):
            v[i-2]='i';
            v[i-1]='s';
        break;
        case(PERS_SING):
            v[i-2]='i';
            v[i-1]='t';
        break;
        case(NOUS):
            v[i-2]='i';
            v[i-1]='s';
            v[i]='s';
            v[i+1]='o';
            v[i+2]='n';
            v[i+3]='s';
        break;
        case(VOUS):
            v[i-2]='i';
            v[i-1]='s';
            v[i]='s';
            v[i+1]='e';
            v[i+2]='z';
        break;
        case(PERS_PLUR):
            v[i-2]='i';
            v[i-1]='s';
            v[i]='s';
            v[i+1]='e';
            v[i+2]='n';
            v[i+3]='t';
        break;
    }
}