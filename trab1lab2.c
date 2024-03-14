#include <stdio.h>
#include <string.h>
#include <math.h>

#define TAM 2

struct pessoa {
    int codigo;
    char nome[81];
    float peso;
    int altura;
    float IMC;
    char faixa[15];
};

typedef struct pessoa Pessoa;

Pessoa leitura(Pessoa dados){

    printf("\nInsira o codigo: ");
    scanf("%d", &dados.codigo);
    printf("\nInsira o nome: ");
    scanf("%s", dados.nome);
    printf("\nInsira o peso (em kg): ");
    scanf("%f", &dados.peso);
    printf("\nInsira a altura (em cm): ");
    scanf("%d", &dados.altura);

    dados.IMC = dados.peso / (pow(dados.altura, 2) / 10000); 
    
    if (dados.IMC < 18.5) {
        strcpy(dados.faixa, "Magreza");
    } else if (dados.IMC >= 18.5 && dados.IMC < 25) {
        strcpy(dados.faixa, "Normal");
    } else if (dados.IMC >= 25 && dados.IMC <= 30) {
        strcpy(dados.faixa, "Sobrepeso");
    } else if (dados.IMC > 30) {
        strcpy(dados.faixa, "Obesidade");
    }

    return dados;
 
}

float calculo_media (Pessoa dados[TAM]){

    int i;
    float total, media;

    for(i = 1; i <= TAM; i++){
        total += dados[i].peso;
    }

    media = total / TAM;

    return media;

}

void relatorio1(Pessoa dados[TAM]){

    printf("\n> Relatorio 1, dados gerais: ");

    int i;

    for(i = 1; i <= TAM; i++){
        printf("\nCodigo pessoa %d: %d\n", i, dados[i].codigo);
        printf("\nNome pessoa %d: %s\n", i, dados[i].nome);
        printf("\nPeso pessoa %d: %f\n", i, dados[i].peso);
        printf("\nAltura pessoa %d: %d\n", i, dados[i].altura);
        printf("\nIMC pessoa %d: %f\n", i, dados[i].IMC);
        printf("\nFaixa pessoa %d: %s\n", i, dados[i].faixa);

    }
}

void relatorio2(Pessoa dados[TAM]){

    int i;

    printf("\n> Relatorio 2, pessoas com sobrepeso: ");

    for(i = 1; i <= TAM; i++){
        if (strcmp(dados[i].faixa, "Sobrepeso") == 0) {
            printf("%s\n", dados[i].nome);
        }
    }

}

void relatorio3(Pessoa dados[TAM]){

    int i;

    printf("\n> Relatorio 3, pessoas com obesidade: ");

    for(i = 1; i <= TAM; i++){
        if (strcmp(dados[i].faixa, "Obesidade") == 0) {
            printf("%s\n", dados[i].nome);
        }
    }

}

void relatorio4(Pessoa dados[TAM], float media){

    printf("\n> Relatorio 4, media de peso: \n");
    printf("%f\n", media);
    
}

void relatorio5(Pessoa dados[TAM], float media){

    int i;

    printf("\n> Relatorio 5, pessoas acima da media de peso: ");

    for(i = 1; i <= TAM; i++){
        if(dados[i].peso > media){
            printf("\n%s", dados[i].nome);
        }
    }

}

void relatorio6(Pessoa dados[TAM]){

    printf("\n> Relatorio 6, pessoas que nao estao na faixa normal de peso: ");

    int i; 

    for(i = 1; i <= TAM; i++){
        if(strcmp(dados[i].faixa, "Normal") != 0){
            printf("\n%s", dados[i].nome);
        }
    }
}

void relatorio7(Pessoa dados[TAM], float media){

    printf("\n> Relatorio 7, pessoas que tem peso normal e pesam menos que a media");

    int i;

    for(i = 1; i <= TAM; i++){
        if(strcmp(dados[i].faixa, "Normal") == 0 && dados[i].peso < media){
            printf("\n%s", dados[i].nome);
        }
    }
}

void relatorio8(Pessoa dados[TAM]){

    printf("\n> Relatorio 8, pessoa(s) com o maior IMC");

    int i;
    float maior = 0;

    for(i = 1; i <= TAM; i++){
        if(maior == 0){
            maior = dados[i].IMC;
        } else if(dados[i].IMC > maior){
            maior = dados[i].IMC;
        } 
    }

    for(i = 1; i <= TAM; i++){
        if(dados[i].IMC == maior){
            printf("\n%s", dados[i].nome);
        }
    }

}

void relatorio9(Pessoa dados[TAM]){

    printf("\n> Relatorio 9, pessoa(s) com o menor IMC");

    int i;
    float menor = 1000;

    for(i = 1; i <= TAM; i++){
        if(menor == 1000){
            menor = dados[i].IMC;
        } else if(dados[i].IMC < menor){
            menor = dados[i].IMC;
        } 
    }

    for(i = 1; i <= TAM; i++){
        if(dados[i].IMC == menor){
            printf("\n%s", dados[i].nome);
        }
    }

}

int main() {

    int vez = 1;
    float media;

    Pessoa dados[TAM];

    while(vez <= TAM){
        printf("\nLeitura de dados pessoa numero %d", vez);
        dados[vez] = leitura(dados[vez]);
        vez++;
    }

    media = calculo_media(dados);

    printf("\n- Fim da leitura - \n> Exibindo relatorios:\n");
    relatorio1(dados);
    relatorio2(dados);
    relatorio3(dados);
    relatorio4(dados, media);
    relatorio5(dados, media);
    relatorio6(dados);
    relatorio7(dados, media);
    relatorio8(dados);
    relatorio9(dados);

}