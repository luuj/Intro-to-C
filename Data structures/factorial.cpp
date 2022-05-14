#include <iostream>
#define TEST_ARRAY_SIZE 4

long int factorial(unsigned int num);

long int factorial(unsigned int num) {
    unsigned int temp = num;
    for(unsigned int i = 1; i < temp; i++) {
        num *=i;
    }
  return num;
}

int main() {
    int test[TEST_ARRAY_SIZE] = {1, 2, 5, 7};
    for (unsigned int i = 0; i < TEST_ARRAY_SIZE; i++) {
        std::cout << "Factorial of " << test[i] << " is " << factorial(test[i]) << std::endl;
    }
}


