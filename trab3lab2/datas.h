#ifndef DATAS_H
#define DATAS_H

struct Date {
    int day;
    int month;
    int year;
};

int converter_para_dias(int data);
int diferenca_de_dias(int data1, int data2);
int bissexto(int ano);
int data_valida(int data);
int compara_datas(int data_retirada, int data_devolucao);
int dias_no_mes(int mes, int ano);


#endif 
