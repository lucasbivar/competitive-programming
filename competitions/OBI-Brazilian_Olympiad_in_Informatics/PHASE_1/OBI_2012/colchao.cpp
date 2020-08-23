#include <iostream>

using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(0);
    int A, B, C, H, L;
    cin >> A >> B >> C;
    cin >> H >> L;
    if((A <= H && B <= L) || (A <= L && B <= H)){
        cout << "S" << endl;
        return 0;
    }else if((A <= H && C <= L) || (A <= L && C <= H)){
        cout << "S" << endl;
        return 0;
    }else if((B <= H && C <= L) || (B <= L && C <= H)){
        cout << "S" << endl;
        return 0;
    }else{
        cout << "N" << endl;
        return 0;
    }
    

    return 0;
}