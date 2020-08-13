#include <iostream>

using namespace std;

int main(){ 
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(0);
    int N, C, S, E;
    bool excedido = false;
    cin >> N >> C;
    int qtd = 0;
    for(int i = 0; i < N; i++){
        cin >> S >> E;
        qtd = (qtd - S) + E;
        if(qtd > C){
            excedido = true;
        }
    }
    if(excedido == true){
        cout << "S" << endl;
    }else{
        cout << "N" << endl;
    }
    return 0;
}