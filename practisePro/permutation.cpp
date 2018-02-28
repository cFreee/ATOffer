#include "solution.h"

void printPermutation(char *str, char *start) {
    if (*start == '\0') {
        cout << str << endl;
        return;
    }

    //如果是有重复字符，在交换时判断是否相等并不能解决字符串重复。 测试样例：abca ，带重复全排列如后注释
    for (char *tmp = start; *tmp != '\0'; tmp++) {
        char ch = *tmp;
        *tmp = *start;
        *start = ch;
        printPermutation(str, start + 1);
        *start = *tmp;
        *tmp = ch;
    }
}

void solution::permutation(char *str) {
    if (str == NULL) {
        return;
    }

    char *start = str;
    printPermutation(str, start);
}


/*
bool next(vector<int> &v)//注意是引用
{
    int i;
    for(i=v.size()-1;i>=1;i--)
    {//从数组后面往前找到第一个比后面的数小的地方
        if(v[i-1]<v[i])
            break;
    }
    if(i==0)//整个数组都是逆序，说明是已是排列最后一个
        return false;//没有下一个
    else
    {
        int t=v[i-1],pos=i;
        for(int j=i;j<v.size();j++)
        {
            if(v[j]>t && v[j]<=v[pos])//再往后找比v[i-1]大的数中最小的一个 //2014.10.1把<改成<=,否则输入有重复数字时会出现bug
                pos=j;
        }
        v[i-1]=v[pos];
        v[pos]=t;//交换
        //sort(v.begin()+i,v.end());//从小到达排序
        reverse(v.begin()+i,v.end());//此时正好逆序，只需反转即可从小到达排序
        return true;//还有下一个
    }
}
void printVector(vector<int> v)
{
    for(int i=0;i<v.size();++i)
        cout<<v[i]<<" ";
    cout<<endl;
}

int main()
{
    int a[] = {1,2,3,4,5};
    vector<int> v(a,a+5);
    do
    {
        printVector(v);
    }while(next(v));
    return 0;
}
 */
