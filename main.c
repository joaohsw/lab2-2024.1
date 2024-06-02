#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "lista.h"
#include "locacoes.h"

int main() {

    l_veiculos* lv;
    l_clientes* lc;
    l_locacoes* ll;

    lv = l_cria_veiculos();
    lc = l_cria_clientes();
    ll = l_cria_locacoes();

    menu_principal(&lv, &lc, &ll); 

    return 0;

}
