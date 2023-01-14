#include "Heap.h"
#include <stdio.h>
#include <stdlib.h>

int menu()
{
    int op;

    printf("1 - Adicionar Elemento\n");
    printf("2 - Printar Heap Maximo\n");
    printf("3 - Maximo ou Minimo\n");
    printf("0 - Sair\n");

    scanf("%d",&op);

    return op;
}

void heapMaximo(celula **inicio)
{
    celula *aux,*aux2;
    aux = *inicio;
    aux2 = *inicio;

    int troca;
    int i = 0;
    int j = 0;

    while(aux->prox != NULL)
    {
        aux = aux->prox;
        i++;
    }

    i = (i-1)/2;

    while(j != i)
    {
        aux2 = aux2->prox;
        j++;
    }

    while(aux->num > aux2->num && aux != *inicio)
    {
        troca = aux->num;
        aux->num = aux2->num;
        aux2->num = troca;

        aux = aux2;
        aux2 = *inicio;

        j = 0;
        i = (i-1)/2;

        while(j != i)
        {
            aux2 = aux2->prox;
            j++;
        }

        if(aux == *inicio)
        {
            break;
        }

    }
}

void preencherVetor(celula **inicio, int valor)
{
    celula *p;

    p = (celula *)malloc(sizeof(celula));

    if(!p)
    {
        printf("\nSem Memoria\n");
    }

    p->num = valor;

    if(*inicio == NULL)
    {
        p->prox = NULL;
        p->ant = NULL;
        *inicio = p;

    }
    else
    {
        celula *aux;
        aux = *inicio;

        while(aux->prox!=NULL)
        {
            aux = aux->prox;
        }

        aux->prox = p;
        p->ant = aux;
        p->prox = NULL;

        heapMaximo(*&inicio);

    }
}

int minimo_maximo(celula **inicio)
{
    celula *aux,*aux2;
    aux = *inicio;
    aux2 = *inicio;

    int flag = 0;
    int i = 0;
    int j = 0;

    while(aux->prox != NULL)
    {
        aux = aux->prox;
        i++;
    }

    i = (i-1)/2;

    while(j != i)
    {
        aux2 = aux2->prox;
        j++;
    }

    while(aux != *inicio){

        aux = aux2;
        aux2 = *inicio;

        j = 0;
        i = (i-1)/2;

        while(j != i)
        {
            aux2 = aux2->prox;
            j++;
        }

        if(aux->num > aux2->num )
        {
            flag = 1;
        }

        if(aux == *inicio)
        {
            break;
        }
    }

    return flag;
}

void listar(celula *inicio)
{
    if(inicio == NULL)
    {
        printf("\nLista Vazia\n");

    }
    else
    {
        celula *p;
        p = inicio;

        printf("Heap: \n");

        while(p)
        {
            printf("%d ",p->num);
            p = p->prox;

        }
    }
    printf("\n");

}

