#include <iostream>

using namespace std;


int main(){
    int N, C, P, I, A;
    int infect[1005];
    cin >> N >> C;
    for(int i = 1; i <= N; i++){
        infect[i] = 0;
    }
    for(int i = 0; i < C; i++){
        cin >> P >> I;
        for(int j = 0; j < I; j++){
            cin >> A;
            infect[A] = 1;
        }
    }
    for(int i = 1; i <= N; i++){
        if(infect[i] == 0){
            cout << i << endl;
        }
    }

    return 0;
}