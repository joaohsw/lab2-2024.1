#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "locacoes.h"
#include "lista.h"
#include "datas.h"

l_clientes* selecionar_cliente(l_clientes** lc) {
    int cnh_busca;
    l_imprime_clientes(*lc);

    l_clientes* cliente_selecionado = NULL;
    int encontrado = 0;

    while (!encontrado) {
        
        printf("\n> Informe a CNH do cliente que deseja locar um veiculo: ");
        scanf("%d", &cnh_busca);

        l_clientes* temp = *lc;
        while (temp != NULL) {
            if (temp->info.cnh == cnh_busca) {
                cliente_selecionado = temp;
                encontrado = 1;
                break;
            }
            temp = temp->prox;
        }

        if (!encontrado) {
            printf("Cliente nao encontrado. Tente novamente.\n");
        }
    }

    return cliente_selecionado;
}

void locar_veiculo(l_veiculos* lv, l_clientes* lc) {

    printf("\n> Realizar locacao\n");

    l_clientes* cliente = selecionar_cliente(&lc);
    if (cliente != NULL) {
        printf("Cliente selecionado: %s\n", cliente->info.nome);
    } else {
        printf("Nenhum cliente foi selecionado.\n");
    }






}

void devolver_veiculo() {


    
}

void listar_locacoes() {



}
