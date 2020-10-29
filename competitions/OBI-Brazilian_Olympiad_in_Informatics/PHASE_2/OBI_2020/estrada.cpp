#include<iostream>
#include <algorithm>
#include <vector>
#include <climits>


using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(0);
    int N, T, aux;
    vector<int> estrada;
    cin >> T;
    cin >> N;
    estrada.push_back(0);
    for(int i = 0; i < N; i++){
        cin >> aux;
        estrada.push_back(aux);
    }
    estrada.push_back(T);
    double min_viz;
    double atual;
    sort(estrada.begin(), estrada.end());
    for(int i = 1; i <estrada.size()-1; i++){
        if(i == 1){
            atual = ((double)estrada[i] - (double)estrada[i-1]) + (((double)estrada[i+1] - (double)estrada[i])/(double)2);
            min_viz = atual;
        }else if(i == estrada.size()-2){
            atual = ((double)estrada[i+1] - (double)estrada[i]) + (((double)estrada[i] - (double)estrada[i-1])/(double)2);
            min_viz = min(atual, min_viz);
        }else{
            atual = (((double)estrada[i] - (double)estrada[i-1])/(double)2) + (((double)estrada[i+1] - (double)estrada[i])/(double)2);
            min_viz = min(atual, min_viz);
        }
    }
    cout.precision(2);
    cout.setf(ios::fixed);
    cout << min_viz << endl;
    
    return 0;
}