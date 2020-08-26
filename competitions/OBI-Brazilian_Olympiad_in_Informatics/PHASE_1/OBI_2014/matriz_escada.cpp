#include <iostream>

using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(0);
    int N, M;
    bool flag_eh_escada = true;
    int pos_primeiro;
    int matriz[505][505];
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> matriz[i][j];
        }
    }
    for(int i = 0; i < N; i++){
        bool linha_zero = true;
        for(int j = 0; j < M; j++){
            if(matriz[i][j] != 0){
                linha_zero = false;
                pos_primeiro = j;
                break;
            }
        }
        if(linha_zero == true){
            for(int k = i+1; k < N; k++){
                for(int j = 0; j < M; j++){
                    if(matriz[k][j] != 0){
                        flag_eh_escada = false;
                        break;
                    }
                }
                if(flag_eh_escada == false){
                    break;
                }
            }
        }else{
            for(int k = i+1; k < N; k++){
                for(int j = 0; j < M; j++){
                    if(j <= pos_primeiro){
                        if(matriz[k][j] != 0){
                            flag_eh_escada = false;
                            break;
                        }
                    }
                }
                if(flag_eh_escada == false){
                    break;
                }
            }
        }
        if(flag_eh_escada == false){
            break;
        }
    }
    char resposta = (flag_eh_escada == true) ? 'S' : 'N';
    cout << resposta << endl;
    return 0;
}