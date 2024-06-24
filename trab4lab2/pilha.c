#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

pilha* cria_pilha() {
    return NULL;
}

void insere_pilha(pilha **p, int ticket) {

    pilha *novo = (pilha*) malloc(sizeof(pilha));
    if (novo == NULL) {
        printf("Erro ao alocar memoria\n");
        exit(1);
    }
    novo->ticket = ticket;
    novo->prox = *p;
    *p = novo;
}

int remove_pilha(pilha **p) {

    if (*p == NULL) {
        printf("Pilha vazia\n");
        return -1;
    }

    pilha *temp = *p;
    int ticket = temp->ticket;
    *p = temp->prox;
    free(temp);
    return ticket;

}

int pilha_vazia(pilha *p) {
    return (p == NULL);
}

void libera_pilha(pilha *p) {
    while (p != NULL) {
        pilha *temp = p;
        p = p->prox;
        free(temp);
    }
}

