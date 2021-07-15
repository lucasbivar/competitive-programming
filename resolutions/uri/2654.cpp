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

bool comp(pair<string, vector<int>> a, pair<string, vector<int>> b){
  if(a.second[0] > b.second[0]) return 1;
  if(a.second[0] < b.second[0]) return 0;
  if(a.second[1] > b.second[1]) return 1;
  if(a.second[1] < b.second[1]) return 0;
  if(a.second[2] < b.second[2]) return 1;
  if(a.second[2] > b.second[2]) return 0;
  if(a.first < b.first) return 1;
  return 0;
}


int main(){
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(0);

  int n, power, killed, died;
  vector<pair<string, vector<int>>> data;
  string name;

  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> name >> power >> killed >> died;
    data.pb({name, {power, killed, died}});
  }

  sort(data.begin(), data.end(), comp);

  cout << data[0].first << endl;

  return 0;
}

// g++ -Wall -std=c++17 resolutions/uri/2654.cpp -o main && ./main < in