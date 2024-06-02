#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "lista.h"
#include "locacoes.h"
#include "relatorios.h"

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void opcao1(l_veiculos** lv) {

    dados_veiculo insercao;

    printf("\n> Inclusao de veiculo\n");

    printf("\nInforme a placa do veiculo a ser incluso no sistema: ");
    scanf("%s", insercao.placa);

    limpar_buffer();  

    printf("\nInforme a marca do veiculo a ser incluso no sistema: ");
    fgets(insercao.marca, sizeof(insercao.marca), stdin);
    insercao.marca[strcspn(insercao.marca, "\n")] = '\0';

    printf("\nInforme o modelo do veiculo a ser incluso no sistema: ");
    fgets(insercao.modelo, sizeof(insercao.modelo), stdin);
    insercao.modelo[strcspn(insercao.modelo, "\n")] = '\0';

    printf("\nInforme o ano do veiculo a ser incluso no sistema: ");
    scanf("%d", &insercao.ano);

    printf("\nInforme a quilometragem do veiculo a ser incluso no sistema: ");
    scanf("%ld", &insercao.quilometragem);

    printf("\nInforme o valor da diaria do veiculo a ser incluso no sistema: ");
    scanf("%f", &insercao.diaria);

    insercao.disponivel = 1;

    *lv = l_insere_veiculo(*lv, insercao);
    printf("\nVeiculo inserido com sucesso!\n");
}

void opcao3(l_clientes** lc){

    dados_cliente insercao;

    printf("\n> Inclusao de cliente\n");

    printf("\nInforme a CNH do cliente a ser cadastrado no sistema: ");
    scanf("%ld", &insercao.cnh);

    limpar_buffer();

    printf("\nInforme o nome do cliente a ser cadastrado no sistema: ");
    fgets(insercao.nome, sizeof(insercao.nome), stdin);
    insercao.nome[strcspn(insercao.nome, "\n")] = '\0';

    printf("\nInforme o telefone do cliente a ser cadastrado no sistema: ");
    scanf("%ld", &insercao.telefone);

    *lc = l_insere_cliente(*lc, insercao);
    printf("\nCliente cadastrado com sucesso!\n");

}

void menu_relatorios(l_veiculos* lv, l_clientes* lc, l_locacoes* ll) {

    int input;

    while (1) {
        printf("\n> Relatorios <");
        printf("\n  1. R1");
        printf("\n  2. R2");
        printf("\n  3. R3");
        printf("\n  4. R4");
        printf("\n  5. R5");
        printf("\n  0. voltar\n");

        scanf("%d", &input);

        switch (input) {
            case 1:
                relatorio1(lv, lc, ll);
                break;
            case 2:
                relatorio2(lv, lc, ll);
                break;
            case 3:
                relatorio3(lv, lc, ll);
                break;
            case 4:
                relatorio4(lv, lc, ll);
                break;
            case 5:
                relatorio5(lv, lc, ll);
                break;
            case 0:
                return;
            default:
                printf("\nOpcao invalida\n");
                break;
        }
    }
}

void menu_principal(l_veiculos** lv, l_clientes** lc, l_locacoes** ll) {

    int input;

    while (1) {
        printf("\n> Menu principal <");
        printf("\n  1. incluir veiculos");
        printf("\n  2. listar veiculos");
        printf("\n  3. incluir clientes");
        printf("\n  4. listar clientes");
        printf("\n  5. realizar locacao");
        printf("\n  6. devolver veiculo");
        printf("\n  7. listar locacoes");
        printf("\n  9. relatorios");
        printf("\n  0. sair\n");

        scanf("%d", &input);

        switch (input) {
            case 1:
                opcao1(lv);
                break;
            case 2:
                l_imprime_veiculos(*lv);
                break;
            case 3:
                opcao3(lc);
                break;
            case 4:
                l_imprime_clientes(*lc);
                break;
            case 5:
                locar_veiculo(*lv, *lc, ll);
                break;
            case 6:
                devolver_veiculo(*lv, *lc, *ll);
                break;
            case 7:
                listar_locacoes(*ll);
                break;
            case 9:
                menu_relatorios(*lv, *lc, *ll);
                break;
            case 0:
                exit(0);
            default:
                printf("\nOpcao invalida\n");
                break;
        }
    }
}
