#include <bits/stdc++.h>
#define f first
#define s second
#define sz size
#define pb push_back
#define mp make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)
#define SQ(a) (a)*(a)
using namespace std;
#define endl '\n'
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;


int main(){
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(0);

  int p, mid,currentPos, ans;

  while(cin >> p){
    mid = p/2;
    ans = 1;
    currentPos = 2;
  
    while(currentPos != 1){
      if(currentPos <= mid){
        currentPos += currentPos;
      }else{
        currentPos -= (p - currentPos + 1);
      }
      ans++;
    }
    cout << ans << endl;
  }
  return 0;
}

// g++ -Wall -std=c++17 resolutions/uri/1709.cpp -o main && ./main < in
// 8 - ans: 6
// if currentPosition <= middle: nextPosition = 2*currentPosition
// else: nextPosition = 2*currentPosition - size -1)

// 1 2 3 4   5 6 7 8
// 5 1 6 2   7 3 8 4
// 7 5 3 1   8 6 4 2
// 8 7 6 5   4 3 2 1
// 4 8 3 7   2 6 1 5
// 2 4 6 8   1 3 5 7
// 1 2 3 4   5 6 7 8