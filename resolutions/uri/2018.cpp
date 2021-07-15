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
  if(a.second[2] > b.second[2]) return 1;
  if(a.second[2] < b.second[2]) return 0;
  if(a.first < b.first) return 1;
  return 0;
}

int main(){
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(0);

  unordered_map<string, vector<int>> countries;
  string categories, country;
  while(getline(cin, categories)){
    for(int i = 0; i < 3; i++){
      getline(cin, country);
      if(countries.find(country) == countries.end()){
        countries.insert({country, {0, 0, 0}});
      }
      countries[country][i] += 1;
    }
  }

  vector<pair<string, vector<int>>> data(countries.begin(), countries.end());
  sort(data.begin(), data.end(), comp);

  cout << "Quadro de Medalhas" << endl;
  for(auto &v: data){
    cout << v.first << " " << v.second[0] << " " << v.second[1] << " " << v.second[2] << endl;
  }
  
  return 0;
}

// g++ -Wall -std=c++17 resolutions/uri/2018.cpp -o main && ./main < in