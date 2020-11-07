#include <iostream>

using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(0);
    int c, a;
    cin >> c;
    cin >> a;
    c--;
    int resp = a/c;
    int rest = a%c;
    if(rest > 0){
        resp++;
    }
    cout << resp << endl;
    
    return 0;
}