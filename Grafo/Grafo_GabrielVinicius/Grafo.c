#include <stdio.h>
#include <stdlib.h>
#include "Grafo.h"
#define L 10
#define C 10


void preencherMatriz(Grafo *g)
{
    for(int i=0; i<L; i++)
    {
        for(int j=0; j<C; j++)
        {
            g->mat[i][j] = 0;
        }
    }
}
void preencherVetor(Grafo *g)
{
    for(int i=0; i<L; i++)
    {
        g->vertices[i] = -1;
    }
}

int adicionarVertice(Grafo *g, int vertice)
{
    if(g->k >= L)
    {
        printf("\nNão é possivel adicionar mais arestas\n\n");
        return 0;
    }

    if(vertice > L-1 || vertice < 0)
    {
        printf("\nNão foi possivel adicionar o vertice: %d\n\n",vertice);
        return 0;
    }

    for(int i=0; i<g->k; i++)
    {
        if(g->vertices[i] == vertice)
        {
            printf("\nVertice ja existe\n\n");
            return 0;
        }
    }

    g->vertices[g->k] = vertice;
    g->k += 1;

    return 1;
}

int existe(Grafo *g, int a1, int a2)
{
    int flag1 = 0;
    int flag2 = 0;

    for(int i=0; i<g->k; i++)
    {
        if(g->vertices[i] == a1)
        {
            flag1 = 1;
        }
        if(g->vertices[i] == a2)
        {
            flag2 = 1;
        }
    }

    if(flag1 == 1 && flag2 == 1)
    {
        if(g->mat[a1][a2] == 1 || g->mat[a2][a1] == 1)
        {
            printf("\nAresta ja existente ");
            return 0;
        }
        return 1;
    }
    else
    {
        return 0;
    }

    return 0;
}

int adicionarAresta(Grafo *g, int a1, int a2)
{
    g->mat[a1][a2] = 1;
}

void removerAresta(Grafo *g,int a1, int a2)
{
    if(g->mat[a1][a2] == 1)
    {
        g->mat[a1][a2] = 0;
    }
    else
    {
        printf("\nAresta não encontrada\n\n");
    }
}

void removerVertice(Grafo *g,int vertice)
{
    int flag = 0;

    for(int i=0; i<g->k; i++)
    {
        if(g->vertices[i] == vertice)
        {
            flag = 1;
        }
    }

    if(flag == 0)
    {
        printf("\nVertice nao encontrado\n\n");
    }
    else
    {
        for(int n=0; n<g->k; n++)
        {
            if(g->vertices[n] == vertice)
            {
                g->vertices[n] = -1;
            }
        }

        for(int i=0; i<L; i++)
        {
            for(int j=0; j<C; j++)
            {
                if(g->mat[vertice][j] == 1 || g->mat[i][vertice] == 1 )
                {
                    g->mat[vertice][j]  = g->mat[i][vertice] = 0;
                }
            }
        }
    }
}

void printarMatriz(Grafo g)
{
    printf("\n");

    for(int i=0; i<L; i++)
    {
        for(int j=0; j<C; j++)
        {
            printf("%d ",g.mat[i][j]);
        }
        printf("\n");
    }

    printf("\n");
}

void printarVertices(Grafo g)
{
    printf("\nVertices: ");
    for(int i=0; i<g.k; i++)
    {
        if(g.vertices[i] != -1)
        {
            printf("%d. ",g.vertices[i]);
        }
    }
    printf("\n\n");
}

void printarArestas(Grafo g)
{

    printf("\nArestas:\n\n");

    for(int i=0; i<L; i++)
    {
        for(int j=0; j<C; j++)
        {
            if(g.mat[i][j] == 1)
            {
                printf("Vertice[%d] --> Vertice[%d] ou Vertice[%d] --> Vertice[%d]\n",i,j,j,i);
            }
        }
    }
    printf("\n");
}

void verticesAdjacentes(Grafo g, int a1)
{
    int aux[L];
    int n = 0,flag = 0;

    printf("Vertice: %d\n\n",a1);
    printf("Adjacentes:\n");

    for(int i=0; i<C; i++)
    {
        if(g.mat[a1][i] == 1)
        {
            aux[n] = i;
            n++;
        }
    }

    for(int i=0; i<L; i++)
    {
        if(g.mat[i][a1] == 1)
        {
            flag = 0;

            for(int l=0;l<n;l++){
                if(aux[l] == i){
                    flag = 1;
                }
            }

            if(flag == 0){
                aux[n] = i;
                n++;
            }
        }
    }
    for(int i=0;i<n;i++){
        printf("Vertice: %d\n",aux[i]);
    }
    printf("\n");
}

int menu()
{
    int op;
    printf("1 - Adicionar Vertice (1 a 10)\n");
    printf("2 - Adicionar Aresta (1 a 10)\n");
    printf("3 - Remover Aresta\n");
    printf("4 - Remover Vertice\n");
    printf("5 - Ver Grafo(Formato de Matriz)\n");
    printf("6 - Imprimir Lista de Vertices\n");
    printf("7 - Imprimir Lista de Arestas\n");
    printf("8 - Imprimir Vertices adjacentes a ""V""\n");
    printf("0 - Sair\n");
    scanf("%d",&op);

    return op;
}
