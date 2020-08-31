#include <iostream>
#include <map>

using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(0);
    map<int, pair<int, char>> pieces;
    int N, start, end;
    char letter;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> start >> letter >> end;
        pieces.insert(make_pair(start, make_pair(end, letter)));
    }
    int first = 0;
    while (true){
        if(pieces.find(first) == pieces.end()){
            break;
        }
        cout << pieces[first].second;
        first = pieces[first].first;
    }
    cout << endl;
    
  
    return 0;
}