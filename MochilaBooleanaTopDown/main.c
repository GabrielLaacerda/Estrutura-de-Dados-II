#include <stdio.h>
#include <stdlib.h>
#define max(A,B) ((A>B) ? (A):(B))

int Mochila(int k,int mochilaValores[],int valor[],int pesos[],int i, int pr)
{
    if(i == 4 || pr == 0)
    {
        return 0;
    }
    else if(pesos[i] > pr)
    {
        Mochila(k,mochilaValores,valor,pesos,i+1, pr);
    }
    else
    {
        int a = valor[i]+Mochila(k,mochilaValores,valor,pesos,i+1, pr - pesos[i]);
        mochilaValores[k++] = a;
        int b = Mochila(k,mochilaValores,valor,pesos,i+1, pr);

        if(a > b)
        {
           return a;
        }
        else{
            return b;
        }
    }

    return 0;
}

int main()
{
    int total;
    int peso[] = {4,2,1,3};
    int valor[] = {500,400,300,450};
    int mochilaValores[4];
    int k = 0;

   total = Mochila(k,mochilaValores,valor,peso,0,5);

   printf("Valores intermediarios:");

   for(int i=0;i<4;i++){
        printf("%d ",mochilaValores[i]);
   }
   printf("\nTotal: %d\n",total);

    return 0;
}
