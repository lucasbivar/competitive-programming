#include <bits/stdc++.h>

int main(){
  // Stack is a data structure that provides two O(1) time operations:
  // adding an element to the top, and removing an element from the top.

  //It is only possible to access the top element of a stack

  std::stack<int> s;

  // push -> O(1)
  s.push(3);
  s.push(2);
  s.push(5);

  // top -> O(1)
  std::cout << s.top() << std::endl; // 5

  // pop -> O(1)
  s.pop();

  std::cout << s.top() << std::endl; // 2

  return 0;
}