#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"
#include "estrutura.h"

int main(){
	No *raiz = NULL;
	NoLista *inicio = NULL;
	
	int opcao;
	
	do{
		printf("\n \\\\\\\\\_|BIBLIOTECA|_////////// \n");
		printf("1 - Cadastrar livro \n");
		printf("2 - Buscar livro por ID \n");
		printf("3 - Remover livro \n");
		printf("4 - Listar livros em ordem \n");
		printf("5 - Inserir ID na lista \n");
		printf("6 - Remover ID na lista \n");
		printf("7 Exibir lista \n");
		printf("0 - Encerrar \n\n");
		printf("Escolha uma opçao: ");
		scanf("%d", &opcao);
		
	}while (opcao != 0);
		
	liberar_bst(raiz);
	liberar_lista(inicio);
	
	return 0;
}