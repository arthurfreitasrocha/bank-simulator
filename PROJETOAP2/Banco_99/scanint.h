#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
int scanint(char *conteudo)
{
    gets(conteudo);

    int i=0, cont=0, num=2, teste, letra;

    while(i < 1)
    {
        letra = atoi(conteudo);
        teste = letra;

        if((teste != 0) && (teste != 1) && (teste != 2) && (teste != 3) && (teste != 4) &&
        (teste != 5)&& (teste != 6) && (teste != 7) && (teste != 8) && (teste != 9))
        {
             gets(conteudo);
        }
        else
        {
            cont++; i++;
        }

    }


    if(cont >= 1)
    {
        num = atoi(conteudo);
        return num;

    }
}*/

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
