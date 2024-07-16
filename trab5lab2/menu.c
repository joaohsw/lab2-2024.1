#include <stdio.h>
#include <stdlib.h>
#include "abb.h"
#include "menu.h"

void opcao1(Curso** raiz) {
    int codigo;
    char nome[30];
    char centro[40];

    printf("Insira o código do curso: ");
    scanf("%d", &codigo);
    printf("Insira o nome do curso: ");
    scanf("%s", nome);
    printf("Insira o centro do curso: ");
    scanf("%s", centro);

    *raiz = adicionar_curso(*raiz, codigo, nome, centro);
}

void opcao2(Curso** raiz) {
    int codigo;

    printf("Insira o código do curso a ser removido: ");
    scanf("%d", &codigo);

    *raiz = remover_curso(*raiz, codigo);
}

void opcao3(Curso* raiz) {
    int codigo;
    int matricula;
    char nome[50];

    printf("Insira o codigo do curso: ");
    scanf("%d", &codigo);
    Curso* curso = buscar_curso(raiz, codigo);
    if (!curso) {
        printf("Curso nao encontrado.\n");
        return;
    }

    printf("Insira a matricula do aluno: ");
    scanf("%d", &matricula);
    printf("Insira o nome do aluno: ");
    scanf("%s", nome);

    adicionar_aluno(curso, matricula, nome);
}

void opcao4(Curso* raiz) {
    int codigo;
    int matricula;

    printf("Insira o codigo do curso: ");
    scanf("%d", &codigo);
    Curso* curso = buscar_curso(raiz, codigo);
    if (!curso) {
        printf("Curso nao encontrado.\n");
        return;
    }

    printf("Insira a matricula do aluno a ser removido: ");
    scanf("%d", &matricula);

    remover_aluno(curso, matricula);
}

void opcao5(Curso* raiz) {
    int codigo;

    printf("Insira o codigo do curso para listar os alunos: ");
    scanf("%d", &codigo);
    Curso* curso = buscar_curso(raiz, codigo);
    if (!curso) {
        printf("Curso nao encontrado.\n");
        return;
    }

    imprimir_alunos(curso);
}

void opcao6(Curso* raiz) {
    imprimir_cursos(raiz);
}

void menu_principal(Curso* raiz) {
    int input;

    while (1) {
        printf("\n> Menu <");
        printf("\n  1. Inserir curso");
        printf("\n  2. Remover curso");
        printf("\n  3. Inserir aluno em curso");
        printf("\n  4. Remover aluno de curso");
        printf("\n  5. Imprimir alunos de curso");
        printf("\n  6. Imprimir todos os cursos");
        printf("\n  0. Sair\n");

        printf("\nEscolha uma opçao: ");
        scanf("%d", &input);

        switch (input) {
            case 1:
                opcao1(&raiz);
                break;
            case 2:
                opcao2(&raiz);
                break;
            case 3:
                opcao3(raiz);
                break;
            case 4:
                opcao4(raiz);
                break;
            case 5:
                opcao5(raiz);
                break;
            case 6:
                opcao6(raiz);
                break;
            case 0:
                liberar_arvore(raiz);
                exit(0);
            default:
                printf("Opcao invalida!\n");
                break;
        }
    }
}
