#include <iostream>
#include <cassert>
#include "vector.hpp"

int main(int argc, char const *argv[])
{
    auto i(0);
    Vector<int> vec;
    Vector<int> vec2(50);

    assert(vec.capacity() == 1);
    assert(vec2.capacity() == 50);

    assert(vec.length() == 0);
    assert(vec2.length() == 0);

    for(i=0; i < 10; i++){
        vec.push_back(i);
        vec2.push_back(i+1);
    }
    // std::cout << "Actual last item: " << vec.back() << std::endl;
    // std::cout << "Actual last item: " << vec.back() << std::endl;

    vec.printVector();

    assert(vec.back() == 9);
    assert(vec2.back() == 10);

    assert(vec.front() == 0);
    assert(vec2.front() == 1);

    assert(vec.length() == 10);
    assert(vec2.length() == 10);

    vec.pop_back();
    vec2.pop_back();

    vec.printVector();
    vec2.printVector();

    assert(vec.length() == 9);
    assert(vec2.length() == 9);

    vec.assign(4);
    vec2.assign(4);

    //USING FUNCTION "at()"
    for(i = 0; i < 9; i++){
        assert(vec.at(i) == 4);
        assert(vec.at(i) == 4);
    }

    //USING OPERATOR[]
    for(i = 0; i < 9; i++){
        assert(vec[i] == 4);
        assert(vec[i] == 4);
    }

    vec.printVector();
    vec2.printVector();

    vec.clear();
    vec2.clear();

    assert(vec.length() == 0);
    assert(vec2.length() == 0);

    vec.printVector();
    vec2.printVector();

    //TESTING WITH ITERATORS
    for(i=0; i < 10; i++){
        vec.push_back(i);
        vec2.push_back(i+1);
    }

    int *ptr = vec.data();
    for(i = 0; i < 10; i++)
        assert(*(ptr+i) == i);

    int *ptr2 = vec2.data();
    for(i = 0; i < 10; i++)
        assert(*(ptr2+i) == i+1);

    i = 0;
    for (auto it = vec.begin(); it != vec.end(); it++, i++)
        assert(*it == i);
    assert(i == 10);

    i = 0;
    for (auto it = vec2.begin(); it != vec2.end(); it++, i++)
        assert(*it == i+1);
    assert(i == 10);

    return EXIT_SUCCESS;
}