#ifndef ESTRUTURA_H
#define ESTRUTURA_H

typedef struct NoLista {
	int id;
	struct NoLista *proximo;
}NoLista;

void inserir_lista(NoLista **inicio, int id);
void remover_lista(NoLista ** inicio);
void exibir_lista(NoLista *inicio);
void liberar_lista(NoLista *inicio);

#endif
