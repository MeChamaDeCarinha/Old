#include <iostream>

using namespace std;

int main() {
    system("chcp 65001 > null");

    float x, y;    
    char op;
    cout.precision(20);

    do {
        cout << "Digite a expressão: ";
        cin >> x;
        cin >> op;
        cin >> y;

        switch(op) {
            case '+':
                cout << x << "+" << y << "=" << x + y << endl;
                break;
            case '-':
                cout << x << "-" << y << "=" << x - y << endl;
                break;
            case '*':
                cout << x << "*" << y << "=" << x * y << endl;
                break;
            case '/':
                cout << x << "/" << y << "=" << x / y << endl;
                break;
            default:
                cout << "Error" << endl;
        }
    } while (x != 0 && y != 0);
}