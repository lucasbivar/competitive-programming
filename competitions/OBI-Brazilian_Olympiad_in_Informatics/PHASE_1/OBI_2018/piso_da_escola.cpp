#include <iostream>

using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(0);
    int L, C, tipo_1, tipo_2;
    cin >> L;
    cin >> C;
    tipo_1 = (L*C) + ((L-1)*(C-1));
    tipo_2 = 2*(L-1) + 2*(C-1);
    cout << tipo_1 << endl;
    cout << tipo_2 << endl;
    return 0;
}