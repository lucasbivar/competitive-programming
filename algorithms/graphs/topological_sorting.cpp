#include <vector>
#include <iostream>
using namespace std;
//------------------------------
#define MAXN 100100
int n; //number of nodes
int m; // number of edges
vector<int> graph[MAXN];
int degree[MAXN];
vector<int> list; // nodes with degree = 0
//------------------------------
int main(){
	
	cin >> n >> m;

	for(int i = 1;i <= m;i++){
		int x, y;
		cin >> x >> y;

		// task X has to be performed before task Y
		degree[y]++;
		graph[x].push_back(y);
	}
	
	for(int i = 1;i <= n;i++){
        if(degree[i] == 0) list.push_back(i);
    }
	int start = 0;
	while(start < (int)list.size()){

		int current = list[start];
		start++;
		
		for(int i = 0;i < (int)graph[current].size();i++){
			int v = graph[current][i];
			degree[v]--;
			if(degree[v] == 0) list.push_back(v); // if the degree becomes zero, we add the node to the list
		}
	}

	//now, if the size of the list is smaller than the number of nodes,
	// we know that it is impossible to perform the procedure

	if((int)list.size() < n) cout << "impossible\n";
	else{
		for(int i = 0;i < (int)list.size();i++) cout << list[i] << " ";
		cout << endl;
	}
	
	return 0;
}