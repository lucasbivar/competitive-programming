#include <bits/stdc++.h>
#include <numeric>  
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

bool comp(pair<string, int> a, pair<string, int> b ){
  if(a.first.size() > b.first.size()) return 1;
  if(a.first.size() < b.first.size()) return 0;
  return (a.second < b.second);
}

vector<pair<string, int>> splitString(string line){
  string currentStr = "";
  vector<pair<string, int>> tokens;
  int pos = 0;

  for(int i = 0; i < (int) line.size(); i++){
    if(line[i] == ' '){
      if(currentStr != ""){
        tokens.push_back({currentStr, pos++});
      }
      currentStr = "";
    }else{
      currentStr += line[i];
    }
  }
  if(currentStr != ""){
    tokens.push_back({currentStr, pos++});
  }
  
  return tokens;
}


int main(){
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(0);

  int n;
  string line;
  vector<pair<string, int>> tokens;

  cin >> n;
  cin.ignore();
  for(int i = 0; i < n; i++){
    getline(cin, line);

    tokens = splitString(line);
    sort(tokens.begin(), tokens.end(), comp);

    for(int j = 0; j < (int) tokens.size(); j++){
      if(j == 0){
        cout << tokens[j].first;
      }else{
        cout << " " << tokens[j].first;
      }
    }
    cout << endl;
  }

  return 0;
}

// g++ -Wall -std=c++17 resolutions/uri/1244.cpp -o main && ./main < in