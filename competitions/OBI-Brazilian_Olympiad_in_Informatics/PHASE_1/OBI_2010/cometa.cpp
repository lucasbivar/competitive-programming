#include <iostream>

using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(0);
    int N;
    cin >> N;
    int res = N + (76 - ((N - 1986)%76));
    cout << res << endl;

    return 0;
}