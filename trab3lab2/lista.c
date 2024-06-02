#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

l_veiculos* l_cria_veiculos() {
    return NULL;
}

l_clientes* l_cria_clientes() {
    return NULL;
}

l_locacoes* l_cria_locacoes() {
    return NULL;
}

l_veiculos* l_insere_veiculo(l_veiculos* l, dados_veiculo i) {
    l_veiculos* novo = (l_veiculos*) malloc(sizeof(l_veiculos));
    if (novo == NULL) {
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }
    novo->info = i;
    novo->prox = l;
    return novo;
}

l_clientes* l_insere_cliente(l_clientes* l, dados_cliente i) {
    l_clientes* novo = (l_clientes*) malloc(sizeof(l_clientes));
    if (novo == NULL) {
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }
    novo->info = i;
    novo->prox = l;
    return novo;
}

l_locacoes* l_insere_locacao(l_locacoes* l, dados_locacao i) {
    l_locacoes* novo = (l_locacoes*) malloc(sizeof(l_locacoes));
    if (novo == NULL) {
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }
    novo->info = i;
    novo->prox = l;
    return novo;
}

void l_imprime_veiculos(l_veiculos* l){


    l_veiculos* p; 
    for (p = l; p != NULL; p = p->prox) {
        printf("\n> Veiculo\n");
        printf("Placa: %s\n", p->info.placa);  
        printf("Marca: %s\n", p->info.marca);
        printf("Modelo: %s\n", p->info.modelo);
        printf("Ano: %d\n", p->info.ano);
        printf("Quilometragem: %d\n", p->info.quilometragem);
        printf("Diaria: %.2f\n", p->info.diaria);
        if(p->info.disponivel == 1){
            printf("Disponivel: sim\n\n");
        }
        else {
            printf("Disponivel: nao\n\n");
        }
    }
}

void l_imprime_clientes(l_clientes* l){

    l_clientes* p;
    for(p = l; p != NULL; p = p->prox) {
        printf("\n> Cliente\n");
        printf("CNH: %d\n", p->info.cnh);
        printf("Nome: %s\n", p->info.nome);
        printf("Telefone: %d\n", p->info.telefone);
    }

}

void l_imprime_locacoes(l_locacoes* l) {
    l_locacoes* p;
    for(p = l; p != NULL; p = p->prox) {
        printf("\n> Locacao\n");
        printf("Nome: %s\n", p->info.nome);
        printf("CNH: %d\n", p->info.cnh);
        printf("Marca/Modelo: %s\n", p->info.marca_modelo);
        printf("Data de retirada: %d\n", p->info.retirada);
        printf("Data de devolucao: %d\n", p->info.devolucao);
        printf("Valor total: %.2f\n", p->info.valor_total);
    }
}

void l_libera_veiculos(l_veiculos* l) {
    l_veiculos* p = l;
    while (p != NULL) {
        l_veiculos* t = p->prox;
        free(p);
        p = t;
    }
}

void l_libera_clientes(l_clientes* l) {
    l_clientes* p = l;
    while (p != NULL) {
        l_clientes* t = p->prox;
        free(p);
        p = t;
    }
}

void l_libera_locacoes(l_locacoes* l) {
    l_locacoes* p = l;
    while (p != NULL) {
        l_locacoes* t = p->prox;
        free(p);
        p = t;
    }
}

