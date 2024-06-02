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

typedef struct Locacoes {
    char nome[50];
    int cnh;
    char marca_modelo[100];
    char placa[50];
    int retirada;
    int devolucao;
    float valor_total;
    float diaria;
    long int quilometragem;   
} dados_locacao;

typedef struct l_locacoes {
    dados_locacao info;
    struct l_locacoes* prox;
} l_locacoes;

l_veiculos* l_cria_veiculos();
l_clientes* l_cria_clientes();
l_locacoes* l_cria_locacoes();
l_veiculos* l_insere_veiculo(l_veiculos* l, dados_veiculo i);
l_clientes* l_insere_cliente(l_clientes* l, dados_cliente i);
l_locacoes* l_insere_locacao(l_locacoes* l, dados_locacao i);
void l_imprime_veiculos(l_veiculos* l);  
void l_imprime_clientes(l_clientes* l);
void l_imprime_locacoes(l_locacoes* l);
void l_libera_veiculos(l_veiculos* l);
void l_libera_clientes(l_clientes* l);
void l_libera_locacoes(l_locacoes* l);

#endif
