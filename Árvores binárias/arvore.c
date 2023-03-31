#include <stdio.h>
#include <stdlib.h>

/* Estrutura de C para representar o nó da árvore */
struct arv{
    char info;
    struct arv* esq;
    struct arv* dir;
};
typedef struct arv Arv;

/* Reprentação de uma árvore vazia */
Arv* arv_criavazia(void){
    return NULL;
}

/* Objetivo: criar uma nó raiz dadas a informação e as duas subárvores, a da esquerda e a da direita */
Arv* arv_cria(char c, Arv* sae, Arv* sad){
    Arv* p = (Arv*)malloc(sizeof(Arv));
    p->info = c;
    p->esq = sae;
    p->dir = sad;
    return p;
}


/* Objetivo: verificar se a árvore está vazia */
int arv_vazia(Arv* a){
    return a==NULL;
}

/* Objeetivo: liberar memória */
Arv* arv_libera(Arv* a){
    if(!arv_vazia(a)){
        arv_libera(a->esq); /* libera sae */
        arv_libera(a->dir); /* libera sad */
        free(a); /* libera raiz */
    }
    return NULL;
}

/* Imprimir os nós da árvore */
/* <nó subarvore subarbore>*/
/* Cada nó e sub árvore é delimitado por <>*/
void arv_imprime(Arv* a){
    printf("<"); /* Mostrando a posição */
    if(!arv_vazia(a)){
        printf("%c ", a->info); /* mostra raiz */
        arv_imprime(a->esq); /* mostra sae */
        arv_imprime(a->dir); /* mostra sad */
    }
    printf(">"); /* Mostrando a posição */
}


/* Recebe o nó e o caractere que quer verificar se pertence ao nó introduzido */
int arv_pertence(Arv* a, char c){
    if(arv_vazia(a))
        return 0; /* árvore vazia: não encontrou */
    else
        return a->info==c || arv_pertence(a->esq, c) || arv_pertence(a->dir, c);

}






int main(void){
    

    /* Uma das formas que podemos representar árvore binária */
    /* sub-árvore 'd' */
    Arv* a1 = arv_cria('d', arv_criavazia(), arv_criavazia());
    /* sub-árvore 'b' */
    Arv* a2 = arv_cria('b', arv_criavazia(), a1);  
    /* sub-árvore 'e' */  
    Arv* a3 = arv_cria('e', arv_criavazia(), arv_criavazia());  
    /* sub-árvore 'f' */  
    Arv* a4 = arv_cria('f', arv_criavazia(), arv_criavazia());  
    /* sub-árvore 'c' */
    Arv* a5 = arv_cria('c', a3, a4);
    /* árvore 'a' */
    Arv* a = arv_cria('a', a2, a5); 

    arv_libera(a); /* Liberando primeira representação de árvore binária */
    /* Outra forma que podemos representar de forma recursiva */

    Arv* aa = arv_cria('a',
        arv_cria('b', 
            arv_criavazia(), 
            arv_cria('d', arv_criavazia(), arv_criavazia())
        ),
        arv_cria('c',
            arv_cria('e', arv_criavazia(), arv_criavazia()),
            arv_cria('f', arv_criavazia(), arv_criavazia())
        )
    );
    printf("\n # VERIFICANDO # \n");
    arv_imprime(aa);

    /* acrescentando alguns nós */
    aa->esq->esq = arv_cria('x',
        arv_cria('y', arv_criavazia(), arv_criavazia()),
        arv_cria('z', arv_criavazia(), arv_criavazia())
    );
    printf("\n # VERIFICANDO # \n");
    arv_imprime(aa);

    /* removendo alguns nó */
    aa->dir->esq = arv_libera(aa->dir->esq);
    printf("\n # VERIFICANDO # \n");
    arv_imprime(aa);

    /* Verifiacndo a função 'arv_pertence' */
    if(arv_pertence(aa, 'b'))
        printf("\n\n # Verificando função pertence: 'b' pertence ao nó # \n");



    printf("\n");
    arv_libera(aa); /* Liberando segunda representação de árvore binária */
    return 0;
}