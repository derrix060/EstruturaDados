#include <stdio.h>
typedef struct{
	int placa;
	int num_manobras;
} carro;
typedef struct{
	carro ca[10];
	int topo;
} estacionamento; //pilha
carro desempilha(estacionamento *);
carro tirar_carro(estacionamento *, int );
void inicia_estacionamento(estacionamento *);
int cheio (estacionamento *);
int vazio(estacionamento *);
void empilha(estacionamento *, carro);
int main() {
	int op;
	int placa;
	estacionamento e;
	inicia_estacionamento(&e);
	carro c;
	carro resp;
	c.num_manobras = 0;
	
	
	
	
	scanf("%d",&op);
	while (op != -1){
		scanf("%d", &placa);
		
		if (op == 0){
			//empilhar
			if (cheio(&e)){
				printf("ESTACIONAMENTO LOTADO\n");
			}
			else{
				c.placa = placa;
				empilha(&e,c);
				printf("CARRO %d GUARDADO\n",placa);
			}
		}
		else{
			//desempilhar
			resp = tirar_carro(&e,placa);
			printf("CARRO %d FOI EMBORA COM %d MANOBRAS\n",placa, resp.num_manobras);
		}
		scanf("%d",&op);
	}
	
	return 0;
}
carro desempilha(estacionamento *e){
	carro temp;
	temp = e->ca[e->topo];
	e->topo--;
	return temp;
}
carro tirar_carro(estacionamento *e, int placa){
	carro carro_temp;
	
	estacionamento est_temp;
	inicia_estacionamento(&est_temp);
	carro_temp = desempilha(e);
	
	while (carro_temp.placa != placa){
		
		carro_temp.num_manobras ++;
		empilha(&est_temp, carro_temp);
		carro_temp = desempilha(e);
	}
	
	while(!vazio(&est_temp))
		empilha(e, desempilha(&est_temp));
	
	return carro_temp;
	
}
void inicia_estacionamento(estacionamento *e){
	e->topo = -1;
}
int vazio(estacionamento *e){
	return e->topo == -1;
}
int cheio (estacionamento *e){
	return e->topo == 9;
}
void empilha(estacionamento *e, carro c){
	e->topo ++;
	e->ca[e->topo] = c;
}