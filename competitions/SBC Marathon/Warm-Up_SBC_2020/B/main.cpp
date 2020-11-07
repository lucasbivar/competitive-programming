#include <iostream>

using namespace std;

int main (){
    int n, cont = 0;
    cin >> n;
    int fact[10];
    fact[0] = 1;

    for (int i = 1; i < 10; i++){
        fact[i] = fact[i-1] * i;
    }
    for (int i = 9; i > 0; i--){
        cont += n/fact[i];
        n = n%fact[i];
    }
    cout << cont << endl;

    return 0;
}
