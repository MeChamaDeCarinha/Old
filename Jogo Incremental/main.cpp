#include <iostream>
#include <string>
#include <thread>

using namespace std;

double money = 10;
int level = 1;
const string tropas[] = {"Guerreiros", "Cavalos", "Coliseus", "Bases"};
double quant[] = {0, 0, 0, 0};
int prec[] = {5, 10, 100, 500};
int seed[] = {0, 5, 10, 100, 0};

// !------------------------------------
// Todo dias/energia.
// ? rebirth.
// !------------------------------------

// !Funções visuais.
// *Mostra as informações(money & Tropas).

void msg(int xLevel) {
    cout << "+-------------------+\n"
         << "Dinheiro: " << money << "\n"
         << "Level: " << level << endl;
    for (int i = 0; i < xLevel; i++) {
        cout << tropas[i] << ": " << quant[i] << endl;
    }
};

// *Mostra as possíveis ações.

void actV() {
    cout << "+-------------------+\n"
         << "Escolha uma ação:\n"
         << "+-------------------+\n"
         << "1 - Batalhar.\n"
         << "2 - Treinar.\n"
         << "3 - Comprar.\n"
         << "4 - Help.\n"
         << "5 - Sair.\n"
         << "+-------------------+" << endl;
};

// *Mostra os tipos de tropas para compra.

void typeV(int level) {
    cout << "+-------------------+\n"
         << "Escolha uma tropa:\n"
         << "+-------------------+\n"
         << "1 - Voltar.\n";
        for (int i = 0; i < level; i++) {
            cout << i + 2 << " - " << tropas[i] << "." << endl;
        }
        cout << "+-------------------+" << endl;
};

// !Funções de mecânica de jogo.
// *Função para batalhar(Ganhar dinheiro).

void battle() {
    system("cls");
    cout << "Batalhando.";
    this_thread::sleep_for(chrono::milliseconds(166));
    cout << ".";
    this_thread::sleep_for(chrono::milliseconds(166));
    cout << ".";
    this_thread::sleep_for(chrono::milliseconds(166));
    for (int i = 0; i < quant[0]; i++) {
        money = money + 1;
    }
};

// *Função para treinar tropas(multiplicar).

void treinar(int level) {
    system("cls");
    cout << "Treinando.";
    this_thread::sleep_for(chrono::milliseconds(500));
    cout << ".";
    this_thread::sleep_for(chrono::milliseconds(500));
    cout << ".";
    this_thread::sleep_for(chrono::milliseconds(500));
    for (int i = 0; i < level; i++) {
        quant[i] = quant[i] + (seed[i + 1] * quant[i + 1]);
    }
}

// *Função para comprar tropas.

void comprar (int nTropa) {
    system("cls");
    cout << "+-------------------+\n"
         << "Dinheiro: " << money << ".\n"
         << "Total: " << quant[nTropa - 1] << ".\n"
         << "Preço por unidade: " << prec[nTropa - 1] << ".\n"
         << "Quantos " << tropas[nTropa - 1] << " quer comprar?\n"
         << "+-------------------+" << endl;
    int cN = 0;
    cin >> cN;

    if ((prec[nTropa - 1] * cN) <= money && (prec[nTropa - 2] * cN) <= quant[nTropa - 2]) {
        
        if (nTropa <= 1) {
            for (int i = 0; i < cN; i++) {
                quant[nTropa - 1]++;
                money = money - prec[nTropa - 1];
            }
        }
        else {
            for (int i = 0; i < cN; i++) {
                quant[nTropa - 1]++;
                money = money - prec[nTropa - 1];
                quant[nTropa - 2] = quant[nTropa - 2] - prec[nTropa - 1]; 
            }
        }
    }
    else {
        cout << "Recursos insuficiente." << endl;
    }
};

// !-----------------!
// !Inicio do Código.!
// !-----------------!

int main() {
    system("chcp 65001 > null");
    int act, type;
    do {
        system ("cls");
        msg(level);
        actV();
        cin >> act;
        
        switch(act) {
            case 1:
                battle();
            break;

            case 2:
                treinar(level);
            break;
            
            case 3:
                system ("cls");
                typeV(level);
                cin >> type;
                switch(type) {
                    case 1:
                    break;

                    case 2:
                        comprar(1);
                    break;

                    case 3:
                        if (level >= 2) {
                            comprar(2);
                        }
                    break;

                    case 4:
                        if (level >= 3) {
                            comprar(3);
                        }
                    break;

                    case 5:
                        if (level >= 4) {
                            comprar(4);
                        }
                    break;
                }
            break;
        }

        if (quant[3] >= 5000) {
            level = 5;
        }
        else if (quant[2] >= 1000) {
            level = 4;
        }
        else if (quant[1] >= 500) {
            level = 3;
        }
        else if (quant[0] >= 25) {
            level = 2;
        }
    } while (act != 5);
}