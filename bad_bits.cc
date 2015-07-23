/**
 * FILE: memory_leak_1.cc
 * AUTHOR: Austin Maliszewski
 * DATE: 23 July 2015
 * 
 *
 **/

#include <iostream>


int main() {
  unsigned int uninitialized;
  
  unsigned int zero = 0;
  unsigned int word = 0xDEADBEEF;

  unsigned int some_good_1 = uninitialized | word;
  unsigned int some_good_2 = uninitialized & word;
  unsigned int all_zero = uninitialized & zero;

  std::cout << "some_good_1: " << some_good_1 << std::endl;
  std::cout << "some_good_2: " << some_good_2 << std::endl;
  std::cout << "all_zero: " << all_zero << std::endl;
  return 0;
}
