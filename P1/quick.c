#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define T 12
void gera_vetor (int v[]) {
   int i;
   for (i=0; i<T; i++) 
      v[i] = rand();
}
void mostra_vetor (int v[]) {
   int i;
   printf("\n\n\n");
   for (i=0; i<T; i++) 
      printf ("%d ", v[i]);
   printf ("\n\n");
}
int partition (int A[], int p, int r) {
    int x = A[r]; 
	int aux, j, i = p-1;
	for(j = p; j <= r-1; j++) {
       if (A[j] <= x) {
            i = i + 1;
            aux = A[i];
	 	  	A[i] = A[j];
		  	A[j] = aux;
       }
    }
	aux = A[r];
	A[r] = A[i + 1];
	A[i + 1] = aux;
    return i+1;
}	
void quicksort(int A[], int p, int r) {
     int q;
     printf ("\np = %d, r = %d", p, r);
     if (p < r) {
           q = partition(A, p, r);
           printf ("\nq = %d", q);
	   	   quicksort (A, p, q-1);
           quicksort (A, q+1, r);
     }
}
int main () {
    int *v = (int *) malloc (sizeof (int) * T);
    srand (time(0));
    gera_vetor (v);
    //mostra_vetor (v);
    quicksort (v, 0, T-1);
    printf ("\n\nvetor ordenado 1a vez\n\n");
    //mostra_vetor (v);
    quicksort (v, 0, T-1);
    //printf ("\n\nvetor ordenado 2a vez\n\n");
    //mostra_vetor (v);
    return 0;
} 
