#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, distancia[1001000];
vector<int> grafo[1001000];

void BFS(int fonte){
	for(int i=0; i<1001000; i++)//Marca os vértices como não visitados
		distancia[i]=-1;

	queue<int> fila;
	fila.push(fonte);//Insere a fonte na fila
	distancia[fonte]=0;//Iniciando a distancia da fonte como zero	

	int aux;
	while(!fila.empty()){
		aux=fila.front();//Pega o primeiro elemento da fila
		fila.pop();//Apaga o primeiro elemento da fila
	
		for(int i = 0; i < (int)grafo[aux].size(); i++){
			if(distancia[grafo[aux][i]]!=-1)//Se foi visitado, não adiciona na fila
				continue;
			
			distancia[grafo[aux][i]] =  distancia[aux]+1;
			fila.push(grafo[aux][i]);
		}
	}

}