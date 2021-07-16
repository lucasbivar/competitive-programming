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

bool comp(int a, int b) {return a > b;}

int main(){
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(0);

  int m, n, quantity;
  int arrivedOrder[1005];
  int gradeOrder[1005];

  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> m;
    for(int j = 0; j < m; j++){
      cin >> arrivedOrder[j];
      gradeOrder[j] =  arrivedOrder[j];
    }

    sort(gradeOrder, gradeOrder+m, comp);
    quantity = 0;
    for(int j = 0; j < m; j++){
      if(gradeOrder[j] == arrivedOrder[j]) quantity++;
    }
    cout << quantity << endl;
  }

  return 0;
}

// g++ -Wall -std=c++17 resolutions/uri/1548.cpp.cpp -o main && ./main < in