#include <bits/stdc++.h>

int main(){
  // Deque is a dynamic array whose size can be efficiently at both ends of
  // the array. Like a vector, a deque provides the functions push_back and pop_back,
  // but it also includes the functions push_front and pop_front which are not
  // available in a vector

  // Unlike vectors, deques are not guaranteed to store all its elements in
  // contigous storage locations
  std::deque<int> d;

  // push_back -> O(1)
  d.push_back(5);
  d.push_back(2);
  d.push_back(8);

  // push_front -> O(1)
  d.push_front(3);

  // operator [] -> O(1)
  std::cout << d[0] << std::endl; // 3
  std::cout << "----" << std::endl; 

  // pop_back -> O(1)
  d.pop_back();

  // pop_front-> O(1)
  d.pop_front();

  //auto& -> change the original value
  for(auto& v: d){
    v++;
    std::cout << v << std::endl; 
  }

  std::cout << "----" << std::endl; 
  //auto -> changes the copy of the value
  for(auto v: d){
    std::cout << v << std::endl; 
  }
  return 0;
}

// g++ -Wall -std=c++17 algorithms/data-structures/deque.cpp -o main && ./main
