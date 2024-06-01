#include <stdio.h>
#include <stdlib.h>
#include "datas.h"

int daysBetweenDates(struct Date date1, struct Date date2) {
    int days1 = date1.year * 365 + date1.day;
    int days2 = date2.year * 365 + date2.day;

    days1 += date1.year / 4 - date1.year / 100 + date1.year / 400;
    days2 += date2.year / 4 - date2.year / 100 + date2.year / 400;

    int monthDays[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (int i = 1; i < date1.month; i++) {
        days1 += monthDays[i];
    }
    for (int i = 1; i < date2.month; i++) {
        days2 += monthDays[i];
    }

    if (date1.month <= 2 && (date1.year % 4 == 0 && (date1.year % 100 != 0 || date1.year % 400 == 0))) {
        days1--;
    }
    if (date2.month <= 2 && (date2.year % 4 == 0 && (date2.year % 100 != 0 || date2.year % 400 == 0))) {
        days2--;
    }

    int difference = days2 - days1;
    return difference;
}

void calcularDiferencaDeDatas() {
    struct Date date1, date2;

    printf("Digite a primeira data (DD MM AAAA): ");
    scanf("%d %d %d", &date1.day, &date1.month, &date1.year);

    printf("Digite a segunda data (DD MM AAAA): ");
    scanf("%d %d %d", &date2.day, &date2.month, &date2.year);

    int difference = daysBetweenDates(date1, date2);

    printf("A diferença em dias entre as duas datas é: %d\n", difference);
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
