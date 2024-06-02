#include <stdio.h>
#include <stdlib.h>
#include "datas.h"

int converter_para_dias(int data) {
    
    int dia, mes, ano;
    dia = data / 1000000;
    mes = (data / 10000) % 100;
    ano = data % 10000;

    int total_dias = ano * 365 + dia;

    int dias_por_mes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (int i = 1; i < mes; i++) {
        total_dias += dias_por_mes[i];
    }

    total_dias += ano / 4 - ano / 100 + ano / 400;

    if (mes > 2 && bissexto(ano)) {
        total_dias++;
    }

    return total_dias;
}



int diferenca_de_dias(int data1, int data2) {
    int dias1 = converter_para_dias(data1);
    int dias2 = converter_para_dias(data2);

    return dias2 - dias1;
}

int bissexto(int ano) {
    return ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0));
}

int data_valida(int data) {

    int dia, mes, ano;
    
    dia = data / 1000000;
    mes = (data / 10000) % 100;
    ano = data % 10000;


    int dias_por_mes[] = {0, 31, 28 + bissexto(ano), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (mes < 1 || mes > 12)
        return 0; 

    if (dia < 1 || dia > dias_por_mes[mes])
        return 0; 

    return 1; 

}

int compara_datas(int data_retirada, int data_devolucao) {

    int dia_retirada, mes_retirada, ano_retirada;
    int dia_devolucao, mes_devolucao, ano_devolucao;

    dia_retirada = data_retirada / 1000000;
    mes_retirada = (data_retirada / 10000) % 100;
    ano_retirada = data_retirada % 10000;

    dia_devolucao = data_devolucao / 1000000;
    mes_devolucao = (data_devolucao / 10000) % 100;
    ano_devolucao = data_devolucao % 10000;

    if (ano_devolucao > ano_retirada) {
        return 1;
    } else if (ano_devolucao == ano_retirada) {
        if (mes_devolucao > mes_retirada) {
            return 1;
        } else if (mes_devolucao == mes_retirada) {
            if (dia_devolucao >= dia_retirada) {
                return 1;
            }
        }
    }

    return 0;
}

int dias_no_mes(int mes, int ano) {
    int dias_por_mes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (mes == 2 && bissexto(ano)) {
        return 29;
    }
    return dias_por_mes[mes];
}
