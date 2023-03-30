#include <stdio.h>
#include <stdlib.h>
#include "pilha_lista.c"



int main(void){

    Pilha *p; /* declarando uma pilha não iniciada */
    p = pilha_cria();
    pilha_push(p, 50);
    pilha_push(p, 33);
    pilha_push(p, 78);
    printf("\n#### Imprimir lista ####\n");
    pilha_imprimir(p);
    pilha_pop(p);
    printf("\n#### Imprimir lista ####\n");
    pilha_imprimir(p);


    pilha_libera(p);
    return 0;
}