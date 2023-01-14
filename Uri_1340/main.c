#include <stdio.h>
#include <stdlib.h>
#include "Uri_1340.h"


void main ()
{
    int n;

    while (scanf("%d", &n) != EOF)
    {
        int valor;
        int op, i;
        int queueN, stackN, Heap;

        _Heap *prioridade = priotiry();
        tipoFila fila;
        tipoPilha pilha;

        //Inicializando estruturas
        iniciarFila(&fila);
        iniciarPilha(&pilha);

        queueN = 1;
        stackN = 1;
        Heap = 1;

        for (i = 0; i < n; ++i)
        {
            scanf("%d %d", &op, &valor);

            if (op == 1)
            {
                //Inserindo elementos em todas as estruturas
                pushHeap(prioridade, valor, valor);
                pushPilha(&pilha, valor);
                pushFila(&fila, valor);

            }
            else
            {
                 //Removendo elementos em todas as estruturas caso possivel
                if (top(&pilha) != valor)
                    stackN = 0;
                else
                    popPilha(&pilha);

                if (frontFila(&fila) != valor)
                    queueN = 0;
                else
                    popFila(&fila);

                if (topHeap(prioridade) != valor)
                    Heap = 0;
                else
                    popHeap(prioridade);

            }

        }

        //Comparações para imprimir
        if (!stackN && !queueN && !Heap){
            printf("impossible\n");
        }
        else if (stackN && Heap){
            printf("not sure\n");
        }
        else if (stackN && queueN){
            printf("not sure\n");
        }
        else if (Heap && queueN){
            printf("not sure\n");
        }
        else if (Heap){
            printf("priority queue\n");
        }
        else if (queueN){
            printf("queue\n");
        }
        else if (stackN){
            printf("stack\n");
        }

    }

}

