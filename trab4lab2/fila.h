#ifndef FILA_H
#define FILA_H

typedef struct fila {
    int ticket;
    struct fila *prox;
} fila;

fila* cria_fila();
void insere_fila(fila **f, int ticket);
int remove_fila(fila **f);
int fila_vazia(fila *f);
void libera_fila(fila *f);
int tamanho_fila(fila *f);

#endif 
