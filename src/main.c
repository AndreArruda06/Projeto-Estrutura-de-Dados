#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>

#include "../include/bst.h"
#include "../include/estrutura.h"

// FUNCAO PARA LER E VALIDAR NUMEROS
int lerInteiro(char mensagem[], int minimo, int maximo) {

    char entrada[100];
    char *fim;
    long valor;

    while (1) { // Repete ate receber um valor valido

        printf("%s", mensagem); 

        // Le a entrada do usuario como texto e armazena
        if (fgets(entrada, sizeof(entrada), stdin) == NULL) {
            return 0;
        }

        errno = 0; // Limpa o indicador de erro anterior para começar a conversao do valor atual



        // Converte o texto digitado em numero e guarda em valor
		// fim indica onde a conversao parou, para verificar se havia caracteres invalidos
		// O numero 10 indicando que a conversao utiliza a base decimal
        valor = strtol(entrada, &fim, 10);

        // Ignora espacos depois do numero
        while (isspace((unsigned char)*fim)) {
            fim++;
        }

        // Verifica se a entrada e invalida
        if (fim == entrada || *fim != '\0' ||
            errno == ERANGE || valor < minimo || valor > maximo) {

            printf("Valor invalido! Tente novamente.\n");

        } else {

            // Se estiver correto, retorna o numero
            return (int)valor;
        }
    }
}

int main(){
	No *raiz = NULL;
	NoLista *inicio = NULL;
	
	int opcao;
	Livro livro;
	
	do{
		printf("\n ========|BIBLIOTECA|=========\n");
		printf("1 - Cadastrar livro \n");
		printf("2 - Buscar livro por ID \n");
		printf("3 - Remover livro \n");
		printf("4 - Listar livros em ordem \n");
		printf("5 - Inserir ID na lista \n");
		printf("6 - Remover ID na lista \n");
		printf("7 - Exibir lista \n");
		printf("0 - Encerrar \n\n");
		opcao = lerInteiro("Escolha uma opcao: ", 0, 7);
		
		if (opcao == 1) {
            livro.id = lerInteiro("Digite o ID do livro: ", 1, 2147483647);
            
            if (buscar(raiz, livro.id) != NULL) {
  				printf("Esse ID ja esta cadastrado!\n");
			} else {
				
				printf("Digite o titulo do livro: ");
				fgets(livro.titulo, sizeof(livro.titulo), stdin);
				livro.titulo[strcspn(livro.titulo, "\n")] = '\0';
				
				printf("Digite o autor do livro: ");
				fgets(livro.autor, sizeof(livro.autor), stdin);
				livro.autor[strcspn(livro.autor, "\n")] = '\0';
				
				livro.ano = lerInteiro("Digite o ano de publicacao: ", 1, 2026);
				
				raiz = inserir(raiz, livro);
				printf("Livro cadastrado com sucesso!\n");
				
			}
        }
		
	}while (opcao != 0);
		
	liberar_bst(raiz);
	liberar_lista(inicio);
	
	return 0;
}