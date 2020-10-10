#include <stdio.h>
#include <stdlib.h>

int scanint(char let)
{
    int letra=-1, i=0, num=48;

    for(i=0; i<1; i++)
    {
        if((letra >= 48) && (letra <= 57))
            break;

        //printf("%d", letra = getchar());

        letra = getchar();
        getchar();

        if((letra < 48) || (letra > 57))
        {
            i--;
        }
        else
        {
            i=1;
        }

    }

    for(i=0; i < 10; i++)
    {
        if(letra == num)
        {
            letra = i;
            i = 10;
        }
        else
            num++;
    }

    return letra;
}
