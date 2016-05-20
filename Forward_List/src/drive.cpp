#include <iostream>
#include <cassert>
#include "forward_list.hpp"

int main(int argc, char const *argv[]){
    /* Control variables*/
    int i;
    Forward_list<int> fl1;
    Forward_list<int> fl2(fl1);
    Forward_list<int> fl3(std::move(fl1));
    Forward_list<int>::iterator it;
    Forward_list<int>::const_iterator cit;

    // Testing function "size"
    assert(fl1.size() == 0
            && fl2.size() == 0
            && fl3.size() == 0);

    // Testing with empty lists: "empty"
    assert(fl1.empty() == true
            && fl2.empty() == true
            && fl3.empty() == true);

    // Testing "push_front" consequences
    fl1.push_front(3);
    fl2.push_front(3);
    fl3.push_front(3);
    assert(fl1.size() == 1
            && fl2.size() == 1
            && fl3.size() == 1);
    assert(fl1.empty() == false
            && fl2.empty() == false
            && fl3.empty() == false);
    assert(fl1.front() == 3
            && fl2.front() == 3
            && fl3.front() == 3);
    assert(fl1.back() == 3
            && fl2.back() == 3
            && fl3.back() == 3);

    // Testing push_back()
    fl1.push_back(10);
    fl2.push_back(10);
    fl3.push_back(10);
    assert(fl1.size() == 2
            && fl2.size() == 2
            && fl3.size() == 2 );       // size() to fl1
    assert(fl1.empty() == false
            && fl2.empty() == false
            && fl3.empty() == false );  // empty() to fl1
    assert(fl1.front() == 3
            && fl2.front() == 3
            && fl3.front() == 3 );      // front() to fl1
    assert(fl1.back() == 10
            && fl2.back() == 10
            && fl3.back() == 10);      // back() to fl1

    fl1.pop_front();
    fl2.pop_front();
    fl3.pop_front();
    assert(fl1.size() == 1
            && fl2.size() == 1
            && fl3.size() == 1);
    assert(fl1.empty() == false
            && fl2.empty() == false
            && fl3.empty() == false);
    assert(fl1.front() == 10
            && fl2.front() == 10
            && fl3.front() == 10);
    assert(fl1.back() == 10
            && fl2.back() == 10
            && fl3.back() == 10);

    fl1.push_front(3);
    fl2.push_front(3);
    fl3.push_front(3);

    fl1.pop_back();
    fl2.pop_back();
    fl3.pop_back();
    assert(fl1.size() == 1
            && fl2.size() == 1
            && fl3.size() == 1);       // size() to fl1
    assert(fl1.empty() == false
            && fl2.empty() == false
            && fl3.empty() == false);  // empty() to fl1
    assert(fl1.front() == 3
            && fl2.front() == 3
            && fl3.front() == 3);      // front() to fl1
    assert(fl1.back() == 3
            && fl2.back() == 3
            && fl3.back() == 3);       // back() to fl1

    fl1.clear();
    fl2.clear();
    fl3.clear();
    assert(fl1.size() == 0
            && fl2.size() == 0
            && fl3.size() == 0);      // size() to fl1
    assert(fl1.empty() == true
            && fl2.empty() == true
            && fl3.empty() == true);  // empty() to fl1

    for (i = 0; i < 10; i++) {
        fl1.push_back(i);
        fl2.push_back(i);
        fl3.push_back(i);
        assert(fl1.back() == i && fl2.back() == i && fl3.back() == i);
    }

    fl1.assign(100);
    fl2.assign(100);
    fl3.assign(100);
    for (i = 0; i < 10; i++) {
        assert(fl1.front() == 100
                && fl2.front() == 100
                && fl3.front() == 100);
        fl1.pop_front();
        fl2.pop_front();
        fl3.pop_front();
    }

    assert(fl1.size() == 0 && fl2.size() == 0 && fl3.size() == 0);
    assert(fl1.empty() == true
            && fl2.empty() == true
            && fl3.empty() == true);

    fl1.assign({1, 2, 3, 4});
    fl2.assign({1, 2, 3, 4});
    fl3.assign({1, 2, 3, 4});
    for (i = 1; i < 5; i++) {
        assert(fl1.front() == i
                && fl2.front() == i
                && fl3.front() == i);
        fl1.pop_front();
        fl2.pop_front();
        fl3.pop_front();
    }

    assert(fl1.size() == 0
            && fl2.size() == 0
            && fl3.size() == 0);
    assert(fl1.empty() == true
            && fl2.empty() == true
            && fl3.empty() == true);
    // Clear List content
    fl1.clear();
    fl2.clear();

    for (i = 0; i < 10; i++) {
        fl1.push_back(i);
        fl2.push_back(i);
        fl3.push_back(i);
    }

    fl1.clear();
    fl2.clear();

    for (i = 0; i < 10; i++) {
        fl1.push_back(i);
        fl2.push_back(i);
        fl3.push_back(i);
    }

    std::cout << ">>> Exiting with success...\n";

    return EXIT_SUCCESS;

}