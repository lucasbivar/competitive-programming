#include <iostream>
#include<cstring>
#include <algorithm>
#include <cmath>

using namespace std;
int n, h[100005], dp[100005];

int min_cost(){

    dp[0] = 0;
    dp[1] = abs(h[1] - h[0]);
    for(int i = 2; i < n; i++){
        dp[i] = min(dp[i-1] + abs(h[i] - h[i-1]), dp[i-2]+abs(h[i]-h[i-2]));
    }

    return dp[n-1];
}
int min_cost_recursive(int pos){
    if(pos == 0) return dp[pos] = 0;
    if(pos == 1) return dp[pos] = abs(h[1] - h[0]);

    if(dp[pos] != -1) return dp[pos];
    cout << pos << endl;
    return dp[pos] =  min(min_cost_recursive(pos-1) + abs(h[pos] - h[pos-1]), min_cost_recursive(pos-2) + abs(h[pos] - h[pos-2]));
}
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(0);
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> h[i];
    }
    cout << min_cost_recursive(n-1) << endl;
    return 0;
}