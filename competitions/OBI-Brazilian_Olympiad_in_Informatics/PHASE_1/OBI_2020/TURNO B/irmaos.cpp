#include <iostream>

using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL); 
    ios::sync_with_stdio(0);
    
    int N, M, A;
    cin >> N;
    cin >> M;
    A = M - N;
    cout << M + A << endl;
 

    return 0;
}