#include <bits/stdc++.h>


int main(){
  // A priority queue maintains a set of elements. The supported operations
  // are insertion and, depending on the type of the queue, retrieval and removal of
  // either the minimum or maximum element. Insertion and removal take O(log n) time,
  // and retrieval takes O(1) time

  //  While an ordered set efficiently supports all the operations of a priority queue,
  // the benefit of using a priority queue is that it has smaller constant factors. A
  // priority queue is usually implemented using a heap structure that is much
  // simpler than a balanced binary tree used in an ordered set.

  //By default, the elements in a C++ priority queue are sorted in decreasing
  // order, and it is possible to find and remove the largest element in the queue
  std::priority_queue<int> q;

  // push -> O(log n)
  q.push(3);
  q.push(5);
  q.push(7);
  q.push(2);

  // top -> O(1)
  std::cout << q.top() << "\n"; // 7

  // pop -> O(log n)
  q.pop();

  std::cout << q.top() << "\n"; // 5

  q.pop();

  q.push(6);

  std::cout << q.top() << "\n"; // 6

  q.pop();

  // changing the priority queue to be sorted in increasing
  std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
  
  return 0;
}


// g++ -Wall -std=c++17 algorithms/data-structures/priority_queue.cpp -o main && ./main
