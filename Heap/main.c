#include <stdio.h>
#include <stdlib.h>
#include "Heap.h"


int main()
{
    int v,op;

    celula *inicio;
    inicio = NULL;

    int flag = 0;

    do{
        op = menu();

        switch(op){

        case 0:
            break;

        case 1:
            printf("Digite um numero: ");
            scanf("%d",&v);
            preencherVetor(&inicio,v);

            break;

        case 2:
            listar(inicio);
            break;

        case 3:

            flag = minimo_maximo(&inicio);

            if(flag == 1){
                printf("Heap Minimo\n");
            }
            else{
                printf("Heap Maximo\n");
            }

            break;
        }
    }
    while(op!=0);


    return 0;
}
