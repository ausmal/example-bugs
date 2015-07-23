/**
 * FILE: memory_leak_1.cc
 * AUTHOR: Austin Maliszewski
 * DATE: 23 July 2015
 * 
 * This file demonstrates a memory leak.
 *
 * Valgrind reports the blocks as indirectly lost because they still
 * form a chain, but there is no pointer to the parent. i.e.
 *
 * [ root ] -> null
 *    S
 *
 * [ node0 ] -> [ node1 ] -> [ node2 ] -> ... [ node9 ] -> null
 *     D            I            I                I
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
    next = next->next;
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
