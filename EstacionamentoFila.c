#include <stdio.h>
//Structs


//Tipos
typedef struct{
	int placa;
	int num_manobras;
} carro;
typedef struct{
	carro ca[11];
	int primeiro;
	int ultimo;
} estacionamento; //fila

//Funcoes
int proximo(int);
carro manobrar_carro(estacionamento *);
void inicia_estacionamento(estacionamento *);
int cheio (estacionamento *);
int vazio(estacionamento *);
void estacionar_carro(estacionamento *, carro);
carro desestacionar_carro(estacionamento *, int);
void mostrar_estacionamento (estacionamento *);
carro inicia_carro(int);

//Mae
int main() {
	int op;
	int placa;
	estacionamento e;
	inicia_estacionamento(&e);
	carro c;
	carro resp;
	
	
	scanf("%d",&op);
	while (op != -1){
		scanf("%d", &placa);
		
		if (op == 0){
			//empilhar
			if (cheio(&e)){
				printf("ESTACIONAMENTO LOTADO\n");
			}
			else{
				c.inicia_carro(placa);
				estacionar_carro(&e, c);
				printf("CARRO %d GUARDADO\n",placa);
			}
		}
		else if (op == 1){
			//desempilhar
			resp = desestacionar_carro(&e,placa);
			printf("CARRO %d FOI EMBORA COM %d MANOBRAS\n",placa, resp.num_manobras);
		}
		else{
			printf("Opcao invalida!!\n");
		}
		//mostrar_estacionamento(&e); //use essa parte para "debugar"
		scanf("%d",&op);
	}
	
	return 0;
}

//Implementacao Funcoes
int proximo(int ultimo){
	return (ultimo + 1) % 11;
}
carro desestacionar_carro(estacionamento *e, int placa){
	carro carro_temp;
	int i = 0;
	
	carro_temp = manobrar_carro(e);
	while(carro_temp.placa != placa && i<10){
		//não é o que eu quero
		guardar_carro(e, carro_temp);
		carro_temp = manobrar_carro(e);
	}
	if (i<10){
		//achei
		return carro_temp;
	else
		printf("Carro não está no estaconamento\n");
	}
}
void mostrar_estacionamento (estacionamento *e){
	int i;
	
	i = e->primeiro;
	
	while (i!=proximo(e->ultimo)){
		printf("Posicao %d: Placa = %d Manobras = %d\n", i, e->ca[i].placa, e->ca[i].num_manobras);
		i = proximo(i);
	}
	printf("\n");
}
void inicia_estacionamento(estacionamento *e){
	e->primeiro = 1;
	e->ultimo = 0;
}
int vazio(estacionamento *e){
	return proximo(e->ultimo) == e->primeiro;
}
int cheio (estacionamento *e){
	return proximo(proximo(e->ultimo)) == e->primeiro;
}
carro manobrar_carro(estacionamento *e){
	carro resp;
	resp = e->ca[e->primeiro];
	e->primeiro = proximo(e->primeiro);
	
	return resp;
}
void estacionar_carro(estacionamento *e, carro c){
	c.num_manobras ++;
	e->ultimo = proximo(e->ultimo);
	e->ca[e->ultimo] = c;
}
carro inicia_carro(int placa){
	carro c;
	
	c.num_manobras = -1;
	c.placa = placa;
	
	return c;
}
