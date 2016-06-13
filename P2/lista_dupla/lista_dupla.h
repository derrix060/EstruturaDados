#include "no_duplo.h"

struct lista_dupla {
	struct no_duplo * primeiro;
};

void inicia_lista_dupla (struct lista_dupla *);
int lista_dupla_vazia (struct lista_dupla *);

int insere_inicio_lista_dupla (char, struct lista_dupla *);
int insere_fim_lista_dupla (char, struct lista_dupla *);

void mostra_lista_dupla (struct lista_dupla *);

int remove_inicio_lista_dupla (char *, struct lista_dupla *);
int remove_fim_lista_dupla (char *, struct lista_dupla *);


