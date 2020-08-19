#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<int> grafo[1000005];
long long distancia[1000005];
long long maior;

void DFS(int f){
    for(int i = 0; i < (int)grafo[f].size(); i++){
        if(distancia[grafo[f][i]] != -1) continue;
        distancia[grafo[f][i]] = distancia[f] + 1;
        DFS(grafo[f][i]); 
    }
    if(distancia[f] > maior){
        maior = distancia[f];
    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(0);
    int N, A, B;
    set<int> fila;
    cin >> N;
    for(int i = 0; i < (N-1); i++){
        cin >> A >> B;
        grafo[A].push_back(B);
        grafo[B].push_back(A);
        fila.insert(A);
        fila.insert(B);
    }
    long long ans = 0;
    while(fila.empty() == false){
        int aux = *fila.begin();
        fila.erase(fila.begin());
        for(int j = 1; j <= N; j++){
            distancia[j] = -1;
        }
        maior = 0;
        distancia[aux] = 0;
        DFS(aux);
        if(maior > ans){
            ans = maior;
        }
    }

    cout << ans << endl;
    return 0;
}