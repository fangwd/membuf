#include "MemBuf.hpp"

#include <string>
#include <cassert>
#include <iostream>

// g++ -Iinclude example/usage.cpp  -o demo

int main(int argc, char **argv) {
    MemBuf mb;

    // stream insertion
    mb << "Hello";

    assert(std::string(mb.content()) == "Hello");

    mb.append(' ');

    // append a string
    mb.append(std::string("world"));

    assert(std::string(mb.content()) == "Hello world");

    // printf
    mb.printf(" %d!", 2018);

    assert(std::string(mb.content()) == "Hello world 2018!");

    // clear the contents
    mb.clear();

    assert(mb.size() == 0);

    // reserve some space
    mb.reserve(100);

    // append data to the end of the internal buffer
    for (int i=0;i<3;i++ ) {
        mb.end()[i] = 'A' + i;
    }

    assert(mb.size() == 0);

    mb.appended(3);

    assert(std::string(mb.content()) == "ABC");

    assert(mb.size() == 3);

    std::cout << mb;

    return 0;
}
