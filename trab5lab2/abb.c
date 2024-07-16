#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "abb.h"

Curso* criar_curso(int codigo, const char* nome, const char* centro) {
    Curso* novo_curso = (Curso*)malloc(sizeof(Curso));
    if (!novo_curso) {
        printf("Erro ao alocar memoria para novo curso.\n");
        return NULL;
    }
    novo_curso->codigo = codigo;
    strncpy(novo_curso->nome, nome, sizeof(novo_curso->nome));
    strncpy(novo_curso->centro, centro, sizeof(novo_curso->centro));
    novo_curso->lista_alunos = NULL;
    novo_curso->esq = NULL;
    novo_curso->dir = NULL;
    return novo_curso;
}

Curso* adicionar_curso(Curso* raiz, int codigo, const char* nome, const char* centro) {
    if (!raiz) {
        return criar_curso(codigo, nome, centro);
    }

    if (codigo < raiz->codigo) {
        raiz->esq = adicionar_curso(raiz->esq, codigo, nome, centro);
    } else if (codigo > raiz->codigo) {
        raiz->dir = adicionar_curso(raiz->dir, codigo, nome, centro);
    }

    return raiz;
}

Curso* remover_curso(Curso* raiz, int codigo) {
    if (!raiz) {
        return NULL;
    }

    if (codigo < raiz->codigo) {
        raiz->esq = remover_curso(raiz->esq, codigo);
    } else if (codigo > raiz->codigo) {
        raiz->dir = remover_curso(raiz->dir, codigo);
    } else {
        if (!raiz->esq) {
            Curso* temp = raiz->dir;
            liberar_alunos(raiz->lista_alunos);
            free(raiz);
            return temp;
        } else if (!raiz->dir) {
            Curso* temp = raiz->esq;
            liberar_alunos(raiz->lista_alunos);
            free(raiz);
            return temp;
        }

        Curso* temp = raiz->dir;
        while (temp && temp->esq) {
            temp = temp->esq;
        }

        raiz->codigo = temp->codigo;
        strncpy(raiz->nome, temp->nome, sizeof(raiz->nome));
        strncpy(raiz->centro, temp->centro, sizeof(raiz->centro));
        raiz->lista_alunos = temp->lista_alunos;
        raiz->dir = remover_curso(raiz->dir, temp->codigo);
    }

    return raiz;
}

Curso* buscar_curso(Curso* raiz, int codigo) {
    if (!raiz || raiz->codigo == codigo) {
        return raiz;
    }

    if (codigo < raiz->codigo) {
        return buscar_curso(raiz->esq, codigo);
    } else {
        return buscar_curso(raiz->dir, codigo);
    }
}

void imprimir_cursos(Curso* raiz) {
    if (raiz) {
        imprimir_cursos(raiz->esq);
        printf("Codigo do Curso: %d, Nome do Curso: %s, Centro: %s\n", raiz->codigo, raiz->nome, raiz->centro);
        imprimir_alunos(raiz);
        imprimir_cursos(raiz->dir);
    }
}

void liberar_arvore(Curso* raiz) {
    if (raiz) {
        liberar_arvore(raiz->esq);
        liberar_arvore(raiz->dir);
        liberar_alunos(raiz->lista_alunos);
        free(raiz);
    }
}

// Funções para alunos
Aluno* criar_aluno(int matricula, const char* nome) {
    Aluno* novo_aluno = (Aluno*)malloc(sizeof(Aluno));
    if (!novo_aluno) {
        printf("Erro ao alocar memória para novo aluno.\n");
        return NULL;
    }
    novo_aluno->matricula = matricula;
    strncpy(novo_aluno->nome, nome, sizeof(novo_aluno->nome));
    novo_aluno->prox = NULL;
    return novo_aluno;
}

void adicionar_aluno(Curso* curso, int matricula, const char* nome) {
    Aluno* novo_aluno = criar_aluno(matricula, nome);
    if (!curso->lista_alunos) {
        curso->lista_alunos = novo_aluno;
    } else {
        Aluno* temp = curso->lista_alunos;
        while (temp->prox) {
            temp = temp->prox;
        }
        temp->prox = novo_aluno;
    }
}

void remover_aluno(Curso* curso, int matricula) {
    Aluno* temp = curso->lista_alunos;
    Aluno* anterior = NULL;

    while (temp && temp->matricula != matricula) {
        anterior = temp;
        temp = temp->prox;
    }

    if (!temp) {
        printf("Aluno com matricula %d nao encontrado.\n", matricula);
        return;
    }

    if (!anterior) {
        curso->lista_alunos = temp->prox;
    } else {
        anterior->prox = temp->prox;
    }

    free(temp);
}

void imprimir_alunos(Curso* curso) {
    Aluno* temp = curso->lista_alunos;
    while (temp) {
        printf("  Matrícula: %d, Nome: %s\n", temp->matricula, temp->nome);
        temp = temp->prox;
    }
}

void liberar_alunos(Aluno* lista_alunos) {
    Aluno* temp;
    while (lista_alunos) {
        temp = lista_alunos;
        lista_alunos = lista_alunos->prox;
        free(temp);
    }
}
