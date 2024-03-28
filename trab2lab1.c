#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct municipio {
    char** nome;
    int populacao;
    int** dados; // matriz de dados
}; 

typedef struct municipio Municipio;

int leitura_quantidade(){

    int num;

    printf("Informe o numero de municipios: ");
    scanf("%d", &num);

    return num;

}

void preenche_vetor(Municipio *mun, int num) {

    mun->nome = malloc(num * sizeof(char*));

    if(mun->nome == NULL){
        printf("Erro de alocacao de memoria");
        exit(1);
    }

    for(int i = 0; i < num; i++){
        mun->nome[i] = malloc(100 * sizeof(char));

        if(mun->nome[i] == NULL){
            printf("Erro de alocacao de memoria");
            exit(1);
        }

        printf("Informe o nome do municipio %d: ", i + 1);
        fgets(mun->nome[i], 100, stdin); 

        if (mun->nome[i][strlen(mun->nome[i]) - 1] == '\n'){
            mun->nome[i][strlen(mun->nome[i]) - 1] = '\0';
        }
    }
}

void preenche_populacao(Municipio *mun, int num){

    mun->populacao = malloc(num * sizeof(int*));

    if(mun->populacao == NULL){
        printf("Erro de alocacao de memoria");
        exit(1);
    }

    int i;

    for(i = 0; i < num; i++){
        printf("Informe a populacao do municipio %s: ", mun->nome[i]);
        scanf("%d", mun->populacao[i]);
    }

}

int main(){
    
    int num;
    Municipio mun;

    num = leitura_quantidade();
    getchar(); // Limpar o buffer de entrada

    preenche_vetor(&mun, num);
    
    for(int i = 0; i < num; i++){
        printf("%s\n", mun.nome[i]);
        free(mun.nome[i]);
    }

    preenche_populacao(&mun, num);

    free(mun.nome); // Liberar memória alocada para o vetor de nomes

    return 0;
}
