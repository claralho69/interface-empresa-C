#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produto.h"
#include "interface.h"

Produto Produtos[100];
int QtdProdutos = 0;

FILE *fpProduto = NULL;

void AbrirArquivoProduto()
{
    fpProduto = fopen("produtos.dat", "ab+");
    if (fpProduto == NULL)
    {
        printf("Erro ao abrir arquivo de produtos.\n");
        exit(1);
    }
}

void FecharArquivoProduto()
{
    if (fpProduto != NULL)
    {
        fclose(fpProduto);
        fpProduto = NULL;
    }
}

void InserirArquivoProduto(Produto P)
{
    fseek(fpProduto, 0, SEEK_END);
    fwrite(&P, sizeof(Produto), 1, fpProduto);
}

Produto DigitarProduto()
{
    Produto p;

    gotoxy(19, 7);
    scanf("%d", &p.Codigo);
    gotoxy(19, 10);
    scanf(" %[^\n]", p.Nome);
    gotoxy(19, 13);
    scanf("%lf", &p.Preco);
    gotoxy(19, 16);
    scanf("%d", &p.Estoque);

    return p;
}

void MostrarProduto(Produto p)
{
    gotoxy(19, 7);
    printf("%d", p.Codigo);
    gotoxy(19, 10);
    printf("%s", p.Nome);
    gotoxy(19, 13);
    printf("%.2lf", p.Preco);
    gotoxy(19, 16);
    printf("%d", p.Estoque);
}

void Imprimir(Produto p)
{
    printf("O Nome: %s\n", p.Nome);
    printf("O Codigo: %d\n", p.Codigo);
    printf("Quantidade em estoque: %d\n", p.Estoque);
    printf("Preco: R$%.2lf\n", p.Preco);
    printf("\n\n\n");
}

void TelaProdutos()
{
    Borda(5, 3, 70, 19, 0, 1);
    gotoxy(32, 4);
    printf("PRODUTOS");
    gotoxy(8, 7);
    printf("  Codigo:");
    gotoxy(8, 10);
    printf("Descricao:");
    gotoxy(8, 13);
    printf("Preco:");
    gotoxy(8, 16);
    printf("Estoque:");
    Borda(18, 6, 8, 2, 0, 0);
    Borda(18, 9, 51, 2, 0, 0);
    Borda(18, 12, 10, 2, 0, 0);
    Borda(18, 15, 7, 2, 0, 0);
}

void MenuProduto()
{
    char Opcoes[][20] = {"NOVO", "PESQUISAR", "LISTAR", "SAIR"};
    int x[] = {8, 20, 32, 44};
    int y[] = {19, 19, 19, 19};
    int l[] = {10, 10, 10, 10};

    int Opcao;
    int Pesquisa;

    CarregarProdutosArquivo(); // <-- CARREGAR DO ARQUIVO

    TelaProdutos();

    do
    {
        Opcao = Menu(Opcoes, 4, x, y, 0, l);

        if (Opcao == 0)
        {
            Produto P;
            P = DigitarProduto();

            AbrirArquivoProduto();
            InserirArquivoProduto(P);
            FecharArquivoProduto();

            Produtos[QtdProdutos] = P;
            QtdProdutos++;

            TelaProdutos();
        }

        if (Opcao == 1)
        {
            gotoxy(19, 7);
            scanf("%d", &Pesquisa);

            for (int i = 0; i < QtdProdutos; i++)
            {
                if (Pesquisa == Produtos[i].Codigo)
                {
                    TelaProdutos();
                    MostrarProduto(Produtos[i]);
                    break;
                }
            }
        }

        if (Opcao == 2)
        {
            system("cls");
            for (int i = 0; i < QtdProdutos; i++)
            {
                Imprimir(Produtos[i]);
            }
            system("pause");
            TelaProdutos();
        }

    }
    while (Opcao != 3);
}

void CarregarProdutosArquivo()
{
    Produto p;
    FILE *arquivo = fopen("produtos.dat", "rb");

    if (arquivo == NULL)
    {
        return; // Nenhum produto cadastrado ainda
    }

    while (fread(&p, sizeof(Produto), 1, arquivo) == 1)
    {
        Produtos[QtdProdutos] = p;
        QtdProdutos++;
    }

    fclose(arquivo);
}
