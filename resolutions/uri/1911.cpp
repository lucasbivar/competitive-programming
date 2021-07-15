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


int main(){
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(0);
  int n, m, falseSignatures = 0, currentDifferences;
  string aux1, aux2, currentOriginalSignature;
  unordered_map<string, string> originalSignatures;
  while (cin >> n){
    if(n == 0) break;
    for(int i = 0; i < n; i++){
      cin >> aux1 >> aux2;
      originalSignatures.insert({aux1, aux2});
    }
    cin >> m;
    for(int i = 0; i < m; i++){
      cin >> aux1 >> aux2;
      currentOriginalSignature = originalSignatures[aux1];
      currentDifferences = 0;
      for(int i = 0; i < (int) min(currentOriginalSignature.size(), aux2.size()); i++){
        if(aux2[i] != currentOriginalSignature[i]) currentDifferences++;
        if(currentDifferences > 1){
          falseSignatures++;
          break;
        }
      }
    }
    cout << falseSignatures << endl;

    //reset
    originalSignatures.clear();
    falseSignatures = 0;
  }

  return 0;
}

// g++ -Wall -std=c++17 resolutions/uri/1911.cpp -o main && ./main < in