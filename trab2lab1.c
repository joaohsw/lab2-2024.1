#include <stdio.h>
#include <stdlib.h>

struct municipio {

char* nome;
int populacao;
int** dados; //matriz de dados

}; 

typedef struct municipio Municipio;

Municipio preenche_vetor(Municipio *mun, int num){

    mun->nome = malloc(num * sizeof(char*));

    if(mun->nome == NULL){
        printf("Erro de alocacao de memoria");
        exit(1);
    }

    int i;

    for(i = 0; i < num; i++){
        mun->nome[i] = (char *) malloc(100 * sizeof(char));
        printf("Informe o nome do municipio %d: ", i + 1);
        scanf("%s", mun->nome[i]);
    }

}

int main(){

    int num;
    Municipio *mun;

    mun = (Municipio *) malloc(num*sizeof(Municipio));

    if(mun == NULL){
        printf("Erro de alocacao de memoria");
        exit(1);
    }

    printf("Informe o numero de municipios: ");
    scanf("%d", &num);

    preenche_vetor(mun, num);
    
    for(int i = 0; i < num; i++){
        printf("%s\n", mun->nome[i]);
    }

}
