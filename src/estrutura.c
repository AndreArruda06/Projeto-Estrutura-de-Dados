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