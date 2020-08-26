#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(0);
    int qtd_atual = 0;
    int maior_qtd = 0;
    int N;
    char matriz[105][105];
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> matriz[i][j];
        }
    }
    for(int i = 0; i < N; i++){
        if(i % 2 == 0){
            for(int j = 0; j < N; j++){
                if(matriz[i][j] == 'o'){
                    qtd_atual++;
                }else if(matriz[i][j] == 'A'){
                    maior_qtd = max(maior_qtd, qtd_atual);
                    
                    qtd_atual = 0;
                }
            } 
        }else{
            for(int j = (N-1); j >= 0; j--){
                if(matriz[i][j] == 'o'){
                    qtd_atual++;
                }else if(matriz[i][j] == 'A'){
                    maior_qtd = max(maior_qtd, qtd_atual);
                    qtd_atual = 0;
                }
            }
        }
    }
    maior_qtd = max(maior_qtd, qtd_atual);
    cout << maior_qtd << endl;
    return 0;
}