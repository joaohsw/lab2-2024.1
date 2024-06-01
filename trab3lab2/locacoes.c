#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "locacoes.h"
#include "lista.h"
#include "datas.h"

void limpar_buffer2() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}



void locar_veiculo(l_veiculos* lv, l_clientes* lc, l_locacoes* ll) {

    dados_locacao insercao;

    printf("\n> Locacao de veiculo\n");

    do {
        printf("\nInforme a CNH do cliente que deseja locar um veiculo: ");
        scanf("%ld", &insercao.cnh);
        for(l_clientes* p = lc; p != NULL; p = p->prox){
            if(p->info.cnh == insercao.cnh){
                printf("\nCliente encontrado: %s\n", p->info.nome);
                insercao.cnh = p->info.cnh;
                strcpy(insercao.nome, p->info.nome);
                break;
            }
            if(p->prox == NULL){
                printf("\nCliente nao encontrado, tente novamente\n");
                insercao.cnh = 0;
            }
        }
    } while (insercao.cnh == 0);

    do {
        printf("\nInforme a placa do veiculo que deseja locar: ");
        scanf("%s", insercao.placa);
        for(l_veiculos* p = lv; p != NULL; p = p->prox){
            if(strcmp(p->info.placa, insercao.placa) == 0 && p->info.disponivel == 1){
                printf("\nVeiculo encontrado: %s %s\n", p->info.marca, p->info.modelo);
                char aux[100];
                strcpy(aux, p->info.marca);
                strcat(aux, " ");
                strcat(aux, p->info.modelo);
                strcpy(insercao.marca_modelo, aux);
                p->info.disponivel = 0;
                break;
            }
            if(p->prox == NULL){
                printf("\nVeiculo nao encontrado ou nao esta disponivel, tente novamente\n");
                strcpy(insercao.placa, "");
            }
        }
    } while (strcmp(insercao.placa, "") == 0);

    int teste_data;

    do {
        
        printf("\nInforme a data de retirada do veiculo (DDMMAAAA): ");
        scanf("%d", &insercao.retirada);
        teste_data = data_valida(insercao.retirada);
        if(teste_data == 0){
            printf("\nData invalida, tente novamente\n");
        }

    } while (teste_data == 0);


}


void devolver_veiculo() {
    




    
}

void listar_locacoes() {
    // Implemente a listagem das locações se necessário
}
