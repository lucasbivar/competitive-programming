#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>

using namespace std;

vector<int> grafo[10005];
int presente[10005];
int geracoes = 0;
double geracoes_p[10005];

void BFS(int f){
    queue<int> fila;
    fila.push(f);
    while(true){
        if(geracoes != 0){
        cout << " ";
        }
        int aux, qtd_total = 0, qtd_presente = 0;
        vector<int> prox_geracao;
        while (fila.empty() == false){
            aux = fila.front();
            fila.pop();
            for(int i = 0; i < (int)grafo[aux].size(); i++){
                prox_geracao.push_back(grafo[aux][i]);
                qtd_total++;
                if(presente[grafo[aux][i]] == 1) qtd_presente++;
            }
        }
        
        double a = (100 * (float)qtd_presente)/(float)qtd_total;
        cout.precision(2);
        cout.setf(ios::fixed);
        if(prox_geracao.empty() == true){
            break;
        }
        cout << a;
        for(int i = 0; i < (int)prox_geracao.size(); i++){
            fila.push(prox_geracao[i]);
        }
        prox_geracao.clear();
        geracoes += 1;
    }
    cout << endl;
}


int main(){
    cin.tie(NULL);
    cout.tie(NULL);

    int M, N, A;
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        presente[i] = 0;
    }
    for(int i = 1; i <= N; i++){
        cin >> A;
        grafo[A].push_back(i);
    }
    for(int i = 0; i < M; i++){
        cin >> A;
        presente[A] = 1;
    }

    BFS(0);
    return 0;
}