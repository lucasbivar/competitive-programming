#include <iostream>
#include <set>
#include <vector>

using namespace std;

#define MAXV 1001000

int n,distancia[MAXV];
vector<pair<int,int>> adj[MAXV];

void dijkstra(int fonte){
	for(int i=0;i<=n;i++)//Marca como não visitado
		distancia[i]=-1;

	set<pair<int,int>> fila;
	fila.insert({0,fonte});//Par de distância e vértice

	pair<int,int> aux;
	while(!fila.empty()){//Enquanto ainda há nós para visitar
		aux=*fila.begin();
		fila.erase(fila.begin());

		int vertice=aux.second;
		int distV=aux.first;

		if(distancia[vertice]!=-1)//Se já foi visitado, passa para o próximo
			continue;

		distancia[vertice]=distV;

		for(int i = 0; i < (int)adj[vertice].size(); i++){
			if(distancia[adj[vertice][i].first]!=-1)//Se já foi visitado, não adicionar no set
				continue;
			fila.insert(make_pair(adj[vertice][i].second+distV, adj[vertice][i].first));// d[vizinho]=d[vertice]+peso_da_aresta
		}
	}
}