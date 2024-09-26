#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct No{
	int numero;
	struct No* prox;
}No;
typedef struct Fila{
	No* inicio;
	No* final;
}Fila;

Fila* inicializaFila(){
	Fila* q = (Fila*)malloc(sizeof(Fila));
	q->inicio = q->final = NULL;
	return q;
}
void insereNaFila(Fila* q,int valor){
	No* novoNo=(No*)malloc(sizeof(No));
	novoNo->numero = valor;
	novoNo->prox = NULL;
	if(q->final == NULL){
		q->inicio = q->final = novoNo;
		return;
	}
	q->final->prox = novoNo;
	q->final = novoNo;
}
int RemoveDaFila(Fila* q){
	if(q->inicio == NULL){
		printf("Fila Vazia!\n");
		return -1;
	}
	
	No* temp = q->inicio;
	int valor = temp->numero;
	q->inicio = q->final->prox;
	
	if(q->inicio == NULL){
		q->final = NULL;
	}
	
	free(temp);
	return valor;
}

int isEmpty(Fila* q){
	return q->inicio == NULL;
}
int peek(Fila* q){
	if(q->inicio == NULL){
		printf("Fila Vazia!\n");
		return -1;
	}
	return q->inicio->numero;
}
int rear(Fila* q){
	if(q->final == NULL){
		printf("Fila Vazia!\n");
		return -1;
	}
	return q->final->numero;
}
void imprimirFila(Fila* q){
	No* temp = q -> inicio;
		while(temp != NULL){
			printf("[%d]\n",temp -> numero);
			temp = temp -> prox;	
		}
	
}
 
main(){
	setlocale(LC_ALL, "Portuguese");
	
	Fila* q = inicializaFila();
	
	insereNaFila(q,20);
	insereNaFila(q,40);
	insereNaFila(q,60);
	
	printf("Primeiro Elemento: %d\n",peek(q));
	printf("Ultimo Elemento: %d\n",rear(q));
	
	RemoveDaFila(q);
	printf("Ap�s remover, primeiro elemento: %d\n",peek(q));
	RemoveDaFila(q);
	
	
	if(isEmpty(q)){
		printf("A Fila est� vazia!\n");
	}

	imprimirFila(q);
}
