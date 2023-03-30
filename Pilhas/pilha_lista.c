#include <stdio.h>
#include <stdlib.h>

struct lista{
    float info;
    struct lista *prox;
};

typedef struct lista Lista;

struct pilha{
    Lista *prim;
};
typedef struct pilha Pilha;

Pilha* pilha_cria(void){
    Pilha* p = (Pilha *)malloc(sizeof(Pilha));
    p->prim = NULL;
    return p;
}

void pilha_push(Pilha *p, float v){
    Lista *n = (Lista*)malloc(sizeof(Lista));
    n-> info = v;
    n->prox = p->prim;
    p->prim = n;
}

int pilha_vazia(Pilha* p){
    return ( p->prim==NULL );
}

float pilha_pop(Pilha* p){
    Lista* t;
    if(pilha_vazia(p)){
        printf("Pilha vazia.\n");
        exit(1);
    }

    t = p->prim;
    v = t->info;
    p->prim = t->prox;
    free(t);
    return v;
}

void pilha_libera(Pilha *p){
    Lista* q = p->prim;
    while(q!=NULL){
        Lista* t = q->prox;
        free(q);
        q = t;
    }
    free(p);
}

void pilha_imprimir(Pilha *p){
    Lista* q;
    for ( q = p->prim; q!= NULL; q=q->prox)
        printf("Valor armazenado: %.0f\n", q->info);
}