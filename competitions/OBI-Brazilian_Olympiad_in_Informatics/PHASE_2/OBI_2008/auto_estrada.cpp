#include <iostream>

using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(0);
    int quantity = 0;
    int C;
    char A;
    cin >> C;
    for(int i = 0; i < C; i++){
        cin >> A;
        if(A == 'P' || A == 'C') quantity += 2;
        else if(A == 'A') quantity += 1;
    }
    cout << quantity << endl;
    
    
    return 0;
}