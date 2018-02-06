#include <iostream>
#include"solution.h"
using namespace std;

void change(int *p){
    *p = 4;
}



int main()
{
    cout << "Hello World!" << endl;
    int a[] = {1,0,1,1,1};
    solution s;
    cout << s.minNum(a, 5);
    return 0;
}

