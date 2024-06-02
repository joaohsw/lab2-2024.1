#ifndef LOCACOES_H
#define LOCACOES_H

#include "lista.h"

void locar_veiculo(l_veiculos* lv, l_clientes* lc, l_locacoes** ll);
void devolver_veiculo(l_veiculos* lv, l_clientes* lc, l_locacoes* ll);
void listar_locacoes(l_locacoes* ll);

#endif 
