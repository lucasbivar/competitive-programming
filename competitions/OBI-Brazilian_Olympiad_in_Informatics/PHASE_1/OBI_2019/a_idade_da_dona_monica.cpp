#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(0);
    int maior = 0;
    int M, A, B, C;
    cin >> M;
    cin >> A;
    maior = max(A, maior);
    cin >> B;
    maior = max(B, maior);
    C = M - A - B;
    maior = max(C, maior);
    cout << maior << endl;
    
    return 0;
}