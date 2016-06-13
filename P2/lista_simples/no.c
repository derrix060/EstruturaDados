#include "no.h"





struct no * cria_no (int i) {
	struct no * ap_no;
	ap_no = (struct no *) malloc (sizeof(struct no));
	if (ap_no != NULL) {
		ap_no->info = i;
		ap_no->prox = NULL;
	}
	return ap_no;
}
