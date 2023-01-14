#include <stdio.h>
#include <stdlib.h>

void preencherMatriz(int mochilaValores[][6])
{
    for(int i=0; i<5; i++)
    {
        for(int k=0; k<6; k++)
        {
            if(i == 4 || k == 0)
            {
                mochilaValores[i][k] = 0;
            }
            else
            {
                mochilaValores[i][k] = -1;
            }
        }
    }

}

int Mochila(int mochilaValores[][6],int valor[],int peso[])
{
    int a,b;

    for(int k=1; k<6; k++)
    {
        for(int i=3; i>=0; i--)
        {
            if(peso[i] > k)
            {
                mochilaValores[i][k] = 0;
            }

            else
            {
                a = valor[i] + mochilaValores[i+1][k-peso[i]];
                b = mochilaValores[i+1][k];

                if(a > b)
                {
                    mochilaValores[i][k] = a;

                }
                else
                {
                    mochilaValores[i][k] = b;
                }
            }

        }
    }

    return mochilaValores[0][5];
}

int main()
{
    int total;
    int peso[] = {4,2,1,3};
    int valor[] = {500,400,300,450};
    int mochilaValores[5][6];

    preencherMatriz(mochilaValores);
    total = Mochila(mochilaValores,valor,peso);

    printf("Valores Intermediarios:\n");

    for(int i=0;i<5;i++){
        for(int k=0;k<6;k++){
            printf("%d ",mochilaValores[i][k]);
        }
        printf("\n");
    }

    printf("\nTotal = %d\n",total);

    return 0;
}
