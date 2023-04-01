/* Árvores com número variável de filhos */
/* Diferança da árvore binária "normal": Ela é limitada em apenas dois nós */

#include <stdio.h>
#include <stdlib.h>

#define N 3


struct arvvar{
    char info;
    struct arvvar *prim; /* ponteiro para eventual primeiro filho */
    struct arvvar *prox; /* ponteiro para eventual irmão */
};
typedef struct arvvar ArvVar;


/* Objetivo: Alocar um nó e inicializar seus campos */
ArvVar* arvv_cria(char c){
    ArvVar * a = (ArvVar *)malloc(sizeof(ArvVar));
    a->info = c;
    a->prim = NULL;
    a->prox = NULL;
    return a;
}

/* Objetivo: insere uma nova subárvore como filha de um dado nó */
void arvv_insere(ArvVar *a, ArvVar *sa){
    sa->prox = a->prim;
    a->prim = sa;
}

void arvv_imprime(ArvVar *a){
    ArvVar* p = a->prim;
    printf("<%c\n", a->info);
    while( p!= NULL ){
        arvv_imprime(p); /* imprime cada sub-árvore filha */
        p = p->prox;
    }
    printf(">");

}


void arvv_libera(ArvVar *a){
    ArvVar* p = a->prim;
    while(p!= NULL){
        ArvVar *t = p->prox;
        arvv_libera(p);
        p = t;
    }
    free(a);
}


int arvv_pertence (ArvVar* a , char c){
    ArvVar* p;
    if ( a->info == c)
        return 1;
    else{
        for ( p= a -> prim; p!= NULL; p=p->prox){
            if (arvv_pertence(p, c))
                return 1;
        }
        return 0;
    }
}

int main(void){
    
    /* cria nós como folhas */
    ArvVar* a = arvv_cria('a');
    ArvVar* b = arvv_cria('b');
    ArvVar* c = arvv_cria('c');
    ArvVar* d = arvv_cria('d');
    ArvVar* e = arvv_cria('e');
    ArvVar* f = arvv_cria('f');
    ArvVar* g = arvv_cria('g');
    ArvVar* h = arvv_cria('h');
    ArvVar* i = arvv_cria('i');
    ArvVar* j = arvv_cria('j');

    /* monta a hierarquia */
    arvv_insere(c,d);
    arvv_insere(b,e);
    arvv_insere(b,c);
    arvv_insere(i,j);
    arvv_insere(g,i);
    arvv_insere(g,h);
    arvv_insere(a,g);
    arvv_insere(a,f);
    arvv_insere(a,b);


    arvv_imprime(a);
    if(arvv_pertence(g, 'i'))
        printf("Pertence");

    arvv_libera(a);
    printf("\n");
    return 0;
}