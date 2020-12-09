#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
vector<int> amgs[100005];
int idades[100005];
int visited[100005];
int qtd[100005];
int anf, l, r;
void DFS(int x){
    for(int i = 0; i < amgs[x].size(); i++){
        int v = amgs[x][i];
        if(visited[v] != -1) continue;
        if(idades[v] < l || idades[v] > r) continue;
        visited[v] = 1;
        qtd[v] += 1;
        DFS(v);
    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(0);
    int p, f, a, b;
    
    cin >> p >> f;
    for(int i = 1; i <= p; i++){
        cin >> a >> b;
        idades[i] = a;
        amgs[i].push_back(b);
        amgs[b].push_back(i);
    }
    memset(qtd, 0, sizeof(qtd));
    for(int i = 0; i < f; i++){
        cin >> anf >> l >> r;
        memset(visited, -1, sizeof(visited));
        visited[anf] = 1;
        qtd[anf] += 1;
        DFS(anf);
    }
    cout << qtd[1];
    for(int i = 2; i <= p; i++){
        cout << " " << qtd[i];
    }
    cout << endl;
    return 0;
}