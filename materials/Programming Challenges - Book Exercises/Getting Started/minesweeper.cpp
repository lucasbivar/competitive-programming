#include <iostream>

using namespace std;

int tab[105][105];
int movI[8] = {-1,-1,0,1,1,1,0,-1};
int movY[8] = {0,1,1,1,0,-1,-1,-1};
int N, M;
char a;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(0);

    int c = 1;

    while(cin >> N >> M){
        if(N == 0 && M == 0) break;

        if(c != 1) cout << endl;
        //Input
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                cin >> a;
                if(a == '.') tab[i][j] = 0;
                if(a == '*') tab[i][j] = -1;
            }
        }
        //Solve
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(tab[i][j] == -1){
                    for(int k = 0; k < 8; k++){
                        int new_i = i + movI[k]; int new_j = j + movY[k];
                        if(new_i < 0 || new_i > (N-1) || new_j < 0 || new_j > (M-1) || tab[new_i][new_j] == -1) continue;
                        tab[new_i][new_j] += 1;
                    }
                }
            }
        }
        //Output
        cout << "Field #" << c++ <<":"<< endl;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(tab[i][j] == -1){
                    cout << '*';
                }else{
                    cout << tab[i][j];
                }
            }
            cout << endl;
        }
    }

    return 0;
}