#include <stdio.h>
#include <stdlib.h>

int Mochila(int n)
{
    int a,b,j=0,qp,max;
tempos
quantidades
    while(j<n)
    {
        scanf("%d",&qp);
        scanf("%d",&max);

        int mochilaP[qp+1][max+1];
        preencherMatriz(mochilaP,qp+1,max+1);

        for(int k=1; k<max+1; k++)
        {
            for(int i=qp; i>=0; i--)
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
        j++;

        for(int cont=0;cont<qp;cont++){
            for(int cont2=0;cont2<max+1;cont2++){
                printf("%d ",mochilaP[cont][cont2]);
        }
           printf("\n");
        }
    }

}

void preencherMatriz(int mochilaP[linhas][colunas],int linhas,int colunas)
{
    for(int i=0; i<linhas; i++)
    {
        for(int k=0; k<colunas; k++)
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

int main()
{
    int total;
    int n, quantPedidos,numP;

    printf("Casos de teste: ");
    scanf("%d",&n);

    if(n == 0)
    {
        return 0;
    }

    Mochila(n);

    return 0;
}
