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

  set<string> shopping_list;
  int n, j;
  string currentList, currentItem;

  cin >> n;
  cin.ignore();
  for(int i = 0; i < n; i++){
    getline(cin, currentList);

    currentItem = "";
    for(j = 0; j < (int) currentList.size(); j++){
      if(currentList[j] == ' '){
        shopping_list.insert(currentItem);
        currentItem = "";
      }else{
        currentItem += currentList[j];
      }
    }
    if(currentItem != "") shopping_list.insert(currentItem);

    j = 0;
    for(auto &item: shopping_list){
      if(j == 0) cout << item;
      else cout << " " << item;
      j++;
    }

    cout << endl;
    shopping_list.clear();
  }


  return 0;
}

// g++ -Wall -std=c++17 resolutions/uri/2729.cpp -o main && ./main < in