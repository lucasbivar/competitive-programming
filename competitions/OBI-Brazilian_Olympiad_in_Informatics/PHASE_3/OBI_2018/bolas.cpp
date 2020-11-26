#include <iostream>
#include <cstring>

using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(0);
    int count[10];
    int N;
    bool possible = true;
    memset(count, 0, sizeof(count));
    for(int i = 0; i < 8;i++){
        cin >> N;
        count[N]++;
        if(count[N] > 4){
            possible = false;
        }
    }
    char ans = (possible == true) ? 'S' : 'N';
    cout << ans << endl;
    return 0;
}