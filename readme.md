# csci-6356-hw4
Completes the tasks outlined in Homework 4 for Dr. Fu's CSCI 6356.
Written by Arnoldo Ramirez at UTRGV, 2019.

Each program creates n threads which each increment a shared variable count m times.
P1 uses mutex locks while P2 does not use mutex locks.

### How to compile
First have the CTPL_STL library installed; for it to work in my environment I had to download the "CTPL_STL.h" header from their GitHub and include that local header.

Preferably on Linux run:
`g++ -pthread p1.cpp -o p1.out`
or
`g++ -pthread p2.cpp -o p2.out`

### How to run
After compiling, you can run something in this format:
`./[program] [m] [n]`

like:
`./p1.out 1000 8`
or
`./p1.out 10000000 32`
or
`./p2.out 10000000 32`
