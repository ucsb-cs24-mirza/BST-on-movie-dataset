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
    int c = count();
    // handle special case of empty tree first
    if (!root) {
	    root = new Node(n,r,c);
	    return true;
    }
    // otherwise use recursive helper
    return insert(n,r, root);
}

// recursive helper for insert (assumes n is never 0)
bool BST::insert(string m, double r,  Node *n) {
    int c=count();
    if (m == n->name)
	    return false;
    if (m < n->name) {
	    if (n->left)
	        return insert(m,r, n->left);
	    else {
	        n->left = new Node(m,r,c);
	        n->left->parent = n;
	        return true;
	    }
    }
    else {
	    if (n->right)
	        return insert(m,r, n->right);
	    else {
	        n->right = new Node(m,r,c);
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
	    cout << n->name << ", "<<n->rating<<", "<<visitedNode(n->name)<<endl;
	    printPreOrder(n->left);
	    printPreOrder(n->right);
    }
}
// return count of values
int BST::visitedNode(string movie) const {
    return visitedNode(movie, root);
}

// recursive helper for count
int BST::visitedNode(string m,Node* n) const {
    if (!n){
        return -1;
    }
    else if(n->name==m){
        return 0;
    }
    else if(n->name > m){
        return 1+visitedNode(m,n->left);
    }
    else{
        return 1+visitedNode(m,n->right);
    }
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
 
    else if (n->name.substr(0,i) >prefix){
        return getNodesFor(prefix,n->left);
    }
    else if (n->name.substr(0,i)<prefix){
        return getNodesFor(prefix,n->right);
    }

    else {// (n->name.substr(0,i) == prefix){
        v.push_back(n);
        vector<Node*> v1=getNodesFor(prefix,n->left);
        vector<Node*> v2=getNodesFor(prefix,n->right);
        v.insert(v.end(),v1.begin(),v1.end());
        v.insert(v.end(),v2.begin(),v2.end());
        return v;
    }
}


Node* BST::MaxNode(string prefix){
    vector<Node*> v=getNodesFor(prefix);
    if(!v.empty()){
        Node* max=v[0];
        for (int i=0; i<v.size();i++){
            if(v[i]->rating > max->rating){
                max=v[i];
            }
        }
        return max;
    }
    else{
        return nullptr;
    }
}

void play(BST& movies, string prefix){
    Node* max = movies.MaxNode(prefix);
    movies.printPreOrder();
    cout<<endl;
    if(max)
        cout<<"Best movie is "<<max->name<<" with rating "<<max->rating<<endl;
}
void play2(BST& movies, int W){
    int N = movies.count();
    double NW = double(N) * double(W);
    double *avg = new double[W];
    for (int i=0;i<W;i++){
        clock_t t = clock();
        movies.searchAll();
        t=clock()-t;
        avg[i]=(((double)t)/(CLOCKS_PER_SEC))*1000000/double(N);
    }
    cout<<"Min AVERAGE Time is "<<min(avg,W)<<" micro seconds\n";
    cout<<"Max AVERAGE Time is " <<max(avg,W)<<" micro seconds\n";
    cout<<"Median AVERAGE Time is "<<median(avg,W)<<" micro seconds\n";
    delete avg;
}

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

Node* BST::search(int c, Node* n) const{
    if (!n){
        return nullptr;
    }
    else if (n->count == c){
        return n;
    }
    else if (n->count >c){
        return search(c,n->left);
    }
    else {
        return search(c,n->right);
    }
}

void BST::searchAll() {
    int num = count();
    searchAll(num, root); 
}

void BST::searchAll(int number, Node* n) {
    if(!n){
        return;
    }else{
        for(int i=0;i<number;i++){
            search(i,root);
        }
    }
}
