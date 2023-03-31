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
    ArvVar* p;
    printf("<%c\n", a->info);
    for (p=a->prim; p!=NULL; p=p->prox);
        arvv_imprime(p);
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


int main(void){
    

    printf("\n");
    return 0;
}