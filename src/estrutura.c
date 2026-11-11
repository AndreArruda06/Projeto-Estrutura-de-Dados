#inlcude <stdio.h>
#include <stdlib.h>
#include "estrutura.h"

void inserir_lista(NoLista **inicio, int id){
	NoLista *novo = malloc(sizeof(NoLista));
	
	if (novo == NULL){
		printf ("Erro ao alocar memoria. \n" );
		return n;
	}
	
	novo ->id = id;
	novo -> proximo = NULL;
}

	if (*inicio == NULL){
		*inicio = novo;
	} else {
		NoLista *atual = *inicio;
		
		while (atual -> proximo != NULL){
			atual = atual -> proximo;
		}
		atual -> proximo = novo
	}
	
	printf("ID inserido na Lista! \n");
}