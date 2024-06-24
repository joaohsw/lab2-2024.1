#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

fila* cria_fila() {
    return NULL; 
}

void insere_fila(fila **f, int ticket) {

    fila *novo = (fila*) malloc(sizeof(fila));
    if (novo == NULL) {
        printf("Erro ao alocar memoria\n");
        exit(1);
    }
    novo->ticket = ticket;
    novo->prox = NULL;

    if (*f == NULL) {
        *f = novo;
    } else {
        fila *temp = *f;
        while (temp->prox != NULL) {
            temp = temp->prox;
        }
        temp->prox = novo;
    }
}

int remove_fila(fila **f) {

    if (*f == NULL) {
        printf("Fila vazia\n");
        return -1; 
    }
    
    fila *temp = *f;
    int ticket = temp->ticket;
    *f = temp->prox;
    free(temp);
    return ticket;
    
}

int fila_vazia(fila *f) {
    return (f == NULL);
}

void libera_fila(fila *f) {
    while (f != NULL) {
        fila *temp = f;
        f = f->prox;
        free(temp);
    }
}