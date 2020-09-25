#include <iostream>

using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL); 
    ios::sync_with_stdio(0);
    int N, A, fab_p, fab_m;
    int qtd_p = 0;
    int qtd_m = 0;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> A;
        if(A == 1){
            qtd_p++;
        }else{
            qtd_m++;
        }
    }
    cin >> fab_p;
    cin >> fab_m;
    bool atendidos = true;
    if(qtd_p > fab_p){
        atendidos = false;
    }
    if(qtd_m > fab_m){
        atendidos = false;
    }

    char resp = (atendidos == true) ? 'S' : 'N';
    cout << resp << endl;

    return 0;
}