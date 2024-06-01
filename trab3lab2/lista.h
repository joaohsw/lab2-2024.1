#ifndef LISTA_H
#define LISTA_H

typedef struct info_veiculo {
    char placa[50];
    char marca[50];
    char modelo[50];
    int ano;
    long int quilometragem;
    float diaria;
    int disponivel;
} dados_veiculo;

typedef struct veiculos {
    dados_veiculo info;
    struct veiculos *prox; 
} l_veiculos;

typedef struct info_cliente {
    long int cnh;
    char nome[50];
    long int telefone;
} dados_cliente;

typedef struct clientes {
    dados_cliente info;
    struct clientes *prox;
} l_clientes;

l_veiculos* l_cria_veiculos();
l_clientes* l_cria_clientes();
l_veiculos* l_insere_veiculo(l_veiculos* l, dados_veiculo i);
l_clientes* l_insere_cliente(l_clientes* l, dados_cliente i);
void l_imprime_veiculos(l_veiculos* l);  
void l_imprime_clientes(l_clientes* l);


#endif
