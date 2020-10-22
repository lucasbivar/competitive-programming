#include <iostream>
#include <cstring>
#include <algorithm>

struct t_edge{
    int u, v, w;
};

bool comp(t_edge a, t_edge b){
    return a.w < b.w;
}

int N, M;
int weights[1005];
int parents[1005];
t_edge edges[10005];
int find(int x){

    if(parents[x] == x) return x;
    return parents[x] = find(parents[x]);

}

using namespace std;

int main(){
    cin.tie(NULL); 
    cout.tie(NULL);
    ios::sync_with_stdio(0);
    int father_a, father_b;
    memset(weights, 1, sizeof(weights));
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }
    sort(edges, edges+M, comp);
    for(int i = 0; i <= N; i++){
        parents[i] = i;
    }
    int sum = 0;
    for(int i = 0; i < M; i++){
        father_a = find(edges[i].u);
        father_b = find(edges[i].v);
        if(father_a != father_b){
            if(weights[father_a] < weights[father_b]) swap(father_a, father_b);
            parents[father_b] = father_a;
            weights[father_a] += weights[father_b];
            sum += edges[i].w;
        }
    }
    cout << sum << endl;

    return 0;
}