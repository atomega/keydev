// cpp_training.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <cmath>
#include "baremetal/i2c/bm_i2c.h"

using namespace std;

void testingValRefPtr(); 

int main()
{
    std::cout << "\n\n\n Reched end of Main" << endl;
    return 0; 
}

void testingValRefPtr()
{
    std::cout << "##################################################" << endl;
    std::cout << "|| Var\t\t|| Value\t|| Address\t||" << endl;
    std::cout << "##################################################" << endl;
                                                                    
    int foo = 30;
    std::cout << "|| foo\t\t|| " << foo << "\t\t|| " << &foo << "\t||" << endl;
    
    int& ref = foo;
    std::cout << "|| &Ref = foo\t|| " << ref << "\t\t|| " << &ref << "\t||" << endl;
    
    int* ptr = 0;
    std::cout << "|| ptr = 0\t|| " << ptr << "\t|| " << &ptr << "\t||" << endl;
    
    ptr = &foo;
    std::cout << "|| ptr = &foo\t|| " << *ptr << "\t\t|| " << &ptr << "\t||" << endl;
    
    std::cout << "##################################################" << endl;

    delete ptr; 
    ptr = 0; 
}
