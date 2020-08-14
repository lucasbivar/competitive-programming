#include <iostream>

using namespace std;

int matriz[105][105];
int pedacos_por_navio[10005] = {};
int DirecaoX[4] = {0, 1, 0, -1};
int DirecaoY[4] = {-1, 0, 1, 0};
int N, M, K, L, C;
int qtd_navios = 0;

void define_navios(int x, int y){
    matriz[x][y] = qtd_navios;
    pedacos_por_navio[qtd_navios] += 1;
    for(int i = 0; i < 4; i++){
        int new_x = x + DirecaoX[i];
        int new_y = y + DirecaoY[i];
        if(new_x < 0 || new_y < 0 || new_x > (N-1) || new_y > (M-1)) continue;
        if(matriz[new_x][new_y] == -2){
            define_navios(new_x, new_y);
        }
    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(0);

    char A;
    int resp = 0;
    
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> A;
            if(A == '.'){
                matriz[i][j] = -1;
            }else{
                matriz[i][j] = -2;
            }
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(matriz[i][j] == -2){
                define_navios(i, j);
                qtd_navios++;
            }
        }
    }
    cin >> K;
    for(int i = 0; i < K; i++){
        cin >> L >> C;
        L--; C--;
        if(matriz[L][C] != -1){
            pedacos_por_navio[matriz[L][C]]--;
            if(pedacos_por_navio[matriz[L][C]] == 0){
                resp++;
            }
        }
    }
    cout << resp << endl;
    return 0;
}


