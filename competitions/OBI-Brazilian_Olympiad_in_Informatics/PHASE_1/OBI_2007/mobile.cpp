#include <iostream>
#include <vector>
#include <queue>


using namespace std;
int N;
int soma;
vector<int> grafo[100005];
vector<pair<int, int>> geracao_atual;

void BFS(int f){
    queue<int> fila;
    fila.push(f);
    int aux;
    while (fila.empty()== false)
    {
        aux = fila.front();
        fila.pop();
        for(int i = 0; i < (int)grafo[aux].size(); i++){
            soma++;
            fila.push(grafo[aux][i]);
        }
    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios:: sync_with_stdio(0);

    int A, B;
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> A >> B;
        grafo[B].push_back(A);
    }
    vector<int> prox_geracao;
    prox_geracao.push_back(0);
    while (prox_geracao.empty() == false){

        for(int i = 0; i < (int)prox_geracao.size(); i++){
            geracao_atual.push_back(make_pair(prox_geracao[i], 0));
        }

        prox_geracao.clear();
        vector<pair<int, int>> verifica_peso;

        if(geracao_atual.empty() == false){
            
            for(int j = 0; j < (int)geracao_atual.size(); j++){
                
                for(int i = 0; i < (int) grafo[geracao_atual[j].first].size(); i++){
                    prox_geracao.push_back(grafo[geracao_atual[j].first][i]);
                    soma = 0;
                    BFS(grafo[geracao_atual[j].first][i]);
                    verifica_peso.push_back(make_pair(grafo[geracao_atual[j].first][i], soma));
                }
                if(verifica_peso.size() > 1){
                    int first_p = verifica_peso[0].second;
                    for(int i = 0; i < (int)verifica_peso.size(); i++){
                        if(verifica_peso[i].second != first_p){
                            cout << "mal" << endl;
                            return 0;
                        }
                    }
                }   
                verifica_peso.clear();
                
            }
        }

        geracao_atual.clear();
    }
    cout << "bem" << endl;

    return 0;
}