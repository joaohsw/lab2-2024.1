#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct municipio {
    char* nome;
    int populacao;
    int** dados; //matriz de dados
};

typedef struct municipio Municipio;

int numero_municipios(int num_mun){

    scanf("%d", &num_mun);
    while (getchar() != '\n');

    return num_mun;

}

void nome_municipios(Municipio* municipios, int num_mun) {

    char buffer[100]; 

    for (int i = 0; i < num_mun; i++) {

        municipios[i].nome = malloc(100 * sizeof(char));

        if (municipios[i].nome == NULL) {
            printf("Erro ao alocar memoria para o nome.\n");
            exit(1);
        }

        printf("Informe o nome do municipio %d: ", i + 1);

        fgets(buffer, sizeof(buffer), stdin);

        buffer[strcspn(buffer, "\n")] = '\0';

        strcpy(municipios[i].nome, buffer);
    }

    printf("Nomes dos municipios:\n");

    for (int i = 0; i < num_mun; i++) {
        printf("%d: %s\n", i + 1, municipios[i].nome);
    }


}

void populacao_municipios(Municipio* municipios, int num_mun) {

    for (int i = 0; i < num_mun; i++) {

        printf("Informe a populacao de %s: ", municipios[i].nome);

        scanf("%d", &(municipios[i].populacao));

        while (getchar() != '\n');
    }

    printf("Populacao dos municipios:\n");

    for (int i = 0; i < num_mun; i++) {

        printf("%d: %s - Populacao: %d\n", i + 1, municipios[i].nome, municipios[i].populacao);

    }
}

void matriz_municipios(Municipio* municipios, int num_mun) {

    int n, m = 3;

    printf("Informe quantos dias serao analisados: ");
    scanf("%d", &n);
    while (getchar() != '\n');

    for (int k = 0; k < num_mun; k++) {
        municipios[k].dados = (int **)malloc(n * sizeof(int *));
        if (municipios[k].dados == NULL) {
            printf("Erro ao alocar memoria para matriz de dados.\n");
            exit(1);
        }

        for (int i = 0; i < n; i++) {
            municipios[k].dados[i] = (int *)malloc(m * sizeof(int));
            if (municipios[k].dados[i] == NULL) {
                printf("Erro ao alocar memoria para matriz de dados.\n");
                exit(1);
            }
        }
    }

    for (int k = 0; k < num_mun; k++) {
        printf("Preenchendo dados para o municipio %s:\n", municipios[k].nome);
        for (int i = 0; i < n; i++) {
            printf("Informe os dados para o dia %d:\n", i + 1);
            
            printf("Casos confirmados: ");
            scanf("%d", &(municipios[k].dados[i][0]));  
            while (getchar() != '\n');

            printf("Obitos: ");
            scanf("%d", &(municipios[k].dados[i][1]));  
            while (getchar() != '\n');
        }
    }
}




int main(){

    int num_mun;

    printf("Informe a quantidade de municipios: ");
    num_mun = numero_municipios(num_mun);

    Municipio* municipios = malloc(num_mun * sizeof(Municipio));

    if(municipios == NULL){
        printf("Erro ao alocar memoria");
        exit(1);
    }

    nome_municipios(municipios, num_mun);
    populacao_municipios(municipios, num_mun);
    matriz_municipios(municipios, num_mun);



}
