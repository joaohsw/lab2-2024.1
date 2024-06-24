#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include "fila.h"

void menu_principal(){

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
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 0:
            exit;
        default: 
            break;
        }
    }
}