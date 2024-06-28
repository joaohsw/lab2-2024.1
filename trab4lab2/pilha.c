#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

pilha* cria_pilha() {
    return NULL;
}

void insere_pilha(pilha **p, int ticket) {
    pilha *novo = (pilha *)malloc(sizeof(pilha));
    novo->ticket = ticket;
    novo->prox = *p;
    novo->proxima_bandeja = ticket + 1; 
    *p = novo;
}

int remove_pilha(pilha **p) {
    if (*p == NULL) {
        return -1; // Pilha vazia
    }
    pilha *temp = *p;
    int ticket = temp->ticket;
    *p = temp->prox;
    free(temp);
    return ticket;
}

int pilha_vazia(pilha *p) {
    return p == NULL;
}

int proxima_bandeja(pilha *p) {
    if (p == NULL) {
        return 0; 
    }
    return p->proxima_bandeja;
}

void libera_pilha(pilha *p) {
    while (p != NULL) {
        pilha *temp = p;
        p = p->prox;
        free(temp);
    }
}

