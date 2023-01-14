#ifndef URI_1340_H_INCLUDED
#define URI_1340_H_INCLUDED

typedef struct TipoFila
{
    int valor;
    struct TipoFila *prox;

} TipoFila;

typedef struct tipoFila
{
    TipoFila *primeiro;
    TipoFila *ultimo;

} tipoFila;


typedef struct Pilha
{
    int valor;
    struct Pilha *prox;

} Pilha;

typedef struct tipoPilha
{
    Pilha *topo;

} tipoPilha;


typedef struct Heap
{
    int valor;
    int prioridade;

} Heap;

typedef struct _Heap
{
    int qtd;
    struct Heap valors[1000];

} _Heap;

void iniciarFila(tipoFila *);
void pushFila(tipoFila *, int);
int frontFila(tipoFila *);
void popFila(tipoFila *);
void iniciarPilha(tipoPilha *);
void pushPilha(tipoPilha *, int);
void popPilha(tipoPilha *);
int top(tipoPilha *);
_Heap* priotiry();
void pushHeap(_Heap *, int, int );
void popHeap(_Heap *);
int topHeap(_Heap *);
void balanceiaRemocao(_Heap *, int);
void balanceiaInsercao(_Heap *, int);


#endif // URI_1340_H_INCLUDED
