#ifndef LOCACOES_H
#define LOCACOES_H

#include "lista.h"

struct Locacoes {
    char nome[50];
    int cnh;
    char marca[50];
    char modelo[50];
    int retirada;
    int devolucao;
    float valor_total;
}; typedef Locacoes locacoes;


l_clientes* selecionar_cliente(l_clientes** lc);
void locar_veiculo(l_veiculos* lv, l_clientes* lc);
void devolver_veiculo();
void listar_locacoes();

#endif 
