#include <bits/stdc++.h>
#define f first
#define s second
#define sz size
#define pb push_back
#define mp make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)
#define SQ(a) (a)*(a)
#define MAX 200005
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

struct TEdge{
  int dist;
  int x, y;
};

bool comp(TEdge a, TEdge b){return a.dist < b.dist;}

int n, m;
TEdge edges[MAX];
int father[MAX];
TEdge mst[MAX];
int weights[MAX];

int find(int x){
  if(father[x] == x) return x;
  return father[x] = find(father[x]);
}

void join(int a, int b){
  a = find(a);
  b = find(b);

  if(a == b) return;

  if(weights[a] < weights[b]){
    father[a] = b;
  }

  if(weights[a] > weights[b]){
    father[b] = a;
  }

  if(weights[a] == weights[b]){
    father[a] = b;
    weights[b]++;
  }
}

int main(){
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(0);

  long long totalCoast, mstCoast;
  while (true){
    cin >> n >> m;
    if(n + m == 0) break;
    totalCoast = 0;
    for(int i = 0; i < m; i++){
      cin >> edges[i].x >> edges[i].y >> edges[i].dist;
      totalCoast += edges[i].dist;
    }

    memset(weights, 0, sizeof(weights));
    for(int i = 0; i < n; i++){
      father[i] = i;
    }
    
    sort(edges, edges+m, comp);

    mstCoast = 0;
    for(int i = 0; i < m; i++){
      if(find(edges[i].x) != find(edges[i].y)){
        join(edges[i].x, edges[i].y);
        mstCoast += edges[i].dist;
      }
    }
    cout << totalCoast - mstCoast << endl;
  }
  
  return 0;
}

// g++ -Wall -std=c++17 resolutions/uri/1152.cpp -o main && ./main < in