#include <stdio.h>
#include <stdlib.h>

struct lista {
    int info;
    struct lista* prox;
};

typedef struct lista Lista;

/* Objetivo: criar uma lista vazia que tem como valor de retorno uma lista sem nenhum elemento */
Lista* lst_cria(void){
    return NULL;
}

/* Objetivo: inserção no inicio: retorna a lista atualizada */
Lista* lst_insere ( Lista *l, int i){
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    novo-> info = i;
    novo->prox = l;
    return novo;
}

/* Objetivo: imprimir a lista */
void lst_imprime(Lista *l){
    Lista *p; /* variável auxiliar para percorrer a lista */
    for ( p = l; p != NULL; p = p->prox) /* p vai receber a lista atual através do parâmetro e apenas pecorrer os elementos dela */
        printf("info: %d\n", p->info);
}

/* Objetivo: verificar se a lista está vazia */
int lst_vazia(Lista* l){
    return( l == NULL );
}

/* Objetivo: buscar elemento dentro da lista */
Lista* lst_busca(Lista *l, int v){
    Lista *p; /* variável auxiliar para percorrer a lista */
    for ( p = l; p != NULL; p = p-> prox){
        if ( p->info == v)
            return p;
    }
    return NULL; /* não achou o elemento */
}

/* Objetivo: retirar elemento da lista */
Lista* lst_retira(Lista* l, int v){
    Lista* ant = NULL; /* Ponteiro para elemento anterior */
    Lista* p = l; /* ponteiro para percorrer a lista */

    /* procura elemento na lista guardando anterior */
    while(p!= NULL && p->info != v){
        ant = p;
        p = p->prox;
    }

    /* verificando se achou o elemento */
    if ( p == NULL )
        return l; /* não achou elemento, logo, retorna a lista original */
    
    /* caso o elemento seja o primeiro */
    if ( ant == NULL )
        l = p-> prox;
    else
        ant->prox = p->prox; /* retira elemento do meio da lista */

    free(p);
    return l;
}

/* Objetivo: liberar lista */
void lst_libera(Lista* l){
    Lista *p = l;
    while( p!= NULL){
        Lista* t = p->prox; /* Guarda referência para o próximo elemento */
        free(p); /* Libera elemento para qual o apontador está atualmente */
        p = t; /* Faz p apontar para o próximo */
    }
}


/* Objetivo: ordenar elementos da lista */
Lista* lst_insere_ordenado(Lista* l, int v){
    Lista* novo;
    Lista* ant = NULL;
    Lista* p = l;

    while(p!=NULL && p->info < v){
        ant = p;
        p = p->prox;
    }

    /* cria novo elemento */
    novo = (Lista *)malloc(sizeof(Lista));
    novo->info = v;

    /* encadeia elemento */
    if ( ant == NULL ){
        novo->prox = l;
        l = novo;
    }
    else{
        novo->prox = ant->prox;
        ant->prox = novo;
    }
    return l;
}

int main(void){
    Lista *l; /* declara uma lista não inicializada */
    l = lst_cria(); /* cria e incializa lista como vazia */
    l = lst_insere(l, 23); /* insere na lista o elemento 23 */ 
    l = lst_insere(l, 45); /* insere na lista o elemento 45 */ 
    l = lst_insere(l, 56); /* ... */ 
    l = lst_insere(l, 78); /* ... */
    printf("\n### Verificando elementos ###\n");
    lst_imprime(l);
    l = lst_retira(l, 78);
    printf("\n### Verificando elementos ###\n");
    lst_imprime(l);
    lst_libera(l);


    return 0;
}