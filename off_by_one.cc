/**
 * FILE: off_by_one.cc
 * AUTHOR: Austin Maliszewski
 * DATE: 23 July 2015
 * 
 * This file demonstrates a "off_by_one"
 *
 * When run normally this code will not cause any memory protection
 * errors or any glibc messages about double free. Valgrind, however,
 * will detect this.
 *
 **/

#include <iostream>
#include <vector>

int main() {
  std::vector<int> v;
  v.resize(10);

  for (int i = 0; i <= 10; i++) {
    v[i] = i * 2;
  }
  
  for (int i = 0; i <= 10; i++) {
    std::cout << "v[i]=" << v[i] << std::endl;
  }

  return 0;
}
