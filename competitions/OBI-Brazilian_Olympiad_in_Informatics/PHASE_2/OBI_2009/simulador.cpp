//Score: 70/100
#include <iostream>
#include<vector>


using namespace std;

vector<int> memoria;
int N, M,X, Y;
char action;

long long soma(int x, int y){
    if(y < x) swap(x, y);
    long long soma = 0;
    
    for(int j = x; j <= y; j++){
        soma += memoria[j];
    }   
    
    return soma;
}

void inverte(int x, int y){
    if(y < x) swap(x, y);
    while (true){
        if(x >= y) break;
        swap(memoria[x], memoria[y]);
        x++;
        y--;
    }
    
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(0);
    cin >> N >> M;
    
    for(int i = 0; i <= N; i++){
        memoria.push_back(i);
    }
    
    for(int i = 0; i < M; i++){
        cin >> action >> X >> Y;
        if(action == 'S'){
            cout << soma(X, Y) << endl;
        }else{
            inverte(X, Y);
        }

    }
    return 0;
}