#include <stdio.h>
#include <stdlib.h>

//Structs
struct no_struct{
	int info;
	struct no_struct *prox;
};

//Tipos
typedef struct no_struct no;
typedef struct{
	no *primeiro;
}lista;

//Funções
void inicia_lista (lista *);
no * cria_no (int);
int lista_vazia (lista *);
void mostrar_lista (lista *);
void insere_inicio (int, lista *);
void insere_fim (int, lista *);
int remove_inicio (int *, lista *);
int remove_fim (int *, lista *);

//Main
int main() {
	lista l;
	
	inicia_lista(&l);
	int i;
	
	for (i=0; i<10;i++){
		insere_inicio(i, &l);
	}
	mostrar_lista(&l);
	
	if (remove_inicio(&i, &l)){
		printf("%d foi removido do inicio\n", i);
		mostrar_lista(&l);
	}
	
	if(remove_fim(&i,&l)){
		printf("%d foi removido do fim\n", i);
		mostrar_lista(&l);
	}
	
	
	return 0;
}


//nó
no * cria_no (int i){
 	no *ap_no;
	ap_no = (no *) malloc (sizeof(no));
	if (ap_no != NULL){
		ap_no->info = i;
		ap_no->prox = NULL;
	}
	return ap_no;
}

//Lista
void inicia_lista (lista *l){
	l->primeiro = NULL;
}
int lista_vazia (lista *l){
	return l->primeiro == NULL;
}
void mostrar_lista (lista *l){
	no *aux;
	
	aux = l->primeiro;
	
	if(lista_vazia(l))
		printf("Lista esta vazia!\n");
	else{
		//descobrir onde acaba
		while(aux != NULL){
			printf("%d ", aux->info);
			aux = aux->prox;
		}
		printf("\n");
	}
}
void insere_inicio (int valor, lista *l){
	no *novo = cria_no(valor);
	
	if (novo != NULL){
		if (!lista_vazia(l))
			novo->prox = l->primeiro;
			
		l->primeiro = novo;
		
	}
	else{
		printf("Não foi possível alocar novo nó!!\n");
	}
}
void insere_fim (int valor, lista *l){
	no *novo = cria_no(valor);
	no *aux;
	if(novo != NULL){
		if (lista_vazia(l))
			l->primeiro = novo;
		else{
			aux = l->primeiro;
			
			//descobrir ultimo elemento
			while(aux->prox != NULL){
				aux = aux->prox;
			}
			
			aux->prox = novo;
		}	
	}
	else
		printf("Nao foi possivel alocar novo no\n");
	
}
int remove_inicio (int *valor, lista *l){
	no *aux; //para liberar memoria
	if (lista_vazia(l))
		return 0;
	
	*valor = l->primeiro->info;
	
	aux = l->primeiro;
	l->primeiro = l->primeiro->prox;
	
	free(aux);
	return 1;
}
int remove_fim (int *valor, lista *l){
	no *aux;
	no *prox_aux;
	
	if (lista_vazia(l))
		return 0;
	if (l->primeiro->prox == NULL){
		//só tem um elemento, devolve ele
		*valor = l->primeiro->info;
		free(l->primeiro);
		l->primeiro = NULL;
		return 1;
	}
	aux = l->primeiro;
	prox_aux = aux->prox;
	
	while(prox_aux->prox != NULL){
		aux = aux->prox;
		prox_aux = aux->prox;
	}
	
	*valor = prox_aux->info;
	aux->prox = NULL;
	free(prox_aux);
	
	return 1;
}
