#include <bits/stdc++.h>
#define f first
#define s second
#define sz size
#define pb push_back
#define mp make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)
#define SQ(a) (a)*(a)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

// Time Complexity: O(n log n)

bool comp(pii a, pii b){
  if(a.first < b.first) return true;
  if(a.first > b.first) return false;
  if(a.second > b.second) return true;
  return false;
}

bool solve(vector<pii>& dragons, int strength){
  bool win = true;
  sort(dragons.begin(), dragons.end(), comp);

  for(auto& dragon : dragons){
    if(strength <= dragon.first){
      win = false;
      break;
    }else{
      strength += dragon.second;
    }
  }
  
  return win;
}

int main(){
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(0);

  vector<pii> dragons;
  int n, strength, x, y;

  cin >> strength >> n;
  for(int i = 0; i < n; i++){
    cin >> x >> y;
    dragons.push_back({x, y});
  }

  
  string ans = solve(dragons, strength) ? "YES" : "NO";
  cout << ans << endl;
  return 0;
}

// g++ -Wall -std=c++17 474E.cpp -o main && ./main < in