#include <stdio.h>
#include <stdlib.h>

int calcular_Percentual(arvore *raiz, int *quant){

	//Percorremos a arvore verificando quantos elementos possui
	if (raiz == NULL)
	{
		return 0;

	}else{

        //Se aquele nó possui tanto o filho da direita, quanto o da esquerda
        //como NULL, ele é um nó folha, portanto incrementamos "quant"
        if(raiz->esquerda == NULL && raiz->direita == NULL){
            *quant++;
        }

		return calcular_Percentual(raiz->esquerda,*(&quant)) + contarNos(raiz->direita,*(&quant)) + 1;
	}

	//Parte que estaria na main
	//Divide a quantidade de elementos folha pelo total

	int total = calcular_Percentual(&arvore,&quant);
	float percentual = quant / total;

	printf("Percentual : %f\n",percentual);

}
