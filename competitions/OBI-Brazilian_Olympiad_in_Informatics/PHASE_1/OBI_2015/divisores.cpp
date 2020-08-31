#include <iostream>
#include <vector>

using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(0);
    int N;
    int d = 2;
    int qtd = 0;
    vector<int> expoentes;

    cin >> N;
    while (N != 1){
       if(N % d == 0){
           N = N/d;
           qtd++;
           continue;
       }
       if(qtd > 0){
           expoentes.push_back(qtd);
       }
       qtd = 0;
       d++;
    }
    if(qtd > 0){
           expoentes.push_back(qtd);
    }
    long long res = 1;
    for(int i = 0; i < (int)expoentes.size(); i++){
        res *= (expoentes[i]+1);
    }
    cout << res << endl;


    
  
    return 0;
}