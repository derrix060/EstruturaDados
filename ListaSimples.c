#include <stdio.h>
#include <stdlib.h>

//Structs
struct no_struct{
	carro car;
	struct no_struct *prox;
};

//Tipos
typedef struct no_struct no;
typedef struct{
	no *primeiro;
}lista;
typedef struct{
	int placa;
	int num_manobras;
}carro;
typedef struct{
	carro ca[10]
	
}estacionamento;

//Funções

//lista
void inicia_lista (lista *);
no * cria_no (int);
int lista_vazia (lista *);
void insere_inicio (int, lista *);
void insere_fim (int, lista *);
void mostrar_lista (lista *);
//estacionamento


//Main
int main() {
	lista l;
	
	inicia_lista(&l);
	int i;
	
	for (i=0; i<10;i++){
		insere_inicio(i, &l);
	}
	mostrar_lista(&l);
	
	
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