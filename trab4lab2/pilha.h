#ifndef PILHA_H
#define PILHA_H

typedef struct pilha {
    int ticket;
    struct pilha *prox;
    int proxima_bandeja;  
} pilha;


pilha* cria_pilha();
void insere_pilha(pilha **p, int ticket);
int remove_pilha(pilha **p);
int pilha_vazia(pilha *p);
int proxima_bandeja(pilha *p);
void libera_pilha(pilha *p);


#endif
