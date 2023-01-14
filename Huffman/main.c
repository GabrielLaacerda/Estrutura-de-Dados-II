#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    char simb ;
    int freq ;
    struct No * esq, * dir ;
} No ;

typedef No * p_no ;

p_no criar_no ( char simb, int freq, p_no esq, p_no dir )
{
    p_no r = malloc ( sizeof ( No ) );
    r -> simb = simb ;
    r -> freq = freq ;
    r -> esq = esq ;
    r -> dir = dir ;

    return r;
}

p_no codificacao_huffman ( char * simbs, int * freqs, int n)
{
    int i;
    p_no fila ;
    p_no no, x, y;

// cria uma folha para cada símbolo e insere na fila
    fila = criar_fprio (n) ;

    for (i = 0; i < n; i ++)
    {
        no = criar_no ( simbs [i ], freqs [i ], NULL, NULL ) ;
        insere ( fila, no );
    }

// enquanto houver pelo menos 2 elementos na fila
    while (n >= 2)
    {
        x = extrai_minimo ( fila );
        y = extrai_minimo ( fila );
        no = criar_no (0, x -> freq + y -> freq, x, y);
        insere ( fila, no );
        n --;
    }
    no = extrai_minimo ( fila );
    destruir_fprio ( fila ) ;

// devolve a raiz da árvore criada
    return no ;
}

int main(){

    char frase[] = "UFU ao contrário é UFU!";



    return 0;
}
