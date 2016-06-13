#include <time.h>
#include "lista_dupla.h"

int main(int argc, char *argv[]) {
	int i;
	char c;
	struct lista_dupla l;
	inicia_lista_dupla (&l);
	srand(time(0));
	for (i=1; i<=5; i++) {
		insere_inicio_lista_dupla ((char)(rand()%96+32), &l);
		mostra_lista_dupla (&l);
	}
	for (i=1; i<=5; i++) {
		insere_fim_lista_dupla ((char)(rand()%96+32), &l);
		mostra_lista_dupla (&l);
	}
	if (remove_inicio_lista_dupla (&c, &l) == 1) {
		printf ("%c saiu do inicio\n", c);
		mostra_lista_dupla (&l);
	}
	if (remove_fim_lista_dupla (&c, &l) == 1) {
		printf ("%c saiu do inicio\n", c);
		mostra_lista_dupla (&l);
	}
	return 0;
}
