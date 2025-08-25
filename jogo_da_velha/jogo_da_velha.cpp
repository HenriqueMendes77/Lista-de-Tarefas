#include <iostream>
#include <windows.h>
#include <conio.h>
#include <cstdlib>

using namespace std;

char tabuleiro[3][3] = {{'1', '2', '3'},
                        {'4', '5', '6'},
                        {'7', '8', '9'}};
int c = 1;
int l = 1;
char jogador = 'x';
char ganhador;
char jogada = ' ';
bool game = true;
char linha;
char coluna;
int contador;

void tab();
void direita();
void esquerda();
void baixo();
void cima();
void selecionar();
void verificar();
void limpar_tela();

int main()
{
    linha = 1;
    coluna = 1;

    while (game)
    {
        limpar_tela();
        tab();

        cout << "\nJogador " << jogador << ": ";
        jogada = _getch();

        switch (jogada)
        {
        case 'd':
            direita();
            break;
        case 'a':
            esquerda();
            break;
        case 'w':
            cima();
            break;
        case 's':
            baixo();
            break;
        case 'e':
            selecionar();
            break;
        case 'f':
            game = false;
            jogador = ' ';
            break;
        default:
            break;
        }
    }

    limpar_tela();

    if (!game && jogador != ' ')
    {
        tab();
        if (contador != 9)
        {
            cout << "\nJogador " << ganhador << " ganhou!\n";
        }
        else
        {
            cout << "\nEmpate!\n";
        }
    }
    else
    {
        cout << "Encerrando...";
    }
    Sleep(2000);
    limpar_tela();

    return 0;
}

void tab()
{
    cout << "\n";
    for (int i = 0; i < 3; i++)
    {
        for (int d = 0; d < 3; d++)
        {
            if (i == linha && d == coluna && game)
            {
                cout << " [" << tabuleiro[i][d] << "] ";
            }
            else
            {
                cout << "  " << tabuleiro[i][d] << "  ";
            }
        }
        cout << "\n\n";
    }
    cout << "\n";
}

void direita()
{
    c = (c < 2) ? c + 1 : 0;
    coluna = c;
}

void esquerda()
{
    c = (c > 0) ? c - 1 : 2;
    coluna = c;
}

void baixo()
{
    l = (l < 2) ? l + 1 : 0;
    linha = l;
}

void cima()
{
    l = (l > 0) ? l - 1 : 2;
    linha = l;
}

void selecionar()
{
    if (tabuleiro[l][c] != 'x' && tabuleiro[l][c] != 'o')
    {
        tabuleiro[l][c] = jogador;
        l = c = 1;
        verificar();
        if (game)
        {
            jogador = jogador == 'x' ? 'o' : 'x';
        }
        else
        {
            ganhador = jogador;
        }
    }
    else
    {
        cout << "\nEscolha outra opcao!\n";
        Sleep(1000);
    }
}

void verificar()
{
    // LINHA
    if (tabuleiro[0][0] == jogador && tabuleiro[0][1] == jogador && tabuleiro[0][2] == jogador)
    {
        game = false;
    }
    else if (tabuleiro[1][0] == jogador && tabuleiro[1][1] == jogador && tabuleiro[1][2] == jogador)
    {
        game = false;
    }
    else if (tabuleiro[2][0] == jogador && tabuleiro[2][1] == jogador && tabuleiro[2][2] == jogador)
    {
        game = false;
    }

    // COLUNA
    else if (tabuleiro[0][0] == jogador && tabuleiro[1][0] == jogador && tabuleiro[2][0] == jogador)
    {
        game = false;
    }
    else if (tabuleiro[0][1] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][1] == jogador)
    {
        game = false;
    }
    else if (tabuleiro[0][2] == jogador && tabuleiro[1][2] == jogador && tabuleiro[2][2] == jogador)
    {
        game = false;
    }

    // DIAGONAL
    else if (tabuleiro[0][0] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][2] == jogador)
    {
        game = false;
    }
    else if (tabuleiro[2][0] == jogador && tabuleiro[1][1] == jogador && tabuleiro[0][2] == jogador)
    {
        game = false;
    }

    // EMPATE
    contador = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int d = 0; d < 3; d++)
        {
            if (tabuleiro[i][d] == 'x' || tabuleiro[i][d] == 'o')
            {
                contador += 1;
            }
            if (contador == 9)
            {
                game = false;
            }
        }
    }

    linha = 1;
    coluna = 1;
}

void limpar_tela()
{
    system("cls");
}