#include <iostream>

using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(0);
    int N, D, A;
    cin >> N;
    cin >> D;
    cin >> A;
    if(D >= A){
        cout << D - A << endl;
    }else{
        cout << (N - A) + D << endl;
    }
    
    return 0;
}