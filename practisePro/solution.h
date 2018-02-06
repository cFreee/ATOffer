#ifndef SOLUTION
#define SOLUTION

#include<cstdio>
#include<stack>
#include<iostream>
#include <exception>

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
    //solution();

    bool searchBinArr(int*, int, int, int);  //No.3
    void replaceBlank(char[], int);  //No.4
    void printListReversingly(ListNode* );  //No.5

    BinaryTreeNode* rebulitTree(int*, int*, int);  //No.6 focus!!!

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

    };

    //quickSort
    void quickSort(int[], int, int, int);
    void quickSort(int[], int, int);
    void quickSort2(int[], int, int);

    int minNum(int*, int);//No.8

};


#endif // SOLUTION

