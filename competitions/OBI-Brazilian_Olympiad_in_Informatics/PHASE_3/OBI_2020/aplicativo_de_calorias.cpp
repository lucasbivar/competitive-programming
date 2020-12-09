#include <iostream>
#include <cmath>
using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(0);
    int e1,e2,e3,x;
    cin >> e1;
    cin >> e2;
    cin >> e3;
    cin >> x;
    if(abs(e1-e2) <= x){
        cout << e2 << endl;
    }else{
        cout << e3 << endl;
    }

    return 0;
}