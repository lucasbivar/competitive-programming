#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int memo[1000];

int dp(int x, vector<int> & v){

    if(x < 0) return 0;
    if(x == 0) return 1;

    if(memo[x] != -1) return memo[x];

    for(int i = 0; i < v.size(); i++){
        if(dp(x-v[i], v)) return memo[x-v[i]] = 1; 
    }
    return memo[x] = 0;
}


int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(0);
    memset(memo, -1, sizeof(memo));
    vector<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    cout << dp(4, a) << endl;
    return 0;
}