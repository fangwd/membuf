MemBuf is a small C++ buffer class that supports both C++'s stream insertion operator `<<` and the C's `printf` function.

# Usage
```cpp
    // Initialise a buffer
    MemBuf mb;

    // Add some data using stream insertions
    mb << "Hello";

    // Add more data using the printf method
    mb.printf("world, %d", 2018);

    // Data can also be appended
    mb.append(std::string("abc"));

    // Get the current data in the buffer
    std::cout << mb.content();
    
    // Stream extraction is also possible
    std::cout << mb;

    // Clear the buffer
    mb.clear();
```
# Other
There are a few other methods to control the internal buffer used by this class; see `include/MemBuf.hpp`.

