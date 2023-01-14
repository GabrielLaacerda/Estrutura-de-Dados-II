#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED

#define L 10
#define C 10

typedef struct Grafo
{
    int mat[L][C];
    int vertices[L];
    int k;

} Grafo;

void preencherMatriz(Grafo *g);
void preencherVetor(Grafo *g);
int adicionarVertice(Grafo *g, int vertice);
int existe(Grafo *g, int a1, int a2);
int adicionarAresta(Grafo *g, int a1, int a2);
void removerAresta(Grafo *g,int a1, int a2);
void removerVertice(Grafo *g,int vertice);
void printarMatriz(Grafo g);
int menu();
void printarVertices(Grafo g);
void printarArestas(Grafo g);
void verticesAdjacentes(Grafo g, int a1);



#endif // GRAFO_H_INCLUDED
