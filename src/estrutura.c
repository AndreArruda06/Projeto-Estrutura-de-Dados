#inlcude <stdio.h>
#include <stdlib.h>
#include "estrutura.h"

void inserir_lista(NoLista **inicio, int id){
	NoLista *novo = malloc(sizeof(NoLista));
	
	if (novo == NULL){
		printf ("Erro ao alocar memoria. \n" );
		return ;
	}
	
	novo->id = id;
	novo->proximo = NULL;
}

	if (*inicio == NULL){
		*inicio = novo;
	} else {
		NoLista *atual = *inicio;
		
		while (atual->proximo != NULL){
			atual = atual->proximo;
		}
		atual->proximo = novo
	}
	
	printf("ID inserido na Lista! \n");
}

void remover_lista(NoLista **inicio) {
	if (*inicio = NULL){
		printf("A lista esta vazia! \n");
		return;
	}
	
	NoLista *removido = *inicio;
	*inicio = removido->proximo;
	
	printf("ID removido: %d \n", removido->id);
	
	free(removido);
}