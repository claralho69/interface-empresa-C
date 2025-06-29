#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"

Cliente Clientes[100];
int QtdClientes = 0;

Cliente DigitarCliente() {
    Cliente c;
    printf("Digite o nome do cliente: ");
    scanf(" %s", c.Nome);
    printf("Digite o codigo do cliente: ");
    scanf("%d", &c.Codigo);
    printf("Digite o endereco do cliente: ");
    scanf("%s", c.Endereco);
    printf("Digite o telefone do cliente: ");
    scanf("%d", &c.Telefone);
    printf("Digite o limite bancario do cliente: ");
    scanf("%lf", &c.Limite);
    return c;
}

void ImprimirCliente(Cliente c) {
    printf("O Nome: %s\n", c.Nome);
    printf("O Codigo: %d\n", c.Codigo);
    printf("Endereco do cliente: %s\n", c.Endereco);
    printf("Telefone: %d\n", c.Telefone);
    printf("Limite do banco: %.2lf\n", c.Limite);
    printf("\n\n\n");
}

void MenuCliente() {
    int Opcao;

    do {
        system("cls");
        printf("====================================\n");
        printf("         CADASTRO DE CLIENTES       \n");
        printf("====================================\n");
        printf("1 - Inserir novo cliente\n");
        printf("2 - Listar clientes\n");
        printf("0 - Sair\n");
        printf("====================================\n");
        printf("Digite uma opcao: ");
        scanf("%d", &Opcao);

        if (Opcao == 1) {
            Clientes[QtdClientes] = DigitarCliente();
            QtdClientes++;
        } else if (Opcao == 2) {
            system("cls");
            for (int i = 0; i < QtdClientes; i++) {
                ImprimirCliente(Clientes[i]);
            }
            system("pause");
        } else if (Opcao != 0) {
            printf("Opcao invalida\n");
            system("pause");
        }

    } while (Opcao != 0);
}
