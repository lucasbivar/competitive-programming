#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(0);

    int N, M, U, V, W;
    long long grafo[255][255];
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            grafo[i][j] = INT_MAX;
        }
    }
    for(int i = 0; i < M; i++ ){
        cin >> U >> V >> W;
        grafo[U][V] = W;
        grafo[V][U] = W;
    }
    //ALGORITMO DE FLOYD-WARSHALL
    for(int k = 1; k <= N; k++){
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                grafo[i][j] =  min(grafo[i][j], grafo[i][k] + grafo[k][j]);
            }
        }
    }
    long long menor = LLONG_MAX, maior_linha = -1;
    for(int i = 1; i <= N; i++){
        maior_linha = -1;
        for(int j = 1; j <= N; j++){
            if(i == j) continue;
            maior_linha = max(maior_linha, grafo[i][j]);
        }
        menor = min(maior_linha, menor);
    }
    cout << menor << endl;

    return 0;
}