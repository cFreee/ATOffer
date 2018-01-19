#ifndef SOLUTION
#define SOLUTION

#include<cstdio>
#include<stack>
#include<iostream>
#include <exception>

using namespace std;

struct ListNode{
    int value;
    ListNode *next;
};

struct BinaryTreeNode{
    int value;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
    BinaryTreeNode(int value){
        this->value = value;
        left = NULL;
        right = NULL;
    }
};

class solution{
public:
    solution();

    bool searchBinArr(int*, int, int, int);  //No.3
    void replaceBlank(char[], int);  //No.4
    void printListReversingly(ListNode* );  //No.5

    BinaryTreeNode* rebulitTree(int*, int*, int);  //No.6 focus!!!


};

#endif // SOLUTION

