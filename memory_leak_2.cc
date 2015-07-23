/**
 * FILE: memory_leak_2.cc
 * AUTHOR: Austin Maliszewski
 * DATE: 23 July 2015
 * 
 * This file demonstrates a memory leak.
 *
 * This time, Valgrind reports the blocks as directly lost because
 * they no longer form a list.
 *
 * [ root ] -> null
 *    S
 *
 * [ node0 ] -> null 
 *     D            
 * 
 * [ node1 ] -> null 
 *     D            
 *
 * [ node2 ] -> null 
 *     D  
 * 
 * ... 
 * 
 * [ node9 ] -> null 
 *     D  
 *          
 *
 * S = still reachable
 * D = directly lost
 * I = indirectly lost
 *
 **/

#include <iostream>

template <typename T>
struct node {
  node * next;
  T value;

  node() {
    next = nullptr;
  }
  
  void insert(T value) {
    next = new node;
    next->value = value;
  }

  void remove_next() {
    auto tmp = next->next;
    next->next = nullptr;
    next = tmp;
  }
};

int main() {
  node<int> root;
  root.value = 0;

  node<int> * ptr = &root;
  for (int i = 0; i < 10; i++) {
    ptr->insert(i);
    ptr = ptr->next;
  }

  ptr = &root;
  while (ptr->next) {
    ptr->remove_next();
  }
  return 0;
}
