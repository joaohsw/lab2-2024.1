#ifndef DATAS_H
#define DATAS_H

struct Date {
    int day;
    int month;
    int year;
};

int daysBetweenDates(struct Date date1, struct Date date2);

void calcularDiferencaDeDatas();

#endif // DATAS_H
