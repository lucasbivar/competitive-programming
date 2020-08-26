#include <iostream>

using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(0);
    int qtd = 0;
    int pinos[1005];
    int N, M;
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> pinos[i];
    }
    for(int i = 0; i < N - 1; i++){
        if(pinos[i] == M) continue;
        int diferenca;
        if(pinos[i] > M){
            diferenca = pinos[i] - M;
            pinos[i+1] -= diferenca;
            
        }else{
            diferenca = M - pinos[i];
            pinos[i+1] += diferenca;
        }
        qtd += diferenca;
        pinos[i] = M;
    }
    cout << qtd << endl;
    return 0;
}