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

bool comp(pii a, pii b){
  if(a.second < b.second) return 1;
  if(a.second > b.second) return 0;
  if(a.first < b.first) return 0;
  return 1;
}

int main(){
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(0);
  string line;
  unordered_map<int, int> chars;
  bool mustPrintBlankLine = false;
  while(getline(cin, line)){
    if(mustPrintBlankLine) cout << endl;
    for(int i = 0; i < (int) line.length(); i++){
      if(chars.find((int)line[i]) != chars.end()){
        chars[(int)line[i]] += 1;
      }else{
        chars[(int)line[i]] = 1;
      }
    }
    vector<pair<int,int>> charsCount(chars.begin(), chars.end());

    sort(charsCount.begin(), charsCount.end(), comp);

    for(auto charCount: charsCount){
      cout << charCount.first << " " << charCount.second << endl;
    }

    chars.clear();
    mustPrintBlankLine = true;
  }
  return 0;
}