#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(0);
    int N;
    int alturas[100005];
    bool e[100005], d[100005];
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> alturas[i];
        e[i] = false;
        d[i] = false;
    }
    int me = alturas[0];
    for(int i = 1; i < N; i++){
        if(alturas[i] < me){
            e[i] = true;
        }
        me = max(me, alturas[i]);
    }
    int md = alturas[N-1];
    for(int i = N-2; i > -1; i--){
        if(alturas[i] < md){
            d[i] = true;
        }
        md = max(alturas[i], md);
    }
    int ans = 0;
	for (int i = 1; i < N - 1; i++) {
		if (e[i] && d[i]){
            ans++;
        } 
	}
    cout << ans << endl;
    return 0;
}