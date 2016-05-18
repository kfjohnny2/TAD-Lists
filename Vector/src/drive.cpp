#include <iostream>
#include <cassert>
#include "vector.hpp"

int main(int argc, char const *argv[])
{
    // int i;
    Vector<int> vec;
    Vector<int> vec2(50);

    std::cout << vec.capacity() << std::endl;
    return EXIT_SUCCESS;
}