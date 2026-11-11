
#ifndef BST_H
#define BST_H

typedef struct Livro {
    int id;
    char titulo[80];
    char autor[80];
    int ano;
} Livro;

typedef struct No {
    Livro livro;
    struct No *esquerda;
    struct No *direita;
} No;

No* inserir(No *raiz, Livro livro);
No* buscar(No *raiz, int id);
No* remover(No *raiz, int id);
void listar_em_ordem(No *raiz);
void liberar_bst(No *raiz);

#endif
