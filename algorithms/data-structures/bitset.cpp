#include <bits/stdc++.h>

int main(){
  // A bitset is an array whose each value is either 0 or 1. For example, the following
  // code creates a bitset that contains 10 elements (0)
  // The benefit of using bitset is that they require less memory than ordinary arrays(1 bit of memory by element)
  // Can be efficiently manipulated using bit operators, which makes it possible
  // to optimize algorithms using bit sets

  std::bitset<10> s;
  s[1] = 1;
  s[3] = 1;
  s[4] = 1;
  s[7] = 1;
  std::cout << s[4] << "\n"; // 1
  std::cout << s[5] << "\n"; // 0

  std::bitset<10> bitst(std::string("0010011010")); // from right to left
  std::cout << bitst[4] << "\n"; // 1
  std::cout << bitst[5] << "\n"; // 0

  // Count how much number ones have in bitset
  std::cout << bitst.count() << "\n"; // 4

  std::bitset<10> a(std::string("0010110110"));
  std::bitset<10> b(std::string("1011011000"));
  std::cout << (a&b) << "\n"; // 0010010000 (AND OPERATION)
  std::cout << (a|b) << "\n"; // 1011111110 (OR OPERATION)
  std::cout << (a^b) << "\n"; // 1001101110 (XOR OPERATION)
  
  return 0;
}

// g++ -Wall -std=c++17 algorithms/data-structures/bitset.cpp -o main && ./main
