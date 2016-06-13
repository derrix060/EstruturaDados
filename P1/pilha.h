#include <stdio.h>
#define MAX 10

typedef struct {
	int dados[MAX];
	int topo;
} t_pilha;

void inicia_pilha (t_pilha *);

void empilha (int, t_pilha *);

int desempilha (t_pilha *);

int tamanho_pilha (t_pilha *);

int pilha_cheia (t_pilha *);

int pilha_vazia (t_pilha *);

void mostra_pilha (t_pilha *, char *);
