// Movies.h
// Danming Wang
// 05/21/2019

#ifndef MOVIES_H
#define MOVIES_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Node {
    public:
	    string name;
        double rating;
	    Node *left, *right, * parent;
	// useful constructor:
        Node(string n="default", double r=0.0) : name(n), rating(r), left(0), right(0), parent(0) { }
};


class BST {

 public:
    BST();                   // constructor
    ~BST();                  // destructor
    vector<Node*> getNodesFor(string prefix);
    friend Node* MaxNode(vector<Node*> v);

    bool insert(string n, double r);     // insert movie; return false if duplicate
    void printPreOrder() const; // prints tree data pre-order to cout
    int count() const;               // count of values

    int getPredecessor(int value) const;       // returns the predecessor value of the given value or 0 if there is none
    int getSuccessor(int value) const;         // returns the successor value of the given value or 0 if there is none
    bool remove(int value);                    // deletes the Node containing the given value from the tree
    friend void play(BST& movies, string prefix);
 private:

        // just one instance variable (pointer to root node):
    Node *root;
    void clear(Node *n);
    vector<Node*> getNodesFor(string prefix, Node* n) const; // IMPLEMENT THIS FIRST: returns the node for a given value or NULL if none exists
    
    bool contains(string prefix) const;
    bool insert(string m, double r, Node *n); // note overloading names for simplicity
    void printPreOrder(Node *n) const;
    int count(Node* n) const;
};
void play(BST& movies,string prefix);
Node* MaxNode(vector<Node*> v);

#endif
