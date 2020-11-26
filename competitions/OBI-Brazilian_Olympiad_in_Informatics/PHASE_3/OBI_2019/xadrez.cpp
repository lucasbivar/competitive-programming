#include <iostream>

using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(0);
    int n, t;
    cin >> n >> t;
    if(t == 0){
        cout << n;
    }else if(t == 1){
        cout << n *(n-1);
    }else{
        cout << (n*(n-1)*(n-2))/6; 
    }
    cout << endl;
    return 0;
}