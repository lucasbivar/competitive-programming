#include <iostream>

using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(0);
    int tabuleiro[8][8];
    int movimentoX[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int movimentoY[8] = {1, 2, 2, 1, -1, -2, -2, -1};
    int x = 4;
    int y = 4;
    int qtd = 0;
    int N, M;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            tabuleiro[i][j] = 0;
        }
    }
    tabuleiro[2][2] = 1;
    tabuleiro[3][5] = 1;
    tabuleiro[4][1] = 1;
    tabuleiro[4][2] = 1;
    bool conta = true;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> M;
        M--;
        x = x + movimentoX[M];
        y = y + movimentoY[M];
        if(tabuleiro[x][y] == 1){
            if(conta == true) qtd++;
            conta = false;
            continue;
        }
        if(conta == true && tabuleiro[x][y] == 0){
            qtd++;
        }
    }
    cout << qtd << endl;
    
    return 0;
}