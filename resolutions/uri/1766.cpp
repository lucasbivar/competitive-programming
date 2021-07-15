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

struct TReindeer{
  string name;
  int weight, age;
  double height;
};

bool comp(TReindeer a, TReindeer b){
  if(a.weight > b.weight) return 1;
  if(a.weight < b.weight) return 0;
  if(a.age < b.age) return 1;
  if(a.age > b.age) return 0;
  if(a.height < b.height) return 1;
  if(a.height > b.height) return 0;
  if(a.name < b.name) return 1;
  return 0;
}

int main(){
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(0);

  TReindeer currentReindeer;
  vector<TReindeer> reindeers;
  int t, n, m;

  cin >> t;
  for(int i = 0; i < t; i++){
    cin >> n >> m;
    for(int j = 0; j < n; j++){
      cin >> currentReindeer.name >> currentReindeer.weight >> currentReindeer.age >> currentReindeer.height;
      reindeers.pb(currentReindeer);
    }
    sort(reindeers.begin(), reindeers.end(), comp);
    cout << "CENARIO {" << i+1 << "}" << endl;
    for(int j = 0; j < m; j++){
      cout << j+1 << " - " << reindeers[j].name << endl;
    }
    reindeers.clear();
  }

  return 0;
}

// g++ -Wall -std=c++17 resolutions/uri/1766.cpp -o main && ./main < in