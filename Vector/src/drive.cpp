#include <iostream>
#include <cassert>
#include "vector.hpp"

int main(int argc, char const *argv[])
{
    // int i;
    Vector<int> vec;
    Vector<int> vec2(50);

    if(vec.empty())
        std::cout << "EMPTY VECTOR!" << std::endl;
    else
        std::cout << "NON-EMPTY LENGTH IS: " << vec.length() << std::endl;
        
    vec.push_back(4);
    vec.push_back(3);
    
    if(vec.empty())
        std::cout << "EMPTY VECTOR!" << std::endl;
    else
        std::cout << "NON-EMPTY LENGTH IS: " << vec.length() << std::endl;
    
    std::cout << "Last item: " << vec.back() << std::endl;
    vec.pop_back();
    std::cout << "Last item: " << vec.back() << std::endl;
    
    std::cout << "First item: " << vec.front() << std::endl;
    
    vec.push_back(5);
    vec.push_back(6);
    vec.push_back(34);
    vec.push_back(2);
    vec.push_back(8);
    vec.push_back(9);
    
    vec.printVector();
    
    vec.assign(4);
    
    vec.printVector();
    
    std::cout << "VECTOR CAPACITY IS: " << vec.length() << std::endl;
    
    return EXIT_SUCCESS;
}