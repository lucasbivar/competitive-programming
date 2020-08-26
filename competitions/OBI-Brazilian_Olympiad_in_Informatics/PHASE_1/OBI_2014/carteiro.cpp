#include <iostream>
#include <queue>

using namespace std;

int casas[45005];

int binarySearch(int tamanho, int procura){
    int fim = tamanho;
    int inicio = 0;
    while (inicio <= fim){
        int mid = (inicio + fim)/2;
        if(casas[mid] == procura) return mid;
        if(casas[mid] < procura) inicio = mid+1;
        if(casas[mid] > procura) fim = mid-1;
    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(0);
    int N, M, casa;
    int tempo = 0;
    int posicao_ultima_casa = 0;
    queue<int> encomendas;
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> casas[i];
    }
    for(int i = 0; i < M; i++){
        cin >> casa;
        encomendas.push(casa);
    }
    int ultima_casa = casas[0];
    while(encomendas.empty() == false){
        int destino = encomendas.front();
        encomendas.pop();
        if(destino == ultima_casa){
            continue;
        }
        int posicao_atual = binarySearch(N, destino);
        if(posicao_atual > posicao_ultima_casa){
            tempo += (posicao_atual - posicao_ultima_casa);
        }else{
            tempo += (posicao_ultima_casa - posicao_atual);
        }

        posicao_ultima_casa = posicao_atual;
        ultima_casa = casas[posicao_atual];
    }

    cout << tempo << endl;
    return 0;
}