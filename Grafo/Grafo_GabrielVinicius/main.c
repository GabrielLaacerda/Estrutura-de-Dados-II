#include <stdio.h>
#include <stdlib.h>
#include "Grafo.h"

int main()
{
    Grafo g;
    g.k = 0;

    preencherMatriz(&g);
    preencherVetor(&g);

    int vertice;
    int a1, a2,exist;

    int op;

    do
    {
        op = menu();

        switch(op)
        {

        case 1:

            printf("Digite um vertice: ");
            scanf("%d",&vertice);
            adicionarVertice(&g,vertice);
            break;

        case 2:

            printf("Digite a primeira aresta: ");
            scanf("%d",&a1);
            printf("Digite a primeira aresta: ");
            scanf("%d",&a2);

            exist = existe(&g,a1,a2);

            if(exist == 0)
            {
                printf("\nNão foi possivel adicionar aresta\n\n");
                break;
            }
            else
            {
                adicionarAresta(&g,a1,a2);
            }
            break;

        case 3:
            printf("Digite o primeiro vertice: ");
            scanf("%d",&a1);
            printf("Digite o segundo vertice: ");
            scanf("%d",&a2);

            removerAresta(&g,a1,a2);
            break;

        case 4:
            printf("Digite o vertice: ");
            scanf("%d",&a1);

            removerVertice(&g,a1);
            break;

        case 5:
            printarMatriz(g);
            break;

        case 6:
            printarVertices(g);
            break;

        case 7:
            printarArestas(g);
            break;

        case 8:
            printf("\nDigite o numero do vertice: ");
            scanf("%d",&a1);
            verticesAdjacentes(g,a1);
        }
    }
    while(op!=0);

    return 0;
}
