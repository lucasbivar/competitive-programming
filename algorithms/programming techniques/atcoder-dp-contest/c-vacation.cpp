#include <iostream>
#include<cstring>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;
int n, a[100005][3], dp[100005][3];
//bottom-up
int max_points(){
    for(int i = 0; i < 3; i++){
        dp[0][i] = a[0][i];
    }
    for(int i = 1; i < n; i++){

        for(int j = 0; j < 3; j++){
            dp[i][j] = 0;
            for(int k = 0; k < 3; k++){
                if(k == j) continue;
                dp[i][j] = max(dp[i][j], dp[i-1][k] +a[i][j]);
            }
        }
    }
    return max({dp[n-1][0], dp[n-1][1], dp[n-1][2]});
}
//top-down
int max_points_recursive(int act, int pos){
    if(act == 0) return a[act][pos];
    if(dp[act][pos] != -1) return dp[act][pos];

    
    dp[act][pos] = 0;
    for(int k = 0; k < 3; k++){
        if(k == pos) continue;
        dp[act][pos] = max(dp[act][pos], max_points_recursive(act-1,k) + a[act][pos]);
    }
    
    return dp[act][pos];
}
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(0);
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }
    cout << max({max_points_recursive(n-1, 2), max_points_recursive(n-1, 1), max_points_recursive(n-1, 0)}) << endl;
    return 0;
}