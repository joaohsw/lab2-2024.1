#ifndef ABB_H
#define ABB_H

typedef struct aluno {
    int matricula;
    char nome[50];
    struct aluno* prox;
} Aluno;

typedef struct curso {
    int codigo;
    char nome[30];
    char centro[40];
    Aluno* lista_alunos;
    struct curso* esq;
    struct curso* dir;
} Curso;

Curso* criar_curso(int codigo, const char* nome, const char* centro);
Curso* adicionar_curso(Curso* raiz, int codigo, const char* nome, const char* centro);
Curso* remover_curso(Curso* raiz, int codigo);
Curso* buscar_curso(Curso* raiz, int codigo);
void imprimir_cursos(Curso* raiz);
void liberar_arvore(Curso* raiz);

Aluno* criar_aluno(int matricula, const char* nome);
void adicionar_aluno(Curso* curso, int matricula, const char* nome);
void remover_aluno(Curso* curso, int matricula);
void imprimir_alunos(Curso* curso);
void liberar_alunos(Aluno* lista_alunos);

#endif
