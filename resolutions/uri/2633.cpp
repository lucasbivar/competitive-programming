#include <bits/stdc++.h>
#define f first
#define s second
#define sz size
#define pb push_back
#define mp make_pair
using namespace std;
#define endl '\n'
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

bool comp(pair<string, int> a, pair<string, int> b){
  if(a.second < b.second) return true;
  return false;
}

int main(){
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(0);
  int n, date, i;
  string meat;
  vector<pair<string, int>> pieces;
  while (cin >> n){
    for(i = 0; i < n; i++){
      cin >> meat >> date;
      pieces.pb({meat, date});
    }
    sort(pieces.begin(), pieces.end(), comp);
    i = 0;
    for(auto &p: pieces){
      if(i == 0) cout << p.first;
      else cout << " " << p.first;
      i++;
    }
    cout << endl;
    pieces.clear();
  }
  
  return 0;
}

// g++ -Wall -std=c++17 resolutions/uri/2633.cpp -o main && ./main < in