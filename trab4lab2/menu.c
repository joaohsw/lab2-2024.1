#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include "fila.h"

void ticket_normal(fila **fila_normal) {

    int ticket;
    printf("Digite o ticket: ");
    scanf("%d", &ticket);
    insere_fila(fila_normal, ticket);

}

void ticket_prioritario(fila **fila_prioritaria) {

    int ticket;
    printf("Digite o ticket: ");
    scanf("%d", &ticket);
    insere_fila(fila_prioritaria, ticket);

}

void fusao_filas(fila **fila_normal, fila **fila_prioritaria, fila **fila_geral) {
    
    while (!fila_vazia(*fila_prioritaria) && tamanho_fila(*fila_geral) < 10) {
        insere_fila(fila_geral, remove_fila(fila_prioritaria));
    }
    
    while (!fila_vazia(*fila_normal) && tamanho_fila(*fila_geral) < 10) {
        insere_fila(fila_geral, remove_fila(*fila_normal));
    }
}

void bandejas(pilha **pilha) {

    int i;
    for (i = 0; i < 20; i++) {
        insere_pilha(pilha, i);
    }

}

void retirada_bandeja(pilha **pilha) {

    if (!pilha_vazia(*pilha)) {
        remove_pilha(pilha);
    } else {
        printf("Pilha vazia\n");
    }

}

void retirada_aluno(fila **fila_geral) {

    if (!fila_vazia(*fila_geral)) {
        remove_fila(fila_geral);
    } else {
        printf("Fila vazia\n");
    }

}

void impressao(fila *fila_normal, fila *fila_prioritaria, fila *fila_geral, pilha *pilha) {

    printf("\nFila normal: ");
    while (fila_normal != NULL) {
        printf("%d ", fila_normal->ticket);
        fila_normal = fila_normal->prox;
    }

    printf("\nFila prioritaria: ");
    while (fila_prioritaria != NULL) {
        printf("%d ", fila_prioritaria->ticket);
        fila_prioritaria = fila_prioritaria->prox;
    }

    printf("\nFila geral: ");
    while (fila_geral != NULL) {
        printf("%d ", fila_geral->ticket);
        fila_geral = fila_geral->prox;
    }

    printf("\nPilha: ");
    while (pilha != NULL) {
        printf("%d ", pilha->ticket);
        pilha = pilha->prox;
    }

}



void menu_principal(fila **fila_normal, fila **fila_prioritaria, fila **fila_geral, pilha **pilha){

    int input;

    while(1) {

        printf("\n> Menu <");
        printf("\n  1. Ingresso de alunos na fila de prioridade normal");
        printf("\n  2. Ingresso de alunos na fila de prioridade alta");
        printf("\n  3. Fusao das duas filas em uma fila unica para ingresso no restaurante");
        printf("\n  4. Colocacao de bandejas pelo funcionario do restaurante");
        printf("\n  5. Retirada de bandeja pelo aluno da fila unica");
        printf("\n  6. Retirada de aluno da fila única apos ter se servido no buffet");
        printf("\n  7. Impressao das 3 filas (normal, com prioridade e unica) e da pilha");
        printf("\n  0. voltar\n");

        scanf("%d", &input);

        switch (input) {
        case 1:
            ticket_normal(fila_normal);
            break;
        case 2:
            ticket_prioritario(fila_prioritaria);
            break;
        case 3:
            fusao_filas(fila_normal, fila_prioritaria, fila_geral);
            break;
        case 4:
            bandejas(pilha);
            break;
        case 5:
            retirada_bandeja(pilha);
            break;
        case 6:
            retirada_aluno(fila_geral);
            break;
        case 7:
            break;
        case 0:
            exit(0);
        default: 
            break;
        }
    }
}