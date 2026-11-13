
#include <stdio.h>
#include <stdlib.h>
#include "../include/bst.h"

// Cria um livro para utilizar nos testes
Livro criarLivro(int id) {
    Livro livro;

    livro.id = id;
    sprintf(livro.titulo, "Livro %d", id);
    sprintf(livro.autor, "Autor teste");
    livro.ano = 2000;

    return livro;
}

int main() {
    No *raiz = NULL;

    // Monta a arvore
    raiz = inserir(raiz, criarLivro(50));
    raiz = inserir(raiz, criarLivro(30));
    raiz = inserir(raiz, criarLivro(70));
    raiz = inserir(raiz, criarLivro(20));
    raiz = inserir(raiz, criarLivro(40));
    raiz = inserir(raiz, criarLivro(60));
    raiz = inserir(raiz, criarLivro(80));

    printf("=== TESTES DE REMOCAO DA BST ===\n");

    // TESTE 1: Remover folha
    raiz = remover(raiz, 20);

    if (buscar(raiz, 20) == NULL) {
        printf("[OK] Remocao de folha\n");
    } else {
        printf("[ERRO] Remocao de folha\n");
    }

    // Adiciona um filho ao no 60
    raiz = inserir(raiz, criarLivro(65));

    // TESTE 2: Remover no com um filho
    raiz = remover(raiz, 60);

    if (buscar(raiz, 60) == NULL && buscar(raiz, 65) != NULL) {
        printf("[OK] Remocao de no com um filho\n");
    } else {
        printf("[ERRO] Remocao de no com um filho\n");
    }

    // TESTE 3: Remover no com dois filhos
    raiz = remover(raiz, 70);

    if (buscar(raiz, 70) == NULL &&
        buscar(raiz, 65) != NULL &&
        buscar(raiz, 80) != NULL) {
        printf("[OK] Remocao de no com dois filhos\n");
    } else {
        printf("[ERRO] Remocao de no com dois filhos\n");
    }

    liberar_bst(raiz);

    return 0;
}
