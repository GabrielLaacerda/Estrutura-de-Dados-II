#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CalculadoraPolonesa.h"

//Criação da Pilha
void criar_pilha(pilhaCalc **inicio)
{
    *inicio = NULL;
}

//Função desimpilha
void remove_pilha(pilhaCalc **inicio)
{
    pilhaCalc *p,*p2;

    if(*inicio == NULL)
    {
        printf("\nCalculadora não possui operandos para efetuar essa operacao\n");
        return;

    }
    else
    {
        //Percorremos a pilha até o final com dois ponteiros, um sempre andando a frente do outro
        //Ao final do loop, apontamos o ponteiro que esta uma posiçao atras para NULL e liberamos a memoria do ponteiro
        //que esta a frente
        p = (*inicio);
        p2 = &p;

        if(p->prox == NULL)
        {
            free(p);
            criar_pilha(*(&inicio));
        }
        else
        {

            while(p->prox != NULL)
            {
                p2 = p;
                p = p->prox;
            }

            p2->prox = NULL;
            free(p);
        }
    }
}

//Funçao empilha
void inserir_pilha(pilhaCalc **inicio, int val)
{
    pilhaCalc *p;

    p = (pilhaCalc *)malloc(sizeof(pilhaCalc));

    if(!p)
    {
        printf("\nSem Memoria\n");

    }

    p->valor = val;
    p->ant = NULL;

    //Inserção do primeiro elemento
    if(*inicio == NULL)
    {
        *inicio = p;
        p->prox = NULL;

    }
    else
    {
        //Percorremos a pilha e inserimos no final
        pilhaCalc *aux;
        aux = *inicio;

        while(aux->prox != NULL)
        {
            aux = aux->prox;
        }

        aux->prox = p;
        p->ant = aux;
        p->prox = NULL;

    }


}

//Funçao Listar para printar os valores presentes na calculadora
void listar(pilhaCalc **inicio)
{
    if(inicio == NULL)
    {
        printf("\nLista Vazia\n");

    }
    else
    {
        pilhaCalc *p;
        p = *inicio;

        printf("\nValores presentes na calculadora: ");

        while(p != NULL)
        {
            printf("[%d] ",p->valor);
            p = p->prox;

        }
    }
    printf("\n");

}

//Soma elementos da pilha
void somar(pilhaCalc **inicio)
{

    if(*inicio == NULL)
    {
        printf("\nCalculadora não possui operandos para efetuar essa operacao\n");

    }
    else
    {
        //Fazemos a soma com os dois ultimos elementos digitados, sendo assim, percorremos a pilha até o final
        //E somamos o ultimo numero com o penultimo
        pilhaCalc *p,*p2;
        p = *inicio;
        p2 = p;

        int valor;

        while(p->prox != NULL)
        {
            p2 = p;
            p = p->prox;
        }

        valor = p2->valor + p->valor;

        //Seguindo a definiçao da calculadora polonesa, removemos esses dois valores somados
        //E empilhamos o valor resultado
        remove_pilha(*(&inicio));
        remove_pilha(*(&inicio));

        inserir_pilha(*(&inicio),valor);
    }
}

//Funçao de subtração
void subtrair(pilhaCalc **inicio)
{

    if(*inicio == NULL)
    {
        printf("\nCalculadora não possui operandos para efetuar essa operacao\n");

    }
    else
    {
        //Percorremos a pilha até o final e como a subtraçao depende de precedencia
        //SUbtraimos o penultimo - ultimo
        pilhaCalc *p,*p2;
        p = *inicio;
        p2 = p;

        int valor;

        while(p->prox != NULL)
        {
            p2 = p;
            p = p->prox;
        }

        valor = p2->valor - p->valor;

        //Seguindo a definição, desimpilhamos os dois valores subtraidos
        //e empilhamos o valor resultado
        remove_pilha(*(&inicio));
        remove_pilha(*(&inicio));

        inserir_pilha(*(&inicio),valor);
    }

}

void multiplicar(pilhaCalc **inicio)
{

    if(*inicio == NULL)
    {
        printf("\nCalculadora não possui operandos para efetuar essa operacao\n");
    }
    else
    {

        //Percorremos até o final da pilha e multiplicamos os dois ultimos
        pilhaCalc *p,*p2;
        p = *inicio;
        p2 = p;

        int valor;

        while(p->prox != NULL)
        {
            p2 = p;
            p = p->prox;
        }

        valor = p2->valor * p->valor;

        //Seguindo a definição, desimpilhamos os dois valores multiplicados
        //e empilhamos o valor resultado
        remove_pilha(*(&inicio));
        remove_pilha(*(&inicio));

        inserir_pilha(*(&inicio),valor);
    }

}

void dividir(pilhaCalc **inicio)
{

    if(*inicio == NULL)
    {
        printf("\nCalculadora não possui operandos para efetuar essa operacao\n");
    }
    else
    {
        //Percorremos a pilha e dividimos o penultimo pelo ultimo
        //Pegando, como pedido no exercicio, a parte inteira do resultado
        pilhaCalc *p,*p2;
        p = *inicio;
        p2 = p;

        int valor;

        while(p->prox != NULL)
        {
            p2 = p;
            p = p->prox;
        }

        valor = p2->valor / p->valor;

        //Seguindo a definição, desimpilhamos os dois valores divididos
        //e empilhamos o valor resultado
        remove_pilha(*(&inicio));
        remove_pilha(*(&inicio));

        inserir_pilha(*(&inicio),valor);
    }
}

//Função para pegar a quantidade de numeros presentes na calculadora
int quant(pilhaCalc **inicio)
{
    int tam = 0;
    pilhaCalc *p;
    p = *inicio;

    while(p != NULL)
    {
        p = p->prox;
        tam++;
    }

    return tam;
}

//Pegamos o valor restante na pilha, que seria o próprio resultado
int resultado(pilhaCalc **inicio)
{

    pilhaCalc *p;
    p = *inicio;

    return p->valor;
}
