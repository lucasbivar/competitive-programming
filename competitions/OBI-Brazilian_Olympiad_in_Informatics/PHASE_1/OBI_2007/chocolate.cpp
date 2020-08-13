#include <iostream>

using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(0);
    int n, x;
    int soma = 0;
    cin >> n;
    for(int i=0; i < n; i++){
        cin >> x;
        soma += (x-1);
    }
    cout << soma << endl;
}