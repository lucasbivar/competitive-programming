//Inversion Count - Time Complexity: O(n log n)
#include <iostream>
#include <vector>
#define INF 1000000000

using namespace std;

int merge_sort(vector<int> &v){
    int inv = 0;

    if(v.size() == 1) return 0;

    vector<int> u1, u2;
    for(int i = 0; i < (int)v.size()/2; i++){
        u1.push_back(v[i]);
    }
    for(int i = v.size()/2; i < (int) v.size(); i++){
        u2.push_back(v[i]);
    }

    inv += merge_sort(u1);
    inv += merge_sort(u2);

    u1.push_back(INF);
    u2.push_back(INF);
    int begin1 = 0, begin2 = 0;
    for(int i = 0; i < (int) v.size(); i++){
        if(u1[begin1] <= u2[begin2]){
            v[i] = u1[begin1];
            begin1++;
        }else{
            v[i] = u2[begin2];
            begin2++;
            inv += u1.size() - begin1 -1;
        }
    }

    return inv;
}

int main(){
    cin.tie(NULL);
    cin.tie(NULL);
    ios::sync_with_stdio(0);

    vector<int> vec;
    vec.push_back(5);
    vec.push_back(2);
    vec.push_back(1);
    vec.push_back(7);
    vec.push_back(5);

    cout << merge_sort(vec) << endl;
    
    return 0;
}
