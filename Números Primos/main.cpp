#include <iostream>

using namespace std;

int main(){
    system("chcp 65001 > null");
    int x = 0;
    cout << "Números primos até: ";
    cin >> x;
    
    for(int i = 1; i <= x; i++){
        int divs = 0;
        for(int j = 1; j <= i; j++){
            if(i % j == 0){
                divs++;
            }
            if(divs > 2){
                j = x + 1;
            }
        }
        if(divs == 2){
            cout << i << endl;
        }
    }
    system("PAUSE");
}
