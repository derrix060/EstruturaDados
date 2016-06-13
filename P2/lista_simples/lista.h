#include "no.h"

struct lista {
	struct no * primeiro;
};

void inicia_lista (struct lista *);
int lista_vazia (struct lista *);

void insere_inicio (int, struct lista *);
void insere_fim (int, struct lista *);

void mostra_lista (struct lista *, char *);

int remove_inicio (int *, struct lista *);
//devolvem 0 ou 1 = fracasso ou sucesso da remoção
int remove_fim (int *, struct lista *);

