#include <iostream>

using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(0);
    int cartas[6];
    int anterior;
    bool crescente = true;
    bool decrescente = true;
    

    for(int i = 0; i < 5; i++){
        cin >> cartas[i];
    }
    anterior = cartas[0];    
    for(int i = 1; i < 5; i++){
        if(cartas[i] < anterior){
            crescente = false;
        }
        if(cartas[i] > anterior){
            decrescente = false;
        }
        anterior = cartas[i];
    }
    if(crescente == true){
        cout << "C" << endl;
    }else if(decrescente== true){
        cout << "D" << endl;
    }else{
        cout << "N" << endl;
    }
    return 0;
}