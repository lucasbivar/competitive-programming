#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct awards{
    int n, o, b,p;
};

bool comp(awards a, awards b){
    if(a.o == b.o){
        if(a.p == b.p){
            if(a.b == b.b){
                if(a.n < b.n){
                    return 1;
                }else{
                    return 0;
                }
            }else if(a.b > b.b){
                return 1;
            }else{
                return 0;
            }

        }else if(a.p > b.p){
            return 1;
        }else{
            return 0;
        }
    }else if(a.o > b.o){
        return 1;
    }else{
        return 0;
    }

}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(0);
    awards team;
    awards teams[105];
    int N, M,O,P,B;
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        team.n = i;
        team.o = 0;
        team.p = 0;
        team.b = 0;
        teams[i-1]= team;
    }
    for(int i = 0; i < M; i++){
        cin >> O >> P >> B;
        teams[O-1].o += 1;
        teams[P-1].p += 1;
        teams[B-1].b += 1;
    }
    sort(teams, teams+N, comp);
    for(int i = 0; i < N;i++){
        if(i == N-1){
            cout << teams[i].n << endl;
        }else{
            cout << teams[i].n << " ";
        }
    }
    return 0;
}
