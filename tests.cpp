#include "tests.h"
#include "movies.h"
#include <iostream>
using namespace std;

void test_constructor(){
    START_TEST("test_constructor");
    START_TEST("test_Node_Constructor");
    Node n;
    cout<<" Expected: name of Node == default"<<endl;
    cout<<" Actual: name of Node == "<<n.name<<endl;
    END_TEST("test_Node_Constructor");
    START_TEST("test_BST_Constructor");
    BST bst;
    if(bst.getRoot()==nullptr){
        cout<<" PASSED: test_constructor, root ==NULL"<<endl;
    }else{
        cout<<" FAILED: test_constructor"<<endl;
    }
    END_TEST("test_BST_Constructor");
    END_TEST("test_constructor");
}

void test_destructor(){
    START_TEST("test_destructor");
    BST *bst = new BST;
    bst->insert("jumanji",6.9);
    bst->insert("sabrina", 6.2);
    bst->insert("tom and huck",5.4);
    bst->insert("sudden death",5.5);
    bst->insert("the american president",6.5);
    delete bst;
    cout<<"Testing destructor, run in valgrind to check for leaks"<<endl;
    END_TEST("test_destructor");
}

void test_printPreOrder(){
    START_TEST("test_printPreOrder");
    BST bst;
    cout<<"Empty tree:\n";
    bst.printPreOrder();
    bst.insert("toy story",7.7);
    cout<<"One element:\n";
    bst.printPreOrder();
    bst.insert("jumanji",6.9);
    bst.insert("sabrina", 6.2);
    bst.insert("tom and huck",5.4);
    bst.insert("sudden death",5.5);
    bst.insert("the american president",6.5);
    cout<<"Many element:\n";
    cout<<"Actual:"<<endl;
    bst.printPreOrder();
    END_TEST("test_printInOrder");
}
void test_count(){
    START_TEST("test_count");
    BST bst;
    cout<<" Empty tree, actual count is: "<<bst.count()<<endl;
    bst.insert("toy story",7.7);
    cout<<" One element, actual count is: "<<bst.count()<<endl;
    cout<<" General case with 6 element, actual count is: ";
    bst.insert("jumanji",6.9);
    bst.insert("sabrina", 6.2);
    bst.insert("tom and huck",5.4);
    bst.insert("sudden death",5.5);
    bst.insert("the american president",6.5);
    cout<<bst.count()<<endl;
    if (bst.count()==6){
        cout << "PASSED: count()"<<endl;
    }
    else{
        cout <<"FAILED: count()"<<endl;
    }
    END_TEST("test_count");
}
void runAll(){
    test_constructor();
    test_destructor();
    test_printPreOrder();
    test_count();
    /*
    test_sum();
	test_count();
	test_contains();
	test_predecessor();
	test_successor();
	test_remove();
    */
}

int main(){
    runAll();
    return 0;
}
