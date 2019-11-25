//        Author:     Arnoldo Ramirez
//        SID:        20254876
//        Course:     CSCI 6356
//        HW:         Homework 4 P1
//
//        Task:       Takes m, n as parameters and creates n threads which
//                    each increment a shared variable count m times.
//                    This program, P1, uses mutex locks.
//
//   TO BUILD:        g++ -pthread p1.cpp -o p1.out
//
//   INTENDED USAGE:  ./p1.out 1000 8
//               or:  ./p1.out 10000000 32
//
//   Github:          https://github.com/arami265/csci-6356-hw4

#include <thread>
#include <stdio.h>
#include <stdlib.h>
#include <mutex>
#include <string>
#include "ctpl_stl.h"
#include <iostream>
#include <chrono>

int count = 0;
std::mutex count_mutex;

void increment_count(int id, int m)
{
  count_mutex.lock();
  for(int i = 0; i < m; i++)
    count++;
  count_mutex.unlock();
}

int main (int argc, char *argv[])
{
  auto t1 = std::chrono::high_resolution_clock::now();
  int m, n;
  std::chrono::milliseconds span (1);

  //The last argv provided by user is stored as m.
  std::string argument1 = argv[1];
  m = std::stoi(argument1);
  std::string argument2 = argv[2];
  n = std::stoi(argument2);

  ctpl::thread_pool pool(n);
  std::future<bool>* f = new std::future<bool>[n];

  for(int i = 0; i < n; i++)
    f[i] = pool.push(increment_count, m);

  for(int i = 0; i < n; i++)
    while (f[i].wait_for(span)==std::future_status::timeout);

  auto t2 = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();

  printf("Final count = %d\n", count);
  std::cout << "Computed in " << duration << " microseconds.\n\n";
}
