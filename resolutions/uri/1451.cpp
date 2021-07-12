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


int main(){
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(0);

  list<string> beijuText;
  string strAux;
  list<string> storeTxts;
  char lastChange;

  while (getline(cin, strAux)){
    storeTxts.push_back(strAux);
  }

  for(auto txt: storeTxts){
    strAux = "";
    lastChange = '-';

    for(auto c: txt){
      if(c == '[' || c == ']'){
        if(lastChange == '['){
          beijuText.push_front(strAux);
        }else{
          beijuText.push_back(strAux);
        }
        strAux = "";
        lastChange = c;
      }else{
        strAux += c;
      }
    }
    if(strAux != ""){
      if(lastChange == '['){
        beijuText.push_front(strAux);
      }else{
        beijuText.push_back(strAux);
      }
    }
    for(auto c: beijuText){
      cout << c;
    }
    cout << endl;
    beijuText.clear();
  }
  

  return 0;
}

// g++ -Wall -std=c++17 problem.cpp -o main && ./main < in