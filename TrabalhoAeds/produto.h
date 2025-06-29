#ifndef PRODUTO_H_INCLUDED
#define PRODUTO_H_INCLUDED

typedef struct {
    int Codigo;
    double Preco;
    char Nome[51];
    int Estoque;
} Produto;

Produto DigitarProduto();
void Imprimir(Produto p);
void MenuProduto();
void AbrirArquivoProduto();
void FecharArquivoProduto();
void InserirArquivoProduto(Produto p);
void CarregarProdutosArquivo();

#endif
