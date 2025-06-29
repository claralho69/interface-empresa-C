#include <stdio.h>
#include <stdlib.h>

#include "produto.h"
#include "cliente.h"
#include "interface.h"
#include "venda.h" //

void TelaPrincipal() {
    Borda(1, 1, 80, 24, 1, 0);
    gotoxy(33, 2);
    printf("EMPRESA S.A");
    gotoxy(2, 3);
    for (int i = 0; i < 77; i++) {
        printf("\xC4");
    }
    gotoxy(33, 14);
    printf("Sistema Versao 1.0");
}

int main() {
    char Opcoes[][20] = {"Produto", "Cliente", "Venda", "Fechar"};
    int X[] = {5, 18, 31, 44};
    int Y[] = {5, 5, 5, 5};
    int L[] = {10, 10, 10, 10};
    int Opcao;

    do {
        system("cls");
        TelaPrincipal();

        Opcao = Menu(Opcoes, 4, X, Y, 0, L);

        if (Opcao == 0) {
            MenuProduto();
        } else if (Opcao == 1) {
            MenuCliente();
        } else if (Opcao == 2) {
            MenuVenda();
        }

    } while (Opcao != 3);

    return 0;
}
