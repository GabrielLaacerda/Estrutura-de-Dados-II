#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED

typedef struct celula
{
    int num;
    struct celula *prox;
    struct celula *ant;

} celula;

int menu();
void preencherVetor(celula **inicio, int valor);
void heap(celula **inicio);
void listar(celula *inicio);
int minimo_maximo(celula **inicio);

#endif // HEAP_H_INCLUDED
