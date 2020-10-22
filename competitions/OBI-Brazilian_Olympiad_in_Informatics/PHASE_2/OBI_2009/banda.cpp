#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int graph[105][105];

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(0);
    int N, M,U,V,W;
    memset(graph, 0, sizeof(graph));
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        cin >> U >> V >> W;
        graph[U][V] = graph[V][U] = W;
    }
    int sol[3], ans = -1;
    for(int i = 1; i <= N; i++){
        for(int j = i+1; j <= N; j++){
            for(int k = j+1; k <= N; k++){
                if(graph[i][j] + graph[i][k] + graph[j][k] > ans){
                    ans = graph[i][j] + graph[i][k] + graph[j][k];
                    sol[0] = i, sol[1]=j, sol[2]= k;
                }
            }   
        }
    }
    cout << sol[0] << " " << sol[1] << " " << sol[2] << endl;
    return 0;
}