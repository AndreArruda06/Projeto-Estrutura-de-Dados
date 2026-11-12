#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

No* inserir(No *raiz, Livro livro){
	if (raiz == NULL){
		No *novo = malloc(sizeof(No));
		
		if (novo == NULL){
			printf("Erro ao alocar memoria! \n");
			return NULL;
		}
		
		novo->livro = livro;
		novo->esquerda= NULL;
		novo->direita = NULL;
		
		return novo;
	}
	
	if (livro.id < raiz->livro.id){
		raiz->esquerda = inserir(raiz->esquerda, livro);
	}
	else if(livro.id > raiz->livro.id){
		raiz->direita = inserir(raiz->direita,livro);
	}
	else{
		printf("ID ja cadastrado!\n");
	}
	
	return raiz;
}

No* buscar(No *raiz, int id){
	if (raiz == NULL || raiz->livro.id == id){
		return raiz;
	}
	if (id < raiz->livro.id){
		return buscar(raiz->esquerda,id);
	}
	return buscar(raiz->direita,id);
}