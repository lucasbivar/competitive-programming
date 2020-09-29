#include <iostream>
#include <algorithm>


using namespace std;
int a[100005];
int n;

int max_sum(){
    int sum = 0; 
    for (int i = 0; i < n; i++) { 
        sum += a[i]; 
    } 
    // Initialize every variable with first value of array. 
    int local_max = a[0], global_max = a[0], local_min = a[0], global_min = a[0]; 
  
    // Concept of Kadane's Algorithm 
    for (int i = 1; i < n; i++) { 
        // Kadane's Algorithm to find Maximum subarray sum. 
        local_max = max(local_max + a[i], a[i]); 
        global_max = max(global_max, local_max); 
  
        // Kadane's Algorithm to find Minimum subarray sum. 
        local_min = min(local_min + a[i], a[i]); 
        global_min = min(global_min, local_min); 
    } 
  
    if (global_min == sum) 
        return global_max; 
  
    // returning the maximum value 
    return max(global_max, sum - global_min);
}

int main(){
    cin.tie(NULL);
    cin.tie(NULL);
    ios::sync_with_stdio(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int qtd = max_sum();
    if(qtd >= 0){
        cout << qtd << endl;
    }else{
        cout << 0 << endl;
    }

    
    return 0;
}