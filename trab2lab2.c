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

int quant_dias(int n){

    printf("Informe quantos dias serao analisados: ");
    scanf("%d", &n);
    while (getchar() != '\n');

    return n;

}

void matriz_municipios(Municipio* municipios, int num_mun, int n) {

    int m = 3;

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

void relatorio1(Municipio* municipios, int num_mun, int n) {

    double maior_incidencia = 0;
    char nomemaior[100]; 

    for (int k = 0; k < num_mun; k++) {
        int total_confirmados = 0;
        
        for (int i = 0; i < n; i++) {
            total_confirmados += municipios[k].dados[i][0]; 
        }

        double incidencia = (double)(total_confirmados * 100) / municipios[k].populacao;
        incidencia *= 1000;

        if(maior_incidencia == 0){
            maior_incidencia = incidencia;
            strcpy(nomemaior, municipios[k].nome);
        } else if (maior_incidencia != 0 && incidencia > maior_incidencia){
            maior_incidencia = incidencia;
            strcpy(nomemaior, municipios[k].nome);

        }        
    }

    printf("\nMaior incidencia/100k habitantes: %s com %2.lf", nomemaior, maior_incidencia);

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
    int n; 
    n = quant_dias(n);
    matriz_municipios(municipios, num_mun, n);

    while(1){

        int opcao;

        printf("\n-> Digite o numero do relatorio que deseja acessar (qualquer outro para sair): ");
        printf("\n1. Municipio com maior incidencia");
        printf("\n2. Municipio com menor mortalidade");
        printf("\n3. Total de confirmados geral");
        printf("\n4. Total de obitos geral");
        printf("\n5. Quantidade de municipios sem novos obitos\n");

        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                relatorio1(municipios, num_mun, n);
                break;
            case 2: 
                break;
            case 3:
                break;
            case 4:
                break;
            case 5: 
                break;
            default:
                exit(1);
        }
        
    }

}
