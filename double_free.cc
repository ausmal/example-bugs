/**
 * FILE: uninitialized_heap.cc
 * AUTHOR: Austin Maliszewski
 * DATE: 23 July 2015
 * 
 * This file demonstrates a "double free"
 *
 * When run normally this code will not cause any memory protection
 * errors or any glibc messages about double free. Valgrind, however,
 * will detect this.
 *
 **/

#include <iostream>

int main() {
  int * thing_one = new int;
  int * thing_two = thing_one;


  std::cout << "Thing one: " << thing_one << std::endl;
  std::cout << "Thing two: " << thing_two << std::endl;

  
  delete thing_one;

  std::cout << "Deleted thing one" << std::endl;

  thing_one = new int;
  std::cout << "Created new thing one: " << thing_one << std::endl;
  delete thing_two;

  std::cout << "Thing one: " << thing_one << std::endl;
  std::cout << "Thing two: " << thing_two << std::endl;

  return 0;
}
