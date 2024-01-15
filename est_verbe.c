#include <stdio.h>

int est_verbe(v) {
    while (v.type[1]>='a')
        {
            if (v.type[1]=='f')
            {    
               return 2;
            }
            else
            {
               return 1;
            }
        }
}
