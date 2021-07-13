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

  unordered_map<char, int> notesDuration;
  notesDuration.insert({'W', 64});
  notesDuration.insert({'H', 32});
  notesDuration.insert({'Q', 16});
  notesDuration.insert({'E', 8});
  notesDuration.insert({'S', 4});
  notesDuration.insert({'T', 2});
  notesDuration.insert({'X', 1});

  string current;
  ll numerator, measures;
  while (true){
    cin >> current;
    if(current == "*") break;
    numerator = measures = 0;
    for(int i = 1; i < (int) current.size(); i++){
      if(current[i] == '/'){
        if(numerator == 64LL) measures++;
        numerator = 0;
      }else{
        numerator += (ll) notesDuration[current[i]];
      }
    }
    cout << measures << endl;
  }
  
  return 0;
}

// g++ -Wall -std=c++17 resolutions/uri/1430.cpp -o main && ./main < in