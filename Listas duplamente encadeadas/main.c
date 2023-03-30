#include <stdio.h>
#include <stdlib.h>


struct lista{
    int info;
    struct lista* ant;
    struct lista* prox;
};

typedef struct lista Lista;

/* Objetivo: criar uma lista vazia que tem como valor de retorno uma lista sem nenhum elemento */
Lista* lst_cria(void){
    return NULL;
}


/* Objetivo: inserção no inicio */
Lista* lst_insere ( Lista* l, int v){
    Lista* novo = (Lista *)malloc(sizeof(Lista));
    novo-> info = v;
    novo->prox = l;
    novo->ant = NULL;

    /* verifica se a lista não está vazia */
    if ( l != NULL )
        l->ant = novo;
    return novo;
}

/* Objetivo: procurar elemento na lista */
Lista* lst_busca(Lista *l, int v){
    Lista* p; /* variável auxiliar para percorrer a lista */
    for ( p = l; p!= NULL; p = p->prox){
        if (p->info == v)
            return p; /* retorna o elemento encontrado*/
    }
    return NULL; /* retorna NULL caso não encontre o elemento */
}


Lista* lst_retira(Lista* l, int v){
    Lista* p = lst_busca(l, v); /* Buscando elemento */

    if ( p == NULL )
        return l; /* não achou o elemento: retorna lista sem alterações */

    if ( l == p ) /* testa se é o primeiro elemento */
        l = p->prox;
    else
        p->ant->prox = p->prox;
    
    if(p->prox != NULL) /* testa se é o último elemento */
        p->prox->ant = p->ant;
    
    free(p);
    return l;
}

/* Objetivo: imprimir a lista */
void lst_imprime(Lista *l){
    Lista *p; /* variável auxiliar para percorrer a lista */
    for ( p = l; p != NULL; p = p->prox) /* p vai receber a lista atual através do parâmetro e apenas pecorrer os elementos dela */
        printf("info: %d\n", p->info);
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