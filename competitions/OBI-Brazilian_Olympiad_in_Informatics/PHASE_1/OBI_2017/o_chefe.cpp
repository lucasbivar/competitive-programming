#include <iostream>
#include <vector>

using namespace std;

int ages[505];
int minimum_age;
int visited[505];
vector<int> graph[505];

void change(int A, int B, int N){
    swap(graph[A], graph[B]);
    for (int i = 1; i <= N; i++){
        for(int j = 0; j < (int)graph[i].size(); j++){
            if(graph[i][j] == A){
                graph[i][j] = B;
                continue;
            }
            if(graph[i][j] == B){
                graph[i][j] = A;
            }
        }
    }
    
}
void DFS(int f){
    visited[f] = 1;
    for(int i = 0; i < (int)graph[f].size(); i++){
        if(visited[graph[f][i]] == 1) continue;
        if(ages[graph[f][i]] < minimum_age){
            minimum_age = ages[graph[f][i]];
        }
        DFS(graph[f][i]);
    }

}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(0);
    int N, M, I, A, B;
    char action;
    while(cin >> N >> M >> I){
        for(int i = 1; i <= N; i++){
            cin >> ages[i]; 
        }
        for(int i = 0; i < M; i++){
            cin >> A >> B;
            graph[B].push_back(A);
        }
        for(int i = 0; i < I; i++){
            cin >> action;
            if(action == 'P'){
                cin >> A;
                for(int j = 1; j <= N; j++){
                    visited[j] = 0;
                }
                minimum_age = 105;
                DFS(A);
                if(minimum_age == 105){
                    cout << "*" << "\n";
                }else{
                    cout << minimum_age << "\n";
                }
            }else{
                cin >> A >> B;
                change(A, B, N);
            }
        }
        for(int i = 1; i <= N; i++){
            graph[i].clear();
        }
    }

    return 0;
}