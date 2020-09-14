//Time Complexity : O(n)
#include <iostream>
#include <cstring>

#define MAXN 1000100

using namespace std;

int n, dp[MAXN]; // number and auxiliary vector

int fib(int x){
    //If I have ever calculated the value of fib (x), return the value salved in dp[x]
    if(dp[x] != -1) return dp[x];

    //base cases
    if(x == 0) return 0;
    if(x == 1) return 1;

    //Calculate the value of fib (x) and save it in dp[x]
    return dp[x] = fib(x-1) + fib(x-2);
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(0);

    cin >> n;
    memset(dp, -1, sizeof(dp));

    cout << fib(n) << endl;

    return 0;
}