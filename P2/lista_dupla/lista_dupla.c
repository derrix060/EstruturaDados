#include "lista_dupla.h"

void inicia_lista_dupla (struct lista_dupla *l) {
	l->primeiro = NULL;
}

int lista_dupla_vazia (struct lista_dupla *l) {
	if (l->primeiro == NULL)
		return 1;
	return 0;
}
int insere_inicio_lista_dupla (char c, struct lista_dupla *l) {
	struct no_duplo * novo = cria_no_duplo(c);
	if (novo != NULL) {
		if (lista_dupla_vazia(l)) {
			novo->ant = novo;
			novo->prox = novo;
		}
		else {
			novo->prox = l->primeiro;
			novo->ant = l->primeiro->ant;
			novo->prox->ant = novo;
			novo->ant->prox = novo;
		}
		l->primeiro = novo;
		return 1;
	}	
	else {
		printf ("\nNao foi possivel alocar novo no\n");
		return 0;
	}
}
int insere_fim_lista_dupla (char c, struct lista_dupla *l) {
	struct no_duplo * novo = cria_no_duplo(c);
	if (novo != NULL) {
		if (lista_dupla_vazia(l)) {
			novo->ant = novo;
			novo->prox = novo;
			l->primeiro = novo;
		}
		else {
			novo->prox = l->primeiro;
			novo->ant = l->primeiro->ant;
			novo->prox->ant = novo;
			novo->ant->prox = novo;
		}
		return 1;
	}	
	else {
		printf ("\nNao foi possivel alocar novo no\n");
		return 0;
	}
}
void mostra_lista_dupla (struct lista_dupla *l) {
	struct no_duplo * aux;
	if (lista_dupla_vazia(l)) {
		printf ("\nesta vazia\n");
	}
	else {
		aux = l->primeiro;
		do {
			printf ("%c ", aux->info);
			aux = aux->prox;
		} while (aux != l->primeiro);
		printf ("\n");
	}
}
int remove_inicio_lista_dupla (char *c, struct lista_dupla *l) {
	struct no_duplo * aux;
	if (lista_dupla_vazia(l)) {
		printf ("\nlista vazia\n");
		return 0;
	}
	else {
		aux = l->primeiro;
		*c = l->primeiro->info;
		if (l->primeiro == l->primeiro->ant) { //um elemento so
			l->primeiro = NULL;
		}
		else { // varios elementos
			l->primeiro->ant->prox = l->primeiro->prox;
			l->primeiro->prox->ant = l->primeiro->ant;
			l->primeiro = l->primeiro->prox;
		}
		free (aux);	
		return 1;
	}
}
int remove_fim_lista_dupla (char *c, struct lista_dupla *l) {
	struct no_duplo * aux;
	if (lista_dupla_vazia(l)) {
		printf ("\nlista vazia\n");
		return 0;
	}
	else {
		aux = l->primeiro->ant;
		*c = l->primeiro->ant->info;
		if (l->primeiro == l->primeiro->ant) { //um elemento so
			l->primeiro = NULL;
		}
		else { // varios elementos
			l->primeiro->ant = l->primeiro->ant->ant;
			l->primeiro->ant->prox = l->primeiro;
		}
		free (aux);	
		return 1;
	}
}





