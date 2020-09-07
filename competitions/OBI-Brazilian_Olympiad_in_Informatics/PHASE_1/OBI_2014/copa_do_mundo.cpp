#include <iostream>
#include <algorithm>

using namespace std;

struct edge{
    int x, y, weight;
};

bool comp(edge a, edge b){
    return a.weight < b.weight;
}

edge mst[124750];
int parents[500];
edge edges[124750];

int find(int x){
    if(parents[x] == x) return x;
    return parents[x] = find(parents[x]);
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(0);
    int N, F, R;
    cin >> N >> F >> R;
    
    for(int i = 0; i < F + R; i++){
        cin >> edges[i].x >> edges[i].y >> edges[i].weight;
    }
    for(int i = 1; i <= N; i++){
        parents[i] = i;
    }
    sort(edges, edges+F, comp);
    sort(edges + F, edges + F + R, comp);
    int size = 0;
    int compr = 0;
    for(int i = 0; i < F + R; i++){
        int a = find(edges[i].x);
        int b = find(edges[i].y);
        if(a != b){
            parents[a] = b;
            mst[++size] = edges[i];
            compr += edges[i].weight;
        }
    }

    cout << compr << endl;
    return 0;
}