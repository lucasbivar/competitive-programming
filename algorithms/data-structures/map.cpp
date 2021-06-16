#include <bits/stdc++.h>

int main(){
  // Map is a generalized array that consists of key-value-pairs

  // While the keys in an ordinary array are always the consecutive integers 0, 1,..., n-1
  // where n is the size of the array, the keys in a map can be of any data type and they
  // do not have to be consecutive values

  // The C++ STL contains two map implementations:
  //  -> map (ordered) - Based on balanced binary tree => accessing elements takes O(log n) time;
  //  -> unordered_map - Using hashing => accessing elements takes O(1) time on average;

  // There is also multimap and unordered_multimap where multiple elements can have equivalent keys

  std::map<std::string, int> m;
  std::map<std::string, int>::iterator it;

  m["monkey"] = 4;
  m["banana"] = 3;
  m["harpsichord"] = 9;
  // insert -> O(log n)
  m.insert({"apple", 5});

  // Access -> O(log n)
  std::cout << m["banana"] << std::endl; //3

  //*PAY ATTENTION* -> if the value of a key is requested, but map does not contain it
  // the key is automatically added to the map with a default value 0
  // it's a good practice check if the element exist, before try to access some key value
  // to make this, we can use the find or count method 
  // count -> O(log n)
  if(m.count("orange")){
    std::cout << m["orange"] << std::endl;
  }

  std::cout << "----------------" << std::endl;
  for(auto elem: m){
    std::cout << elem.first << " " << elem.second << std::endl;
  }

  // ERASE:
  //  - erase(value) -> O(log n)
  m.erase("harpsichord");
  //  - erase(iterator) -> amortized O(1)
  it = m.find("banana");
  if(it != m.end()){
    m.erase(it);
  }
  //  - erase(it_first, it_last) -> O(n)

  std::cout << "----------------" << std::endl;
  for(auto elem: m){
    std::cout << elem.first << " " << elem.second << std::endl;
  }
  return 0;
}

// g++ -Wall -std=c++17 algorithms/data-structures/map.cpp -o main && ./main
