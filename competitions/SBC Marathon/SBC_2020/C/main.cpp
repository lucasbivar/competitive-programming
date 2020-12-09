#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;
map<string, int> index_a[100005];
map<string, int> index_b[100005];
string uni_a[100005];
string uni_b[100005];

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(0);
    int m, n;
    string name;
    cin >> m >> n;
    for(int i = 0; i < m; i++){
        cin >> name;
        uni_a[i] = name;
    }
    for(int i = 0; i < n; i++){
        cin >> name;
        uni_b[i] = name;
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            string nova = uni_a[i] + uni_b[j];
            index_a[i].insert({nova, j});
            index_b[j].insert({nova, i});
        }
    }
    int a = 0;
    for(int i = 0; i < m; i++){
        bool ok = false;
        for(map<string, int> :: iterator it = index_a[i].begin(); it != index_a[i].end(); it++){
            for(int j = 0; j < i; j++){
                if(index_a[j].find(it->first) != index_a[j].end()){
                    ok = true;
                    break;
                }
            }
            if(ok == true) break;
            for(int j = i+1; j < m; j++){
                if(index_a[j].find(it->first) != index_a[j].end()){
                    ok = true;
                    break;
                }
            }
            if(ok == true) break;
        }  
        if(ok == false){
            a++;
        }
    }
    int b = 0;
    for(int i = 0; i < n; i++){
        bool ok = false;
        for(map<string, int> :: iterator it = index_b[i].begin(); it != index_b[i].end(); it++){
            for(int j = 0; j < i; j++){
                if(index_b[j].find(it->first) != index_b[j].end()){
                    ok = true;
                    break;
                }
            }
            if(ok == true) break;
            for(int j = i+1; j < n; j++){
                if(index_b[j].find(it->first) != index_b[j].end()){
                    ok = true;
                    break;
                }
            }
            if(ok == true) break;
        }  
        if(ok == false){
            b++;
        }
    }
    cout << a << " " << b << endl;
    return 0;
}