#include "no_duplo.h"

struct no_duplo * cria_no_duplo (char c) {
	struct no_duplo * novo = (struct no_duplo *) malloc 
	(sizeof(struct no_duplo));
	if (novo != NULL) {
		novo->info = c;
		novo->ant = NULL;
		novo->prox = NULL;
	}
	return novo;
}

