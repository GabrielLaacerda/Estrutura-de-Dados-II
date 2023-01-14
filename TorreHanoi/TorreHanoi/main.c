#include <math.h>
#include <stdlib.h>
#include <stdio.h>

void calcula(int v, int j,int n,int *total,int vetor[])
{
    if(j == n) return;

    if(vetor[j] == 0)
    {
        vetor[j] = v;
        (*total)++;

        return calcula(v+1,j,n,total,vetor);
    }
    for(int i = 0; i <= j; i++)
    {
        int raiz = (int)sqrt(vetor[i] + v);
        if((raiz * raiz) == (vetor[i] + v))
        {
            vetor[i] = v;
            (*total)++;

            return calcula(v+1,j,n,total,vetor);
        }
    }
    calcula(v,j+1,n,total,vetor);
}

void preencheVetor(int vetor[]){

    for(int i=0; i<=50; i++){
            vetor[i] = 0;
        }
}

int main(){

    int quantCasos,n;
    int total;
    int vetor[51];
    int j=0;

    scanf("%d",&quantCasos);

    for (int i=0; i<quantCasos; i++){

        scanf("%d",&n);

        preencheVetor(vetor);
        total = 0;
        calcula(1, j, n,&total,vetor);

        printf("Total: %d\n",total);

    }
    return 0;
}
