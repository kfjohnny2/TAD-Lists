#include <iostream>
#include <cassert>
#include "list.hpp"

int main(int argc, char const *argv[]){
    /* Control variables*/
    int i;
    List<int> dlist;
    List<int> dlist2(dlist);
    List<int> dlist3(std::move(dlist));
    List<int>::iterator it;
    List<int>::const_iterator cit;

    // Testing function "size"
    assert(dlist.size() == 0
            && dlist2.size() == 0
            && dlist3.size() == 0);

    // Testing with empty lists: "empty"
    assert(dlist.empty() == true
            && dlist2.empty() == true
            && dlist3.empty() == true);

    // Testing "push_front" consequences
    dlist.push_front(3);
    dlist2.push_front(3);
    dlist3.push_front(3);
    assert(dlist.size() == 1
            && dlist2.size() == 1
            && dlist3.size() == 1);
    assert(dlist.empty() == false
            && dlist2.empty() == false
            && dlist3.empty() == false);
    assert(dlist.front() == 3
            && dlist2.front() == 3
            && dlist3.front() == 3);
    assert(dlist.back() == 3
            && dlist2.back() == 3
            && dlist3.back() == 3);

    // Testing push_back()
    dlist.push_back(10);
    dlist2.push_back(10);
    dlist3.push_back(10);
    assert(dlist.size() == 2
            && dlist2.size() == 2
            && dlist3.size() == 2 );       // size() to dlist
    assert(dlist.empty() == false
            && dlist2.empty() == false
            && dlist3.empty() == false );  // empty() to dlist
    assert(dlist.front() == 3
            && dlist2.front() == 3
            && dlist3.front() == 3);      // front() to dlist
    assert(dlist.back() == 10
            && dlist2.back() == 10
            && dlist3.back() == 10);      // back() to dlist

    // Unity test #5: pop_front() consequences
    dlist.pop_front();
    dlist2.pop_front();
    dlist3.pop_front();
    assert(dlist.size() == 1
            && dlist2.size() == 1
            && dlist3.size() == 1);
    assert(dlist.empty() == false
            && dlist2.empty() == false
            && dlist3.empty() == false);
    assert(dlist.front() == 10
            && dlist2.front() == 10
            && dlist3.front() == 10);
    assert(dlist.back() == 10
            && dlist2.back() == 10
            && dlist3.back() == 10);

    dlist.push_front(3);
    dlist2.push_front(3);
    dlist3.push_front(3);

    // Unity test #6: pop_back() consequences
    dlist.pop_back();
    dlist2.pop_back();
    dlist3.pop_back();
    assert(dlist.size() == 1
            && dlist2.size() == 1
            && dlist3.size() == 1);       // size() to dlist
    assert(dlist.empty() == false
            && dlist2.empty() == false
            && dlist3.empty() == false);  // empty() to dlist
    assert(dlist.front() == 3
            && dlist2.front() == 3
            && dlist3.front() == 3);      // front() to dlist
    assert(dlist.back() == 3
            && dlist2.back() == 3
            && dlist3.back() == 3);       // back() to dlist

    // Unity test #7: clear() consequences
    dlist.clear();
    dlist2.clear();
    dlist3.clear();
    assert(dlist.size() == 0
            && dlist2.size() == 0
            && dlist3.size() == 0);      // size() to dlist
    assert(dlist.empty() == true
            && dlist2.empty() == true
            && dlist3.empty() == true);  // empty() to dlist

    // Unity test #8: push_back() and back()
    for (i = 0; i < 10; i++) {
        dlist.push_back(i);
        dlist2.push_back(i);
        dlist3.push_back(i);
        assert(dlist.back() == i && dlist2.back() == i && dlist3.back() == i);
    }

    // Unity test #9: assign(), front() and pop_front();
    dlist.assign(100);
    dlist2.assign(100);
    dlist3.assign(100);
    for (i = 0; i < 10; i++) {
        assert(dlist.front() == 100
                && dlist2.front() == 100
                && dlist3.front() == 100);
        dlist.pop_front();
        dlist2.pop_front();
        dlist3.pop_front();
    }

    // Unity test #10: size() and empty() (after pop_front)
    assert(dlist.size() == 0 && dlist2.size() == 0 && dlist3.size() == 0);
    assert(dlist.empty() == true
            && dlist2.empty() == true
            && dlist3.empty() == true);

    // Unity test #11: assign() with initializer list
    dlist.assign({1, 2, 3, 4});
    dlist2.assign({1, 2, 3, 4});
    dlist3.assign({1, 2, 3, 4});
    for (i = 1; i < 5; i++) {
        assert(dlist.front() == i
                && dlist2.front() == i
                && dlist3.front() == i);
        dlist.pop_front();
        dlist2.pop_front();
        dlist3.pop_front();
    }

    assert(dlist.size() == 0
            && dlist2.size() == 0
            && dlist3.size() == 0);
    assert(dlist.empty() == true
            && dlist2.empty() == true
            && dlist3.empty() == true);
    dlist.clear();
    dlist2.clear();

    for (i = 0; i < 10; i++) {
        dlist.push_back(i);
        dlist2.push_back(i);
        dlist3.push_back(i);
    }

    dlist.clear();
    dlist2.clear();

    for (i = 0; i < 10; i++) {
        dlist.push_back(i);
        dlist2.push_back(i);
        dlist3.push_back(i);
    }

    std::cout << ">>> Exiting with success...\n";

    return EXIT_SUCCESS;

}