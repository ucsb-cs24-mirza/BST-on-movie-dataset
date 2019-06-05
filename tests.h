// test.h
// Danming Wang
// 05/04/2019

#ifndef TESTS_H
#define TESTS_H
#include <iostream>

using namespace std;

void runAll();
void test_constructor();
void test_destructor();
void test_printPreOrder();
void test_visitedNode();
void test_count();
void test_MaxNode();

void START_TEST(string testname){
    cout << "Start "<<testname<<endl;
}

void END_TEST(string testname){
    cout << "End "<<testname<<endl;
    cout<<endl;
}

#endif
