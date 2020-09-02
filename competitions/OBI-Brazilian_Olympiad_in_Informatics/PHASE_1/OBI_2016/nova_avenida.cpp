#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;
int matriz[1005][1005];

int main(){

    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(0);
    int N, M;

    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> matriz[i][j];
        }
    }
    int menor_soma = INT_MAX;
    for(int i = 0; i < M; i++){
        int soma = 0;
        for(int j = 0; j < N; j++){
            soma += matriz[j][i];
        }
        menor_soma = min(soma, menor_soma);
    }
    cout << menor_soma << endl;
    return 0;
}