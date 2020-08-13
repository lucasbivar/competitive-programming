#include <iostream>

using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(0);

    int N, M, I, R, A, B;
    int infectado[1005];
    int reuniao[1005];
    int qtd = 1;

    cin >> N >> M;
    cin >> I >> R;
    for(int i = 1; i <= N; i++){
        infectado[i] = 0;
    }

    infectado[I] = 1;

    for(int i = 1; i <= M; i++){
        bool infec_presente = false;
        cin >> A;
        for(int j = 0; j < A; j++){
            cin >> reuniao[j];
            
        }
        if(i >= R){
            for(int j = 0; j < A; j++){
                if(infectado[reuniao[j]] == 1){
                    infec_presente = true;
                    break;
                }
            }
            if(infec_presente == true){
                for(int j = 0; j < A; j++){
                    if(infectado[reuniao[j]] == 0){
                        qtd++;
                        infectado[reuniao[j]] = 1;
                    }
                }
            }
        }

    }

    cout << qtd << "\n";

    return 0;    
}