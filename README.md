# bdb
bdb (Big Dynamic Branches) is a header-only library that implements the
ternary operator on steroids.  It started as a joke during a conversation with
a friend (available in the bottom of this readme) and is unlikely to be
maintained.

## Building
Because the library contains only a single header it can be installed by
copying `bdb.h` to an appropriate location (i.e., an include directory).
[CMake][1] is available if you want to build the tests or do the install
through a build tool.

1. `mkdir <build_dir>`
2. `cd <build_dir>`
3. `cmake /path/to/bdb/src`
4. `make`
5. (Optional, requires [gtest][2]) `make test`
6. `make install`

Because bdb uses C++14 you'll need a C++14 compliant compiler to use it,
including building the tests.  If you're using a toolchain CMake doesn't have
built-in support for you'll need to add the appropriate flags at configuration
time (something like
`cmake -DCMAKE_CXX_FLAGS="-std=c++14" /path/to/bureaucracy/src`).

## Conversation
Friend: i actually have a better idea anyway 10:33:21 AM MDT  
Friend: foo ?? bar : less_than() : equal() : greater_than(); 10:33:46 AM MDT  
Friend: quaternary operator! 10:33:56 AM MDT  
Me: that's stupid 10:34:33 AM MDT  
Me: you'll need at least four disk pointers 10:34:39 AM MDT (inside joke)  
Friend: i actually like it 10:34:54 AM MDT  
Friend: i like the ? operator sometimes for simple things 10:35:03 AM MDT  
Friend: you could combine the two 10:35:06 AM MDT  
Friend: i like the idea of getting a trinary comparison result 10:35:11 AM MDT  
Me: write the helper function 10:39:47 AM MDT  
Me: take three functions, call the appropriate one 10:40:06 AM MDT  
Friend: we should do it c++-style though 10:40:16 AM MDT  
Friend: have an n-way comparison function 10:40:21 AM MDT  
Friend: all templated 10:40:24 AM MDT  
Friend: with a storable result 10:40:28 AM MDT  
Friend: call it BDB - big dynamic branches 10:40:42 AM MDT  

[1]: https://cmake.org/ "CMake"
[2]: https://github.com/google/googletest "gtest"
