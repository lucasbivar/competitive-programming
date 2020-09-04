//TLE - pass in 2/4 tests
#include <iostream>

using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(0);
    int N, K;
    int sequencia[500005];
    int qtd = 0;
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        cin >> sequencia[i];
    }
    for(int i = 0; i < N; i++){
        long long soma = 0;
        for(int j = i; j < N; j++){
            soma += sequencia[j];
            if(soma == K) qtd++;
            if(soma > K) break;
        }
    }
    cout << qtd << endl;

    return 0;
}