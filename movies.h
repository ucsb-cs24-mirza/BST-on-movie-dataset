// Movies.h
// Danming Wang
// 05/21/2019

#ifndef MOVIES_H
#define MOVIES_H

#include <iostream>
#include <string>
using namespace std;

class BST {

 public:
    BST();                   // constructor
    ~BST();                  // destructor
    bool insert(string movie);     // insert movie; return false if duplicate
    void printPreOrder() const; // prints tree data pre-order to cout
    int count() const;               // count of values
    string finds(string prefix) const;  // returns the movie name with the input prefix

    int getPredecessor(int value) const;       // returns the predecessor value of the given value or 0 if there is none
    int getSuccessor(int value) const;         // returns the successor value of the given value or 0 if there is none
    bool remove(int value);                    // deletes the Node containing the given value from the tree

 private:

    struct Node {
	string name;
    double rating;
	Node *left, *right, * parent;
	// useful constructor:
    Node(int v=0) : info(v), left(0), right(0), parent(0) { }
    };

    // just one instance variable (pointer to root node):
    Node *root;

    // recursive utility functions for use by public methods above
    Node* getNodeFor(string movie, Node* n) const; // IMPLEMENT THIS FIRST: returns the node for a given value or NULL if none exists
    void clear(Node *n); // for destructor
    bool insert(int value, Node *n); // note overloading names for simplicity
    void printPreOrder(Node *n) const;
};
