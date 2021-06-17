#include <bits/stdc++.h>

int main(){
  // A Queue also provides two O(1) time operations: adding an element to the
  // end of the queue, and removing the first element in the queue.

  // It is only possible to access the first and last element of a queue
  std::queue<int> q;

  // push -> O(1)
  q.push(3);
  q.push(2);
  q.push(5);

  // back -> O(1)
  std::cout << "Back -> " << q.back() << std::endl; // 5

  // front -> O(1)
  std::cout << "Front -> " << q.front() << std::endl; // 3

  // pop -> O(1)
  q.pop();

  std::cout << "Front -> " << q.front() << std::endl; // 2


  return 0;
}

// g++ -Wall -std=c++17 algorithms/data-structures/queue.cpp -o main && ./main
