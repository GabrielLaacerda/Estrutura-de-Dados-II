#include <stdio.h>
#include <stdlib.h>
#include "Uri_1340.h"

void iniciarFila(tipoFila *fila)
{
    fila->primeiro = NULL;
    fila->ultimo = NULL;
}

void iniciarPilha(tipoPilha *pilha)
{
    pilha->topo = NULL;
}

void pushFila(tipoFila *fila, int x)
{
    TipoFila *aux;

    aux = (TipoFila *)malloc(sizeof(TipoFila));

    if (aux == NULL)
        exit(1);

    if (fila->primeiro)
    {
        fila->ultimo->prox = aux;
        aux->prox = NULL;
    }
    else
        fila->primeiro = aux;

    fila->ultimo = aux;
    aux->valor = x;
}

void pushPilha(tipoPilha *pilha, int x)
{

    Pilha *aux;

    aux = (Pilha *)malloc(sizeof(Pilha));

    if (aux == NULL)
        exit(1);

    aux->prox = pilha->topo;
    pilha->topo = aux;
    aux->valor = x;
}

void pushHeap(_Heap *filaP, int prioridade, int id)
{

    if (filaP == NULL)
        exit(1);

    if (filaP->qtd == 1000)
        exit(1);

    filaP->valors[filaP->qtd].valor = id;
    filaP->valors[filaP->qtd].prioridade = prioridade;
    balanceiaInsercao(filaP, filaP->qtd);
    ++filaP->qtd;
}

void popFila(tipoFila *fila)
{
    TipoFila *aux;

    if (fila->primeiro)
    {
        if (fila->primeiro->prox)
        {
            aux = fila->primeiro;
            fila->primeiro = fila->primeiro->prox;
            free(aux);

            return;
        }
        else
        {
            aux = fila->primeiro;
            fila->primeiro = NULL;
            fila->ultimo = NULL;
            free(aux);
            
            return;
        }
    }
    else
        return;
}

void popPilha(tipoPilha *pilha)
{
    Pilha *aux;

    aux = pilha->topo;

    if (aux)
    {
        pilha->topo = aux->prox;
        free(aux);
    }
}

void popHeap(_Heap *filaP)
{
    if (filaP == NULL)
        exit(1);

    if (filaP->qtd == 0)
        exit(1);

    --filaP->qtd;
    filaP->valors[0] = filaP->valors[filaP->qtd];
    balanceiaRemocao(filaP, 0);
}

int frontFila(tipoFila *fila)
{
    return fila->primeiro->valor;
}

int top(tipoPilha *pilha)
{
    return pilha->topo->valor;
}

void balanceiaInsercao(_Heap *filaP, int filho)
{
    int pai;

    Heap tmp;

    pai = (filho - 1) / 2;

    while ((filho > 0) && (filaP->valors[pai].prioridade <= filaP->valors[filho].prioridade))
    {

        tmp = filaP->valors[filho];
        filaP->valors[filho] = filaP->valors[pai];
        filaP->valors[pai] = tmp;

        filho = pai;
        pai = (pai - 1) / 2;
    }
}

int topHeap(_Heap *filaP)
{
    if (filaP == NULL || filaP->qtd == 0)
        return 0;

    return filaP->valors[0].valor;
}

_Heap *priotiry()
{
    _Heap *filaP;

    filaP = (_Heap *)malloc(sizeof(_Heap));

    if (filaP){
        filaP->qtd = 0;
    }

    return filaP;
}

void balanceiaRemocao(_Heap *filaP, int pai)
{

    int filho;
    Heap tmp;

    filho = 2 * pai + 1;

    while (filho < filaP->qtd)
    {

        if (filho < filaP->qtd - 1)
            if (filaP->valors[filho].prioridade < filaP->valors[filho + 1].prioridade)
                ++filho;

        if (filaP->valors[pai].prioridade >= filaP->valors[filho].prioridade)
            break;

        tmp = filaP->valors[pai];
        filaP->valors[pai] = filaP->valors[filho];
        filaP->valors[filho] = tmp;

        pai = filho;
        filho = 2 * pai + 1;
    }
}
