#include <stdio.h>
#include <stdlib.h>

struct no_duplo {
	char info;
	struct no_duplo *ant, *prox;
};

struct no_duplo * cria_no_duplo (char);

