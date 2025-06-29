#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct cliente {
    int Codigo;
    char Nome[51];
    char Endereco[100];
    int Telefone;
    double Limite;
} Cliente;

Cliente DigitarCliente();
void ImprimirCliente(Cliente c);
void MenuCliente();

#endif
