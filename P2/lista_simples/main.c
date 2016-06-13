#include "lista.h"

int main(int argc, char *argv[]) {
/*	struct no no1, no2;
	
	struct no * ap_no;
	
	no1.info = 10;
	no1.prox = &no2;
	
	printf ("no1.info = %d\n", no1.info);
	printf ("no1.prox = %p\n", no1.prox);
	
	no1.prox->info = 20;
	no1.prox->prox = &no1;
	
	printf ("no2.info = %d\n", no2.info);
	printf ("no2.prox = %p\n", no2.prox);
	
	no1.prox->prox->info = 100;
	printf ("no1.info = %d\n", no1.info);
		
	//printf ("ap_no = %p\n", ap_no);
	//ap_no->info = 50;
	//printf ("ap_no->info = %d\n", ap_no->info);
	
	/*ap_no = (struct no *) malloc (sizeof(struct no));
	
	ap_no->info = 100;
	ap_no->prox = &no2;
	
	ap_no = cria_no (200);
	if (ap_no != NULL) {
		printf ("ap_no = %p\n", ap_no);
		printf ("ap_no->info = %d\n", ap_no->info);
		printf ("ap_no->prox = %p\n", ap_no->prox);
	}
	else {
		printf ("Nao foi possivel alocar o no");
	}*/
	int i;
	struct lista l;
	inicia_lista (&l);
	for (i=1; i<10; i=i+2) {
		insere_inicio (i, &l);
		mostra_lista (&l, "");
	}
	for (i=2; i<=10; i=i+2) {
		insere_fim (i, &l);
		mostra_lista (&l, "");
	}
	if (remove_inicio(&i, &l) == 1) {
		printf ("\n%d foi removido do inicio\n", i);
		mostra_lista (&l, "lista depois da remocao de inicio");
	}
	else {
		printf ("\nNao foi possivel remover elemento do inicio");
	}
	if (remove_fim(&i, &l) == 1) {
		printf ("\n%d foi removido do fim\n", i);
		mostra_lista (&l, "lista depois da remocao de fim");
	}
	else {
		printf ("\nNao foi possivel remover elemento do fim");
	}
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}

