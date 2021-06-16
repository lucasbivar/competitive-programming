#include <bits/stdc++.h>


int main(){
  // Set is a data structure that maintains a collection of unique elements.
  // There is also multiset and unordered_multiset where multiple elements can have equivalent values
  // The basic operations of sets are element insertion, search and removal.

  // The C++ standard library contains two set implementations:
  //  -> set (ordered) - Based on balanced binary tree => the operations work in O(log n) time;
  //  -> unordered_set - Using hashing => the operations work in O(1) time on average;

  // The benefit of the set structure is that it maintains the order of the elements
  // and provides functions that are not avaible in unordered_set

  // Atention: it's not possible to access the elements using the [] notation

  std::set<int> s;
  std::set<int>::iterator it;

  // insert -> O(log n)
  s.insert(3);
  s.insert(2);
  s.insert(5);
  s.insert(6);
  s.insert(7);
  s.insert(8);

  std::cout << "ELEMENTS:" << std::endl;
  for(auto& element: s){
    std::cout << element << std::endl;
  }

  std::cout << "----------------" << std::endl;
  std::cout << "COUNTING:" << std::endl;

  // count -> O(log n)
  std::cout << s.count(3) << std::endl; // 1
  std::cout << s.count(4) << std::endl; // 0

  std::cout << "----------------" << std::endl;


  // find -> O(log n)
  // if not found, return an iterator to end()
  it = s.find(5);


  // ERASE:
  //  - erase(value) -> O(log n)
  s.erase(3);
  //  - erase(iterator) -> amortized O(1)
  if(it != s.end()){
    s.erase(it);
  }
  //  - erase(it_first, it_last) -> O(n)


  std::cout << "ELEMENTS:" << std::endl;
  for(auto &element: s){
    std::cout << element << std::endl;
  }
  std::cout << "----------------" << std::endl;
  std::cout << "SIZE:" << std::endl;

  // size -> O(1)
  std::cout << s.size() << std::endl;
  std::cout << "----------------" << std::endl;
  


  // WORKING WITH MULTISET - multiple elements can have equivalent values
  std::multiset<int> ms;
  // insert -> O(log n) in general
  ms.insert(2);
  ms.insert(2);
  ms.insert(5);
  ms.insert(5);
  ms.insert(5);

  // count -> O(log n) in size and O(n) in the number of matches
  std::cout << "COUNT: " << std::endl; 
  std::cout << ms.count(5) << std::endl; //3

  // erase (removes all instances) ->  O(log (size + count))
  ms.erase(5);
  std::cout << ms.count(5) << std::endl; // 0

  // Often, only one instance should be removed, which can be done as follows:
  ms.erase(ms.find(2));
  std::cout << ms.count(2) << std::endl; // 1
  return 0;
}


// g++ -Wall -std=c++17 algorithms/data-structures/set.cpp -o main && ./main
