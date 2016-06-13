//Exercicios DivertimentosFilas

//fila.c
typedef struct{
	int v*;
	int prim;
	int ult;
	int cap;
}fila;

void inicia_fila (fila *f, int capacidade){
	f->v = (int *) malloc ((capacidade +1) * sizeof (int));
	f->prim = 1;
	f->ult = 0;
}
int proximo(int posicao, fila *f){
	return (posicao+1) %(f->cap + 1);
}
int anterior(int posicao, fila *f){
	return (posicao + f->cap) % (f->cap + 1);
}
int fila_vazia (fila *f){
	return proximo(f->ult,f) == f->prim;
}
int fila_cheia (fila *f){
	return proximo(proximo(f->ult,f),f) == f->prim;
}
void insere(int vlr, fila *f){
	if (!fila_cheia(f)){
		f->ult = proximo(f->ult,f);
		f->v[f->ult] = vlr;
	}
}


//1.1
int remove_primeiro(fila *f){
	int resposta;

	resposta = f->v[f->prim];
	f->prim = proximo(f->prim,f);

	return resposta;
}
//1.2
int remove_ultimo(fila *f){
	int resposta;

	resposta = f->v[f->ult];
	f-ult = anterior(f->ult,f);

	return resposta;
}
//1.3
int num_elementos(fila *f){
	int pos_aux;
	int resposta = 0;

	if(fila_vazia(f))
		return 0;

	pos_aux = f->prim;
	while(pos_aux != proximo(f->ult,f)){
		resposta ++;
		pos_aux = proximo(pos_aux,f);
	}

	return resposta;
}
//1.4
void inverter_fila(fila *f){
	int i;
	pilha p;
	inicia_pilha(&p);

	while(!fila_vazia(f)){
		empilha(remove_primeiro(f),p);
	}
	while(!pilha_vazia){
		insere(desempilha(p),f);
	}
}
//2.1
int e_impar(int num){
	return num%2!=0;
}
int qtde_impar_vetor(int v*, int tam){
	int resultado = 0;
	int i;

	for(i=0;i<tam;i++){
		if(e_impar(v[i]))
			resultado++;
	}
}
void separar_paridade(fila *f, fila *par, fila *impar){
	int tamanho = num_elementos(f);
	int qtde_impar = qtde_impar_vetor(f->v, tamanho);
	int aux;

	inicia_fila(impar, qtde_impar);
	inicia_fila(par, tamanho-qtde_impar);

	while(!fila_vazia(f)){
		aux = remove_primeiro(f);
		if(e_impar(aux))
			insere(aux,impar);
		else
			insere(aux,par);
	}
}

//2.2
void separar_paridade(fila *f, fila *par, fila *impar){
	int tamanho = num_elementos(f);
	int qtde_impar = qtde_impar_vetor(f->v, tamanho);
	int aux;

	inicia_fila(impar, qtde_impar);
	inicia_fila(par, tamanho-qtde_impar);

	while(!fila_vazia(f)){
		aux = remove_primeiro(f);
		if(e_impar(aux))
			insere(aux,impar);
		else
			insere(aux,par);
		//so adicionar o elemento no final da fila novamente para nao destui-la
		insere(aux,f);
	}
}
