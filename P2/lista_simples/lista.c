#include "lista.h"

void inicia_lista (struct lista *l) {
	l->primeiro = NULL;
}
int lista_vazia (struct lista *l) {
	if (l->primeiro == NULL) // return !l->primeiro;
		return 1;
	return 0;
}
void insere_inicio (int i, struct lista *l) {
	struct no * novo = cria_no(i);
	if (novo != NULL) {
		if (!lista_vazia(l)) {
			novo->prox = l->primeiro;
		}
		l->primeiro = novo;
	}
	else {
		printf ("\nNao foi possivel alocar novo no\n");
	}
}
void mostra_lista (struct lista *l, char *msg) {
	struct no * aux;
	printf ("\n%s\n", msg);
	if (lista_vazia(l)) {
		printf ("esta vazia!\n");
	}
	else {
		aux = l->primeiro;
		while (aux != NULL) { //procurando o final da lista
			printf ("%d ", aux->info);
			aux = aux->prox;
		}
		printf ("\n");
	}
}
void insere_fim (int i, struct lista *l) {
	struct no * novo = cria_no(i);
	struct no * aux;
	if (novo != NULL) {
		if (lista_vazia(l)) {
			l->primeiro = novo;
		}
		else {
			aux = l->primeiro;
			while (aux->prox != NULL) {//procurando o último 
				aux = aux->prox;
			}
			aux->prox = novo;
		}
	}
	else {
		printf ("\nNao foi possivel alocar novo no\n");
	}
}
int remove_inicio (int *p_i, struct lista *l) {
	struct no * aux;
	if (lista_vazia(l)) {
		return 0;
	}
	*p_i = l->primeiro->info;
	aux = l->primeiro;
	l->primeiro = l->primeiro->prox;
	free(aux);
	return 1;
}
int remove_fim (int *p_i, struct lista *l) {
	struct no * aux;
	if (lista_vazia(l)) {
		return 0;
	}
	if (l->primeiro->prox == NULL) { //tem um cara só
		*p_i = l->primeiro->info;
		free(l->primeiro);
		l->primeiro = NULL;
	}
	else {
		aux = l->primeiro;
		while (aux->prox->prox != NULL) {//procurando o penúltimo 
			aux = aux->prox;
		}
		*p_i = aux->prox->info;
		free(aux->prox);
		aux->prox = NULL;
	}
	return 1;
}
void remove_todos_n (int n, struct lista *l) {
	struct no * aux = l->primeiro;
	struct no * livre;
	
	while (aux && l->primeiro->info == n) {
		remove_inicio (&n, l);
		aux = l->primeiro;
	}
	while (aux) {
		while (aux->prox && aux->prox->info == n) {
			livre = aux->prox;
			aux->prox = aux->prox->prox;
			free(livre);
		}
		aux = aux->prox;
	}
}
void merge_lista (struct lista *l1, struct lista *l2, struct lista *l3) {
	int aux1, aux2;
	inicia_lista(l3);
	while (!lista_vazia(l1) && !lista_vazia(l2)) {
		remove_inicio (&aux1, l1);
		remove_inicio (&aux2, l2);
		if (aux1 <= aux2) {
			insere_fim (aux1, l3);
			insere_inicio (aux2, l2);
		}
		else {
			insere_fim (aux2, l3);
			insere_inicio (aux1, l1);
		}
	}
	while (!lista_vazia(l1)) {
		remove_inicio(&aux1, l1);
		insere_fim (aux1, l3);
	}
	while (!lista_vazia(l2)) {
		remove_inicio(&aux2, l2);
		insere_fim (aux2, l3);
	}
}



















