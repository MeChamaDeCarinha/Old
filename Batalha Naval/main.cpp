#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <thread>

using namespace std;

const int tam = 10;
int esc, acertosPM, acertosMM;
int acertosP = 0;
int acertosM = 0;
bool playing = true;

char grid1[tam][tam] = {{'+', '1', '2', '3', '4', '5', '6', '7', '8', '9'},
                        {'1', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'2', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'3', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'4', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'5', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'6', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'7', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'8', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'9', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}};

char grid2[tam][tam] = {{'+', '1', '2', '3', '4', '5', '6', '7', '8', '9'},
                        {'1', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'2', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'3', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'4', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'5', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'6', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'7', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'8', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'9', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}};

char grid3[tam][tam] = {{'+', '1', '2', '3', '4', '5', '6', '7', '8', '9'},
                        {'1', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'2', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'3', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'4', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'5', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'6', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'7', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'8', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'9', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}};

char grid4[tam][tam] = {{'+', '1', '2', '3', '4', '5', '6', '7', '8', '9'},
                        {'1', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'2', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'3', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'4', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'5', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'6', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'7', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'8', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'9', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}};

void show(int grid){
    if(grid == 1){
        for(int i = 0; i < tam; i++){
            for(int j = 0; j < tam; j++){
                cout << grid1[i][j];
            }
            cout << endl;
        }
    }
    if(grid == 2){
        for(int i = 0; i < tam; i++){
            for(int j = 0; j < tam; j++){
                cout << grid2[i][j];
            }
            cout << endl;
        }
    }
    if(grid == 3){
        for(int i = 0; i < tam; i++){
            for(int j = 0; j < tam; j++){
                cout << grid3[i][j];
            }
            cout << endl;
        }
    }
    if(grid == 4){
        for(int i = 0; i < tam; i++){
            for(int j = 0; j < tam; j++){
                cout << grid4[i][j];
            }
            cout << endl;
        }
    }
}

void update(int n){
    system("cls");
    show(n);
}

void escP(){
    for(int i = 0; i < 4; i++){
        int x, y, e, r = 0, barcos = 2, subs = 2;

        cout << "Escolha a linha: ";
        
        cin >> x;
        update(1);

        cout << "Escolha a coluna: ";
        
        cin >> y;
        update(1);


        cout << "1 - Barco(####)\n"
                "2 - Submarino(###)\n"
                "Escolha a embarcação: ";

        cin >> e;

        if((y >= 7 && e == 1 ) || (y >= 7 && e == 2) || x <= 0 || y <= 0){
            i--;
        }
        else{
            switch(e){
                case 1:
                    for(int i = 0; i < 4; i++){
                        if(grid1[x][i + y] == '#'){
                            r += 1;
                        }
                    }
                    if(r == 0){
                        for(int i = 0; i < 4; i++){
                            grid1[x][i + y] = '#';
                        }
                    }
                    else{
                        i--;
                    }
                    break;
                case 2:
                    for(int i = 0; i < 3; i++){
                        if(grid1[x][i + y] == '#'){
                            r += 1;
                        }
                    }
                    if(r == 0){
                        for(int i = 0; i < 3; i++){
                            grid1[x][i + y] = '#';
                        }
                    }
                    else{
                        i--;
                    }
                break;
            }
        }
        update(1);
    }
}

void escM(){
    for(int i = 0; i < 4; i++){
        srand (time(NULL));
        int x, y, e, r = 0;
        x = rand() % 9 + 1;
        y = rand() % 9 + 1;
        e = rand() % 2 + 1;

        if((y >= 7 && e == 1) || (y >= 7 && e == 2) || x <= 0 || y <= 0){
            i--;
        }
        else{
            switch(e){
                case 1:
                    for(int i = 0; i < 4; i++){
                        if(grid2[x][i + y] == '#'){
                            r += 1;
                        }
                    }
                    if(r == 0){
                        for(int i = 0; i < 4; i++){
                            grid2[x][i + y] = '#';
                        }
                    }
                    else{
                        i--;
                    }
                break;

                case 2:
                    for(int i = 0; i < 3; i++){
                        if(grid2[x][i + y] == '#'){
                            r += 1;
                        }
                    }
                    if(r == 0){
                        for(int i = 0; i < 3; i++){
                            grid2[x][i + y] = '#';
                        }
                    }
                    else{
                        i--;
                    }
                break;
            }
        }
        update(2);
    }
}

void check(){
    if(acertosM == acertosMM){
        playing == false;
        cout << "Máquina ganhou a partida.";
        system("PAUSE");
    }
    else if(acertosP == acertosPM){
        playing == false;
        cout << "Você ganhou a partida.";
        system("PAUSE");
    }
}

void tiroM(){
    for(int i = 0; i < 1; i++){
        int x, y;
        srand (time(NULL));
        x = rand() % 9 + 1;
        y = rand() % 9 + 1;

        if(grid1[x][y] == '#'){
            grid3[x][y] = 'X';
            i--;
            acertosM++;
        }
        else{
            grid3[x][y] = 'O';
        }
    }
    check();
    update(3);
    this_thread::sleep_for(chrono::milliseconds(1000));
}

void tiroP(){
    for(int i = 0; i < 1; i++){
        int x, y;
        update(4);

        cout << "Escolha uma linha: ";
        cin >> x;

        cout << "Escolha uma coluna: ";
        cin >> y;

        if(grid2[x][y] == '#'){
            grid4[x][y] = 'X';
            i--;
            acertosP++;
        }
        else{
            grid4[x][y] = 'O';
        }
    }
    check();
}

void scan(){
    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
            if(grid1[i][j] == '#'){
                acertosMM++;
            }
            
        }
    }
    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
            if(grid2[i][j] == '#'){
                acertosPM++;
            }
            
        }
    }
}


int main(){
    system("chcp 65001 > null");
    update(1);
    escP();
    escM();
    scan();
    update(1);
    while(playing == true){
        tiroP();
        tiroM();
    }
}