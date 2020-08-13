#include <iostream>
#include <vector>

using namespace std;

#define MAXN 1000 

vector<int> adj[MAXN]; 

int visited[MAXN];

void dfs(int v){
	for(int i = 0; i < (int)adj[v].size(); i++){
		if(visited[adj[v][i]] != 0) continue; 
		visited[adj[v][i]] = 1;
		dfs(adj[v][i]); 
	}
}

int main(){

	for(int i = 0; i < MAXN; i++){
        visited[i] = 0; 
    }
	visited[0] = 1;
    dfs(0);
}