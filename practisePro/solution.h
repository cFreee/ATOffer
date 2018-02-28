#ifndef SOLUTION
#define SOLUTION

#include<cstdio>
#include<stack>
#include <queue>
#include <vector>
#include<iostream>
#include<exception>
#include<cstring>

using namespace std;

/**
 *剑指offer的面试题项目的唯一头文件
 * 为方便和简易，将所有实现的面试题函数和用到的结构体、类都写在class solution中
 * 使用尾注编号
 * 每个面试题目有各自的源文件来实现
 * 只有某一题使用的辅助函数只在该题目对应的源文件中实现
 */

struct ListNode{
    int value;
    ListNode *next;

    ListNode(int value) {
        this->value = value;
        next = NULL;
    }
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

struct ComplexListNode {
    int value;
    ComplexListNode *next;
    ComplexListNode *sibling;

    ComplexListNode(int value) {
        value = this->value;
        next = NULL;
        sibling = NULL;
    }
};

class solution {
public:
    //solution();

    bool searchBinArr(int*, int, int, int);  //No.3
    void replaceBlank(char[], int);  //No.4
    void printListReversingly(ListNode* );  //No.5

    BinaryTreeNode *rebuiltTree(int *, int *, int);  //No.6 focus!!! ***

    void printNDigits(int);  //No.12
    void deleteNode(ListNode *, ListNode *);  //No.13
    void reorderList(int *, int n);  //No.14

    ListNode *theLastKthNode(ListNode *, int);  //No.15
    ListNode *reverseList(ListNode *);  //No.16
    ListNode *mergeList(ListNode *, ListNode *);  //No.17

    bool isSubTree(BinaryTreeNode *, BinaryTreeNode *);  //No.18
    void printMatrix(int **, int, int);  //N0.20

    //No.21
    template<typename T>
    class StackWithMin {
    public:
        stack<T> s1;
        stack<T> s2; //minStack
    public:
        void push(const T &);

        void pop();

        const T &min();
    };

    bool isValidOrder(int *, int *, int);  //No.22
    void printBTreeFromTopToBottom(BinaryTreeNode *); //No.23, notice
    bool isPostOrder(int *, int); //No.24

    //No.7 思路有点错误
    template<typename T> class CQueue{
    public:
        CQueue ();
        ~CQueue ();

        void appendTail(const T&);
        T deleteHead();

    private:
        stack<T> s1;
        stack<T> s2;
    void findSumPath(BinaryTreeNode *, int);  //No.25
    void findSumPath(BinaryTreeNode *, int, vector<BinaryTreeNode *>);  //No.25

    };

    //quickSort
    void quickSort(int[], int, int, int);
    void quickSort(int[], int, int);
    void quickSort2(int[], int, int);

    int minNum(int*, int);//No.8

    ComplexListNode *clone(ComplexListNode *);  //No.26 focus!!!
    BinaryTreeNode *treeToList(BinaryTreeNode *);  //No.27 notice book's function
    void permutation(char *);  //No.28
    void combination();  //focus!!!

    int moreThanHalfNum(int *, int);  //No.29
    void getLastKNumber(int *, int *, int, int);  //No.30
    int findMaxSum(int *, int); //No.31
    int numberOf1Between1AndN(int); //No.32 notice

    void printMinNumber(int *, int);  //No.33 注意qsort的使用

    int getUglyNumber(int);  //No.34 notice

    char firstNotRepeatChar(char *); //No.35
    int inversePairs(int *, int); //No.36 focus,归并排序的变种。。。

    ListNode *findFirstInCommon(ListNode *, ListNode *); //No.37
    int getNumberOfK(int *, int, int); //No.38 notice

    int deepOfTree(BinaryTreeNode *); //No.39
    void findNumAppendOnce(int *, int, int *, int *); //No.40 focus

    bool findNumbersWithSum(int *, int, int *, int *, int);  //No.41
    char *reverseSentence(char *);  //No.42

    void printProbability(int); //No.43 notice
};

#endif // SOLUTION

