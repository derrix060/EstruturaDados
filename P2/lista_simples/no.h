#include <stdlib.h>
#include <stdio.h>

struct no {
	int info;
	struct no * prox;
};

struct no * cria_no (int);
