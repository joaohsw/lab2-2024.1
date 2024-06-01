#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "lista.h"

int main() {

    l_veiculos* lv;
    l_clientes* lc;

    lv = l_cria_veiculos();
    lc = l_cria_clientes();

    menu_principal(&lv, &lc); 

    return 0;
}
