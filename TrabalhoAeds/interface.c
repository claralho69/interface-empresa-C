#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include "interface.h"

int getTecla() {
    int ch = getch();
    if (ch == 224) {
        ch = getch() + 1000;
    }
    return ch;
}

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x - 1;
    coord.Y = y - 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void textcolor(int iColor) {
    HANDLE hl = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
    GetConsoleScreenBufferInfo(hl, &bufferInfo);
    bufferInfo.wAttributes &= 0x00F0;
    SetConsoleTextAttribute(hl, bufferInfo.wAttributes |= iColor);
}

void textbackground(int iColor) {
    HANDLE hl = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
    GetConsoleScreenBufferInfo(hl, &bufferInfo);
    bufferInfo.wAttributes &= 0x000F;
    SetConsoleTextAttribute(hl, bufferInfo.wAttributes |= (iColor << 4));
}

void Borda(int x, int y, int largura, int altura, int tipo, int sombra) {
    char C[][6] = {"\xda\xbf\xc0\xd9\xc4\xb3", "\xc9\xbb\xc8\xbc\xcd\xba"};
    int i, j;

    gotoxy(x, y); printf("%c", C[tipo][0]);
    for (i = 0; i < largura; i++) printf("%c", C[tipo][4]);
    printf("%c", C[tipo][1]);

    for (j = 0; j < altura; j++) {
        gotoxy(x, y + j + 1); printf("%c", C[tipo][5]);
        for (i = 0; i < largura; i++) printf(" ");
        printf("%c", C[tipo][5]);
        if (sombra) printf("\xb2");
    }

    gotoxy(x, y + altura); printf("%c", C[tipo][2]);
    for (i = 0; i < largura; i++) printf("%c", C[tipo][4]);
    printf("%c", C[tipo][3]);

    if (sombra) {
        gotoxy(x + 1, y + altura + 1);
        for (i = 0; i < largura + 2; i++) printf("\xb2");
    }
}

int Menu(char Opcoes[][20], int Qtde, int x[], int y[], int Opcao, int Larg[]) {
    int tecla;

    for (int i = 0; i < Qtde; i++) {
        Borda(x[i], y[i], Larg[i], 2, 0, 0);
        gotoxy(x[i] + 1, y[i] + 1);
        printf("%s", Opcoes[i]);
    }

    do {
        Borda(x[Opcao], y[Opcao], Larg[Opcao], 2, 1, 0);
        gotoxy(x[Opcao] + 1, y[Opcao] + 1);
        printf("%s", Opcoes[Opcao]);

        tecla = getTecla();
        if (tecla == TEC_ESC)
            return -1;

        Borda(x[Opcao], y[Opcao], Larg[Opcao], 2, 0, 0);
        gotoxy(x[Opcao] + 1, y[Opcao] + 1);
        printf("%s", Opcoes[Opcao]);

        if (tecla == TEC_DIR) Opcao++;
        if (tecla == TEC_ESQ) Opcao--;
        if (tecla == TEC_ENTER) break;

        if (Opcao > Qtde - 1) Opcao = 0;
        if (Opcao < 0) Opcao = Qtde - 1;

    } while (1);

    return Opcao;
}
