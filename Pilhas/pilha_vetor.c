#include <stdio.h>
#include <stdlib.h>

#define N 50 /* numero máximo de elementos */

struct pilha{
    int n;
    float vet[N];
};

typedef struct pilha Pilha;


/* Objetivo: cria uma pilha e aloca dinamicamente essa estrutura e inicializa a pilha como sendo vazia*/
Pilha* pilha_cria(void){
    Pilha *p = (Pilha *)malloc(sizeof(Pilha));
    p->n = 0; /* Inicializa com 0 elementos */
    return p;
}

/* Objetivo: inserir elementos na posição livre */
void pilha_push(Pilha* p, float v){
    if(p->n == N){
        printf("Capacidade da pilha esgotada.\n");
        exit(1); /* Sai do programa */
    }
    /* insere elemento na próxima posição livre */
    p->vet[p->n] = v;
    p->n++;
}


/* Objetivo: verificar se pilha está vazia */
float pilha_vazia(Pilha *p){
    return( p->n == 0);
}

/* Objetivo: retirar o elemento do topo da pilha */
float pilha_pop(Pilha *p){
    float v;
    if (pilha_vazia(p)){
        printf("Pilha vazia. \n");
        exit(1);
    }
    /* retira elemento do topo */
    v = p->vet[p->n-1]; /* pegando elemento que vai sair para retornar ao final */
    p->n--;
    return v;
}


void pilha_imprimir(Pilha *p){

    int i;
    if (pilha_vazia(p)){
        printf("Pilha vazia. \n");
        exit(1);
    }
    for ( i = p->n-1; i >= 0; i--)
        printf("Valor armazenado: %.2f\n", p->vet[i]);

}



void pilha_libera(Pilha *p){
    free(p);
}