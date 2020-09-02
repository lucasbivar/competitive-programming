//Two-pointers O(n)

#include <iostream>

using namespace std;

bool isPairSum(int A[], int N, int X){ 
    // represents first pointer 
    int i = 0; 
  
    // represents second pointer 
    int j = N - 1; 
  
    while (i < j) { 
  
        // If we find a pair 
        if (A[i] + A[j] == X){
            return true; 
        }
  
        // If sum of elements at current 
        // pointers is less, we move towards 
        // higher values by doing i++ 
        else if (A[i] + A[j] < X){
            i++; 
        }
  
        // If sum of elements at current 
        // pointers is more, we move towards 
        // lower values by doing j-- 
        else
            j--; 
    } 
    return false; 
} 

int main(){
    int ord_array[6] = {1, 4, 6, 12, 13, 14};
    int N = 6;
    cout << isPairSum(ord_array, N, 19) << endl;
    return 0;
}