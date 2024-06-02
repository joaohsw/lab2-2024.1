#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "lista.h"
#include "locacoes.h"
#include "relatorios.h"
#include "datas.h"

void relatorio1(l_veiculos* lv, l_clientes* lc, l_locacoes* ll){

    int data;
    int data_dias;

    printf("\n> Relatorio 1\n");
    printf("\nInforme uma data no formato DDMMAAAA: ");
    scanf("%d", &data);

    data_dias = converter_para_dias(data);

    for(l_locacoes* p = ll; p != NULL; p = p->prox){
        int data_dias_retirada, data_dias_devolucao;
        data_dias_retirada = converter_para_dias(p->info.retirada);
        data_dias_devolucao = converter_para_dias(p->info.devolucao);
        if(data_dias >= data_dias_retirada && data_dias <= data_dias_devolucao){
            printf("\n> Locacao ativa dia %d\n", data);
            printf("Placa: %s\n", p->info.placa);
            printf("Marca/Modelo: %s\n", p->info.marca_modelo);
            printf("Nome do cliente: %s\n", p->info.nome);
            printf("Data de retirada: %d\n", p->info.retirada);
            printf("Data de devolucao: %d\n", p->info.devolucao);
            printf("Valor total: %.2f\n", p->info.valor_total);
        }
    }
}

void relatorio2(l_veiculos* lv, l_clientes* lc, l_locacoes* ll){

    printf("\n> Relatorio 2\n");
    printf("\nInforme um CNH valido para consultar as locacoes: ");
    long int cnh;
    scanf("%ld", &cnh);
    
    for(l_locacoes* p = ll; p != NULL; p = p->prox){
        if(p->info.cnh == cnh){
            printf("\n> Locacao realizada pelo CNH %d\n", cnh);
            printf("Nome: %s\n", p->info.nome);
            printf("CNH: %d\n", p->info.cnh);
            printf("Marca/Modelo: %s\n", p->info.marca_modelo);
            printf("Data de retirada: %d\n", p->info.retirada);
            printf("Data de devolucao: %d\n", p->info.devolucao);
            printf("Valor total: %.2f\n", p->info.valor_total);
        }
    }
}

void relatorio3(l_veiculos* lv, l_clientes* lc, l_locacoes* ll) {
    int mes, ano;
    float faturamento_total = 0.0;

    printf("\n> Relatorio 3\n");
    printf("\nInforme um mes para consultar o faturamento (MM): ");
    scanf("%d", &mes);
    printf("\nInforme um ano para consultar o faturamento (AAAA): ");
    scanf("%d", &ano);

    for (l_locacoes* p = ll; p != NULL; p = p->prox) {
        int dia_retirada, mes_retirada, ano_retirada, dia_devolucao, mes_devolucao, ano_devolucao;

        dia_retirada = p->info.retirada / 1000000;
        mes_retirada = (p->info.retirada / 10000) % 100;
        ano_retirada = p->info.retirada % 10000;

        dia_devolucao = p->info.devolucao / 1000000;
        mes_devolucao = (p->info.devolucao / 10000) % 100;
        ano_devolucao = p->info.devolucao % 10000;

        int total_dias_locacao = diferenca_de_dias(p->info.retirada, p->info.devolucao);
        float valor_diario = p->info.valor_total / total_dias_locacao;

        if (ano_retirada == ano && mes_retirada == mes) {
            int dias_restantes_mes_retirada = dias_no_mes(mes_retirada, ano_retirada) - dia_retirada + 1;
            faturamento_total += dias_restantes_mes_retirada * valor_diario;
        }

        if (ano_devolucao == ano && mes_devolucao == mes) {
            int dias_devolucao_mes = dia_devolucao;
            faturamento_total += dias_devolucao_mes * valor_diario;
        }

        if (ano_retirada == ano && ano_devolucao == ano && mes_retirada < mes && mes_devolucao > mes) {
            int dias_mes = dias_no_mes(mes, ano);
            faturamento_total += dias_mes * valor_diario;
        }
    }

    printf("\nFaturamento total no mes %02d/%04d: %.2f\n", mes, ano, faturamento_total);
}

void relatorio4(l_veiculos* lv, l_clientes* lc, l_locacoes* ll){

    char maior[3][50];
    int maior_km[3] = {0, 0, 0};

    printf("\n> Relatorio 4\n");
    printf("\nPlaca dos 3 veiculos com a maior quilometragem: ");

    for(l_veiculos* p = lv; p != NULL; p = p->prox){
        if(p->info.quilometragem > maior_km[0]){
            maior_km[2] = maior_km[1];
            strcpy(maior[2], maior[1]);
            maior_km[1] = maior_km[0];
            strcpy(maior[1], maior[0]);
            maior_km[0] = p->info.quilometragem;
            strcpy(maior[0], p->info.placa);
        }
        else if(p->info.quilometragem > maior_km[1]){
            maior_km[2] = maior_km[1];
            strcpy(maior[2], maior[1]);
            maior_km[1] = p->info.quilometragem;
            strcpy(maior[1], p->info.placa);
        }
        else if(p->info.quilometragem > maior_km[2]){
            maior_km[2] = p->info.quilometragem;
            strcpy(maior[2], p->info.placa);
        }
    }
    for(int i = 0; i < 3; i++){
        printf("\n%d. %s", i+1, maior[i]);
    }
}


void relatorio5(l_veiculos* lv, l_clientes* lc, l_locacoes* ll){

    printf("\n> Relatorio 5\n");
    printf("\nPlaca e modelo dos veiculos disponiveis: ");
    for(l_veiculos* p = lv; p != NULL; p = p->prox){
        if(p->info.disponivel == 1){
            printf("\nPlaca: %s\n", p->info.placa);
            printf("Marca/Modelo: %s %s\n", p->info.marca, p->info.modelo);
        }
    }
}


