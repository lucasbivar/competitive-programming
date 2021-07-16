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

  int n, winners = 0;
  char aux;
  string word;
  queue<string> toBeProcessed;
  stack<string> accumulated;

  cin >> n;
  for(int i = 0; i < n; i++){
    word = "";
    for(int j = 0; j < 4; j++){
      cin >> aux;
      word += aux;
    }
    toBeProcessed.push(word);
  }

  while(!toBeProcessed.empty()){
    if(accumulated.empty()) accumulated.push("FACE");

    string reverseFrontQueue = string(toBeProcessed.front().rbegin(), toBeProcessed.front().rend());
   
    if(accumulated.top() == reverseFrontQueue){
      winners++;
      accumulated.pop();
    }else{
      accumulated.push(toBeProcessed.front());
    }

    toBeProcessed.pop();
  }

  cout << winners << endl;

  return 0;
}

// g++ -Wall -std=c++17 resolutions/uri/1944.cpp -o main && ./main < in