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



void locar_veiculo(l_veiculos* lv, l_clientes* lc, l_locacoes** ll) {

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
                insercao.diaria = p->info.diaria;
                insercao.quilometragem = p->info.quilometragem;
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

    *ll = l_insere_locacao(*ll, insercao);

}


void devolver_veiculo(l_veiculos* lv, l_clientes* lc, l_locacoes* ll) {

    dados_locacao remocao;
    int teste_data, teste_data2;
    int devolucao;
    int nova_quilometragem;
    float diaria;
    
    printf("\n> Devolucao de veiculo\n");
    printf("\nInforme a placa do veiculo que deseja devolver: ");
    char placa[50];
    scanf("%s", placa);

    for(l_locacoes* p = ll; p != NULL; p = p->prox){
        if(strcmp(p->info.placa, placa) == 0){
            printf("\nVeiculo encontrado: %s\n", p->info.marca_modelo);
            printf("\nCliente: %s\n", p->info.nome);
            printf("\nData de retirada: %d\n", p->info.retirada);
            do {
                printf("\nInforme a data de devolucao do veiculo (DDMMAAAA): ");
                scanf("%d", &devolucao);
                teste_data = data_valida(devolucao);
                teste_data2 = compara_datas(p->info.retirada, devolucao);
                if(teste_data == 0 || teste_data2 == 0){
                    printf("\nData invalida, tente novamente\n");
                }
            } while (teste_data == 0 || teste_data2 == 0);

            p->info.devolucao = devolucao;
            p->info.valor_total = diferenca_de_dias(p->info.retirada, p->info.devolucao) * p->info.diaria;

            do {
                printf("\nInforme a nova quilometragem do veiculo: ");
                scanf("%d", &nova_quilometragem);
                if(nova_quilometragem < p->info.quilometragem){
                    printf("\nQuilometragem invalida, tente novamente\n");
                }
            } while (nova_quilometragem < p->info.quilometragem);
            p->info.quilometragem = nova_quilometragem;
            break;
        }
    }

    for(l_veiculos* p = lv; p != NULL; p = p->prox){
        if(strcmp(p->info.placa, placa) == 0){
            p->info.disponivel = 1;
            break;
        }
    }
}

void listar_locacoes(l_locacoes* ll) {

    for(l_locacoes* p = ll; p != NULL; p = p->prox) {
        printf("\n> Locacao\n");
        printf("Nome: %s\n", p->info.nome);
        printf("CNH: %d\n", p->info.cnh);
        printf("Marca/Modelo: %s\n", p->info.marca_modelo);
        printf("Data de retirada: %d\n", p->info.retirada);
        if(p->info.devolucao != 0){
            printf("Data de devolucao: %d\n", p->info.devolucao);
        }
        else {
            printf("Data de devolucao: ainda nao devolvido\n");
        }
        if(p->info.valor_total != 0){
            printf("Valor total: %.2f\n", p->info.valor_total);
        }
        else {
            printf("Valor total: ainda nao calculado\n");
        }
    }

}
