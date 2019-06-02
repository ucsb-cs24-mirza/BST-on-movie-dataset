// movies.cpp
// Implements class BST
// Danming Wang 05/31/2019

#include "movies.h"

#include <iostream>
using std::cout;

// constructor sets up empty tree
BST::BST() : root(0) { }

// destructor deletes all nodes
BST::~BST() {
    clear(root);
}

// recursive helper for destructor
void BST::clear(Node *n) {
    if (n) {
	    clear(n->left);
	    clear(n->right);
	    delete n;
    }
}

// insert value in tree; return false if duplicate
bool BST::insert(string n, double r) {
    // handle special case of empty tree first
    if (!root) {
	    root = new Node(n,r);
	    return true;
    }
    // otherwise use recursive helper
    return insert(n,r, root);
}

// recursive helper for insert (assumes n is never 0)
bool BST::insert(string m, double r,  Node *n) {
    if (m == n->name)
	    return false;
    if (m < n->name) {
	    if (n->left)
	        return insert(m,r, n->left);
	    else {
	        n->left = new Node(m,r);
	        n->left->parent = n;
	        return true;
	    }
    }
    else {
	    if (n->right)
	        return insert(m,r, n->right);
	    else {
	        n->right = new Node(m,r);
	        n->right->parent = n;
	        return true;
	    }
    }
}

// print tree data pre-order
void BST::printPreOrder() const {
    printPreOrder(root);
}

// recursive helper for printPreOrder()
void BST::printPreOrder(Node *n) const {
    if (n) {
	    cout << n->name << ", "<<n->rating<<endl;
	    printPreOrder(n->left);
	    printPreOrder(n->right);
    }
}
// return count of values
int BST::count() const {
    return count(root);
}

// recursive helper for count
int BST::count(Node *n) const {
    if (!n){
        return 0;
    }
    return 1+count(n->left)+count(n->right);
}

vector<Node*> BST:: getNodesFor(string prefix){
    return getNodesFor(prefix, root);
}
vector<Node*> BST::getNodesFor(string prefix, Node* n) const{
    vector<Node*> v;
    int i= prefix.length();
    if (!n){
        return v;
    }
    else if (n->name.substr(0,i) == prefix){
        v.push_back(n);
    }
    else if (n->name.substr(0,i) >prefix){
        return getNodesFor(prefix,n->left);
    }
    else {
        return getNodesFor(prefix,n->right);
    }
    return v; // think about this
}

Node* MaxNode(vector<Node*> v){
    Node* max=v[0];
    for (int i=0; i<v.size();i++){
        if(v[i]->rating > max->rating){
            max=v[i];
        }
    }
    return max;
}


// returns true if value is in the tree; false if not
bool BST::contains(string prefix) const {
    if (getNodesFor(prefix,root).empty()){
        return false;
    }
    return true;
}
/*
// returns the Node containing the predecessor of the given value
BST::Node* BST::getPredecessorNode(int value) const{
    Node* a= getNodeFor(value,root);
    if(a==nullptr){
        return nullptr;
    }
    else if(a->left){
        Node* m=a->left;
        // predecessor of value is in its subtree
        while(m->right){
            m=m->right;
        }
        return m;
    }
    else{
        Node* t=a->parent;
        while(t&&t->info>a->info){
            t=t->parent;
        }
        // if there is no predecessor, then t=nullptr and exit while loop
        return t;
        
    }
}

// returns the predecessor value of the given value or 0 if there is none
int BST::getPredecessor(int value) const{
    if (getPredecessorNode(value)==nullptr){
        return 0;
    }
    return getPredecessorNode(value)->info;
}

// returns the Node containing the successor of the given value
BST::Node* BST::getSuccessorNode(int value) const{
    Node* a= getNodeFor(value,root);
    if(a==nullptr){
        return nullptr;
    }
    else if(a->right){
        Node* m=a->right;
        while(m->left){
            m=m->left;
        }
        return m;
    }
    else{
        Node* t=a->parent;
        while(t&&t->info<a->info){
            t=t->parent;
        }
        return t;
        
    }
}

// returns the successor value of the given value or 0 if there is none
int BST::getSuccessor(int value) const{
    if (getSuccessorNode(value)==nullptr){
        return 0;
    }
    return getSuccessorNode(value)->info;
}

// deletes the Node containing the given value from the tree
// returns true if the node exist and was deleted or false if the node does not exist
bool BST::remove(int value){
    Node* a= getNodeFor(value,root);
    Node* p = a->parent;
    if (a==nullptr){
        return false;
    }
    else if (!a->left&& !a->right){
        if(a==root){
            root = nullptr;
        }
        // Node is a leaf node
        else if(a->info>p->info){
            p->right=nullptr;
            delete a;
        }
        else{
            p->left=nullptr;
            delete a;
        }
        return true;
    }
    else if (!a->left){
        // Node has only one child
        if(p->info>a->info){
            p->left=a->right;
            a->right->parent=p;
            delete a;
        }
        else{
            p->right=a->right;
            a->right->parent=p;
            delete a;
        }
        return true;
    }
    else if (!a->right){
        // Node has only one child
        if(p->info>a->info){
            p->left=a->left;
            a->left->parent=p;
            delete a;
        }
        else{
            p->right=a->left;
            a->left->parent=p;
            delete a;
        }
        return true;
     }
     else {
         int sn = getSuccessor(value);
         remove(sn);
         a->info=sn;
         return true;
      
    }
}
*/
void play(BST& movies, string prefix){
    vector<Node*> v= movies.getNodesFor(prefix);
    Node* max = MaxNode(v);
    movies.printPreOrder();
    cout<<"Best movie is "<<max->name<<" with rating "<<max->rating<<endl;

}
