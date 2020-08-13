#include <iostream>

using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(0);

    int N, D;
    long long M;
    char C;
    bool ultrapassou = false;
    pair<long long, long long> posicao;
    posicao.second = 0;
    posicao.first = 0;
    
    cin >> N >> M;
    M *= M;
    for(int i = 0; i < N; i++){
        cin >> C >> D;
        if(C == 'N'){
            posicao.second += D;
        }else if(C == 'S'){
            posicao.second -= D;
        }else if(C == 'L'){
            posicao.first += D;
        }else if(C == 'O'){
            posicao.first -= D;
        }
        if(posicao.first * posicao.first + posicao.second * posicao.second > M){
            ultrapassou = true;
        }
    }
    if(ultrapassou == true){
        cout << "1" << endl;
    }else{
        cout << "0" << endl;
    }
    return 0;
}