#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "fila.h"

int main(){


    fila* fila_normal = cria_fila();
    fila* fila_prioritaria = cria_fila();
    fila* fila_geral = cria_fila();

    menu_principal(&fila_normal, &fila_prioritaria, &fila_geral);



}