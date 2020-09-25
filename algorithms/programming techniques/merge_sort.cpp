//Merge Sort - Time complexity: O(n log n)
#include <iostream>
#include <vector>
#define INF 1000000000

using namespace std;

//function merge_sort that sort the vector v
void merge_sort(vector<int> &v){
    // if the size of v is 1, return the function   
    if(v.size() == 1) return;

    //if not
    //create the vectors u1 and u2
    vector<int> u1, u2;
    //and make each one receive half a v
    for(int i = 0; i < v.size()/2; i++) u1.push_back(v[i]);
    for(int i = v.size()/2; i < v.size();i++) u2.push_back(v[i]);

    //sort the vectors u1 and u2

    merge_sort(u1);
    merge_sort(u2);


    //add infinity to the end of each vector
    u1.push_back(INF);
    u2.push_back(INF);

    //Declare begin1 and begin2 with value zero
    int begin1 = 0, begin2 = 0;
    //scroll through each position of the vector v
    for(int i = 0; i < v.size();i++){
        if(u1[begin1] < u2[begin2]){
            v[i] = u1[begin1];
            begin1++;
        }else{
            v[i] = u2[begin2];
            begin2++;
        }
    }

    return;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(0);

    vector<int> v;
    v.push_back(10);
    v.push_back(4);
    v.push_back(2);
    v.push_back(15);
    v.push_back(8);
    v.push_back(5);

    merge_sort(v);

    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}