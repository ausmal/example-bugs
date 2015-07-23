/**
 * FILE: off_by_one_stack.cc
 * AUTHOR: Austin Maliszewski
 * DATE: 23 July 2015
 * 
 * This file demonstrates a "off_by_one" on a stack array. 
 *
 * This error cannot be detected by valgrind. The written-to location
 * is valid.
 *
 **/

#include <iostream>
#include <vector>

int main() {
  int v[10];

  for (int i = 0; i <= 10; i++) {
    v[i] = i * 2;
  }
  
  for (int i = 0; i <= 10; i++) {
    std::cout << "v[i]=" << v[i] << std::endl;
  }

  return 0;
}
