#ifndef CALCULADORAPOLONESA_H_INCLUDED
#define CALCULADORAPOLONESA_H_INCLUDED

//Tad Pilha contendo o valor, ponteiro prox e ant
typedef struct Pilha
{
    int valor;
    struct Pilha *prox;
    struct Pilha *ant;

} pilhaCalc;

//Protótipos das Funções
void criar_pilha(pilhaCalc **inicio);
void remove_pilha(pilhaCalc **inicio);
void inserir_pilha(pilhaCalc **inicio, int val);
void listar(pilhaCalc **inicio);
void somar(pilhaCalc **inicio);
void subtrair(pilhaCalc **inicio);
void multiplicar(pilhaCalc **inicio);
void dividir(pilhaCalc **inicio);
int quant(pilhaCalc **inicio);
int resultado(pilhaCalc **inicio);



#endif // CALCULADORAPOLONESA_H_INCLUDED
