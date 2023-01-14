#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CalculadoraPolonesa.h"

//----------------Instruções para uso da Calculadora---------------//
//-> Para digitar um numero tecle 'E', digite um caracter, e se quiser inserir mais valores a direita, basta digitar o valor e enter
//Ex: ->E
//    ->1
//    ->0
//    ->E (Para pararmos a inserção desse valor, teclamos novamente a tecla 'E')
//Resultado: Insere o valor 1 e 10 na pilha, após isso, os valores intermediarios são removidos, e empilhamos somente o valor final(10)
//--------------------------------------------------------------------------------------------------------------
//Com os numeros digitados, as operações são feitas teclando diretamente os operadores
//Operadores Possíveis -> +    -    *    /
//--------------------------------------------------------------------------------------------------------------
//Após realizar as operações, teclar 'R' para ver o resultado
//A tecla 'C', "zera" a calculadora, excluindo todos os valores presentes na calculadora
//Tecle 'S' para desligar a calculadora

//O estado atual da pilha/calculadora, esta sempre sendo mostrado por motivos de entendimento

int main()
{
    char c[50];
    char aux[50];
    char v[50];
    int valor,transformar, quantidade= 0;
    int exc = 0, flag = 0,flag2 = 0;

    //Criação e inicialização da pilha
    pilhaCalc calculadora;
    criar_pilha(&calculadora);

    do
    {
        //Menu
        printf("---------------------- Calculadora Polonesa -------------------\n\n");
        printf("E -> Digitar numero ou finalizar insercao\n");
        printf("+,-,*,/ -> Operacoes possiveis\n");
        printf("R -> Ver Resultado\n");
        printf("S -> Desligar Calculadora\n");
        printf("\nOpcao -> ");

        scanf("%s",&c);

        //Se o caracter digitado for 'E', queremos adicionar um valor
        if(strcmp(c,"E") == 0)
        {
            //Setando o valor 0 para inicio da pilha
            if(flag == 0)
            {
                inserir_pilha(&calculadora,0);
                flag = 1;
            }

            aux[0] = '\0';
            v[0] = '\0';
            exc = 0;

            //Enquanto a tecla 'E' não for digitada novamente, lemos o valor, empilhamos e concatenamos em uma string
            while(strcmp(v, "E") != 0)
            {
                printf("-> ");
                scanf(" %s", &v);

                //Ponteiro, que conta quantos valores foram adicionados, para de possamos desimplilharmos no final
                //deste loop
                exc++;

                //Quando teclamos 'E', removemos uma quantidade "exc" de valores na pilha
                //Ao final empilhamos o valor final da String (Fazemos a conversãp utilizando a funçao atoi)
                if(strcmp(v, "E") == 0)
                {
                    for(int i=0; i<exc-1; i++)
                    {
                        remove_pilha(&calculadora);
                    }

                    if(flag2 == 0)
                    {
                        remove_pilha(&calculadora);
                        flag2 = 1;
                    }
                    inserir_pilha(&calculadora,transformar);
                    break;
                }

                strcat(aux,v);
                transformar = atoi(aux);

                inserir_pilha(&calculadora,transformar);

            }
            listar(&calculadora);

        }
        else
        {
            //Variavel quantidade, pega quantos elementos temos na calculadora
            //Caso seja menos que 2, algumas operações não podem ser feitas
            quantidade = 0;
            quantidade = quant(&calculadora);

            //Tecla "C", zera a pilha chamando a funçao criar_pilha
            //Simplesmente aponta a pilha para NULL
            if(strcmp(c,"C") == 0)
            {
                criar_pilha(&calculadora);
                printf("\nCalculadora limpa\n");
            }
            //Funçao de Soma
            else if(strcmp(c,"+") == 0)
            {
                if(quantidade < 2)
                {
                    printf("\nCalculadora não possui operandos para efetuar essa operacao\n");
                }
                else
                {
                    somar(&calculadora);
                    listar(&calculadora);
                }
            }
            //Funçao de Subtração
            else if(strcmp(c,"-") == 0)
            {
                if(quantidade < 2)
                {
                    printf("\nCalculadora não possui operandos para efetuar essa operacao\n");
                }
                else
                {
                    subtrair(&calculadora);
                    listar(&calculadora);
                }
            }
            //Função de Multiplicação
            else if(strcmp(c,"*") == 0)
            {
                if(quantidade < 2)
                {
                    printf("\nCalculadora não possui operandos para efetuar essa operacao\n");
                }
                else
                {
                    multiplicar(&calculadora);
                    listar(&calculadora);
                }
            }
            //Função de Divisão
            else if(strcmp(c,"/") == 0)
            {
                if(quantidade < 2)
                {
                    printf("\nCalculadora não possui operandos para efetuar essa operacao\n");
                }
                else
                {
                    dividir(&calculadora);
                    listar(&calculadora);
                }
            }
            //Funçao para mostrar o resultado final
            else if(strcmp(c,"R") == 0)
            {
                printf("\nR: %d\n",resultado(&calculadora));
                criar_pilha(&calculadora);

            }
            else if(strcmp(c,"S") == 0)
            {
                return 0;

            }
            else
            {
                printf("\nTecla Invalida\n");
            }
        }

    }
    while(c!='S');

    return 0;
}
