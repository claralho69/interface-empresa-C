#include <stdio.h>
#include <stdlib.h>
#include "venda.h"
#include "produto.h"
#include "cliente.h"

Venda vendas[100];
int qtdVendas = 0;

void CadastrarVenda() {
    Venda v;

    printf("Codigo do produto: ");
    scanf("%d", &v.codigoProduto);

    printf("Codigo do cliente: ");
    scanf("%d", &v.codigoCliente);

    printf("Quantidade: ");
    scanf("%d", &v.quantidade);

    FILE *arquivo = fopen("vendas.dat", "ab");
    if (arquivo != NULL) {
        fwrite(&v, sizeof(Venda), 1, arquivo);
        fclose(arquivo);
        vendas[qtdVendas++] = v;
        printf("Venda registrada com sucesso!\n");
    } else {
        printf("Erro ao salvar a venda.\n");
    }
}

void ListarVendas() {
    FILE *arquivo = fopen("vendas.dat", "rb");
    Venda v;
    if (arquivo == NULL) {
        printf("Nenhuma venda registrada ainda.\n");
        return;
    }

    printf("LISTA DE VENDAS:\n");

    while (fread(&v, sizeof(Venda), 1, arquivo) == 1) {
        printf("Produto: %d | Cliente: %d | Quantidade: %d\n",
               v.codigoProduto, v.codigoCliente, v.quantidade);
    }

    fclose(arquivo);
}

void MenuVenda() {
    int opcao;
    do {
        system("cls");
        printf("===== MENU DE VENDAS =====\n");
        printf("1 - Nova venda\n");
        printf("2 - Listar vendas\n");
        printf("0 - Voltar\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch(opcao) {
        case 1:
            CadastrarVenda();
            system("pause");
            break;
        case 2:
            ListarVendas();
            system("pause");
            break;
        }
    } while(opcao != 0);
}
