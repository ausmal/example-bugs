/**
 * FILE: uninitialized_heap.cc
 * AUTHOR: Austin Maliszewski
 * DATE: 11 July 2015
 * 
 * This file demonstrates a common bug -- use of an uninitalized
 * value. The myClass::aBool_ member is only initalized if anInt > 100. 
 * 
 * The specific demonstration here shows the values left over from a
 * stack allocated C++ string leaking into a dynamically allocated
 * instance of this class. (std::string automatically allocates heap
 * memory for the contents of the string.)
 *
 **/

#include <iostream>
#include <cstring>
#include <cstdio>
#include <stdint.h>

#ifdef PRINT_MEM
void print_mem(void * mem, size_t size) {
  unsigned char * mbuf = reinterpret_cast<unsigned char *>(mem);
  unsigned char * ebuf = mbuf + size;
  while (mbuf < ebuf) {
    printf("0x%016llx : 0x%02x\n",  
           reinterpret_cast<unsigned long long>(mbuf), 
           static_cast<unsigned int>(*(mbuf++))
           );
  }
  printf("\n");
}
#else
void print_mem(void * mem, size_t size) {}
#endif

class myClass {
  double aDouble_;
  int anInt_;
  int anArray[8];
  bool aBool_;

public:
  myClass(int anInt, double aDouble) : anInt_(anInt), aDouble_(aDouble) {
    if (anInt > 100) {
      aBool_ = true;
    } 
  }
  void saySomething() {
    std::cout << "I'm saying: ";
    if(aBool_) {
      std::cout << "Hello world!" << std::endl;
    } else {
      std::cout << (anInt_ + aDouble_) << std::endl;
    }
  }
};

int main(int argc, char **argv) {
  if (argc > 1) {
    std::string a_string("I am a stack C++ string");
    std::cout << a_string << std::endl;
    print_mem((char *)a_string.data() - 0x18, 48);
  }
  
  myClass * myClassPtr = new myClass(10, 3.14);
  print_mem(myClassPtr, sizeof(myClass));
  myClassPtr->saySomething();
}

