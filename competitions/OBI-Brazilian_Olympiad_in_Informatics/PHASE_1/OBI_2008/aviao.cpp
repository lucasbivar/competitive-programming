#include <iostream>
#include <cmath>

using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(0);
    int F, C, E, B, posicao;
    string alfabeto = "zABCDEFGHIJKLMNOPQRSTUVWXYZ";
    cin >> F >> C >> E >> B;
    if(B % C==0){
        posicao = C;
    }else{
        posicao = B % C;
    }
    int fila =  ceil((float)B / (float)C) + (E - 1) ;
     if(fila > F){
         cout << "PROXIMO VOO" << endl;
    }else{
         cout << fila << " " << alfabeto[posicao] << endl;
    }
   

    return 0;
}