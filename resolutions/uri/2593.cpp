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

template < class T >
ostream& operator << (ostream& os, const vector<T>& v) {
  int quantity = 0;
  for (typename vector<T>::const_iterator ii = v.begin(); ii != v.end(); ++ii){
    quantity == 0 ? os << *ii : os << " " << *ii;
    quantity++; 
  }
  os << endl;
  return os;
}

int main(){
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(0);

  string bigString;
  string auxString = "";
  int pos = 0;
  int n;
  unordered_map<string, vector<int>> wordPositions;

  getline(cin, bigString);
  for(int i = 0; i < (int) bigString.size(); i++){
    if(bigString[i] != ' '){
      auxString += bigString[i];
    }else{
      wordPositions[auxString].pb(pos);
      pos = i+1;
      auxString = "";
    }
  }
  if(auxString != ""){
    wordPositions[auxString].pb(pos);
  }

  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> auxString;
    if(wordPositions.find(auxString) != wordPositions.end()){
      cout << wordPositions[auxString];
    }else{
      cout << -1 << endl;
    }
  }

  return 0;
}

// g++ -Wall -std=c++17 resolutions/uri/2593.cpp -o main && ./main < in