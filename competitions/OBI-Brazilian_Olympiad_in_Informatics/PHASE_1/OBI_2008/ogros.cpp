#include <iostream>
#include <queue>
#include <vector>
/*link do prob: https://olimpiada.ic.unicamp.br/pratique/p2/2008/f1/ogros/*/
using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(0);
    int N, M, A;
    queue<int> fila_de_ogros;
    vector<int> faixa;
    vector<int> pontuacao;
    cin >> N >> M;
    for(int i = 0; i < (N-1); i++){
        cin>> A;
        faixa.push_back(A);
    }
    for(int i = 0; i < N; i++){
        cin >> A;
        pontuacao.push_back(A);
    }
    for(int i = 0; i < M; i++){
        cin >> A;
        fila_de_ogros.push(A);

    }
    int qtd = 0;
    int aux;
    while (fila_de_ogros.empty() == false){
        aux = fila_de_ogros.front();
        fila_de_ogros.pop();
        if(aux < faixa[0]){
            if(qtd == 0){
                cout << pontuacao[0]; 
                qtd++;
            }else{
                cout << " " << pontuacao[0];
            }
            continue;
        }
        if(aux >= faixa[N - 2]){
            if(qtd == 0){
                cout << pontuacao[N - 1]; 
                qtd++;
            }else{
                cout << " " << pontuacao[N - 1];
            }
            continue;
        }
        for(int i = 0; i < (N - 2); i++){
            if(aux >= faixa[i] && aux < faixa[i+1]){
                if(qtd == 0){
                    cout << pontuacao[i + 1]; 
                    qtd++;
                }else{
                    cout << " " << pontuacao[i+1];
                }
                break;
            }
        }

    }
    cout << endl;   

    return 0;
}