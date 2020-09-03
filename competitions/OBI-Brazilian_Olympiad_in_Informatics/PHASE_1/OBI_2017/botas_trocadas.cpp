#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(0);
    int N, tamanho;
    char lado;
    map<int, pair<int, int>> pares;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> tamanho >> lado;
        if(pares.find(tamanho)!= pares.end()){
            if(lado == 'E'){
                pares[tamanho].first++;
            }else{
                pares[tamanho].second++;
            }
        }else{
            if(lado == 'E'){
                pares.insert(make_pair(tamanho,make_pair(1, 0)));
            }else{
                pares.insert(make_pair(tamanho,make_pair(0, 1)));
            }
        }
    }
    int ans = 0;
    for(map<int,pair<int,int>>::iterator it = pares.begin(); it != pares.end(); it++){
        int direito = it->second.second;
        int esquerdo = it->second.first;
        ans += min(direito, esquerdo);
    }
    cout << ans << endl;
    
    return 0;
}