#include"solution.h"
/*方法中都将第一个元素当枢轴，小于枢纽值key的序列的末尾为枢轴的index，并将末尾值与枢纽值进行交换*/

int partition(int data[], int length, int start, int end){
    if(data == NULL || length <= 0 || start < 0 || end >= length){
        logic_error ex("invlid input.");
        throw exception(ex);
    }
    int index = start + 1;
    int small = index;
    for(; index <= end; index++){
        if(data[index] < data[start]){
            if(index != small){
                swap(data[index], data[small]);
            }
            small++;
        }
    }
    swap(data[--small], data[start]);// --smal-是为了将队列中最后一个比key小的值与key所在的index交换
    return small;
}

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

//顺序遍历，将小于key的值依次交换到前列，得到small序列
void solution::quickSort(int data[], int start, int end, int length){
    if(start == end){
        return;
    }

    int index = partition(data, length, start, end);
    if(index > start){
        quickSort(data, start, index - 1, length);
    }
    if(index < end){
        quickSort(data, index + 1, end, length);
    }
}

//另一种实现,依次前后遍历，将两端寻到的“异常值”进行交换，得到small序列
void solution::quickSort(int data[], int start, int end){
    if(start >= end){
        return;
    }
    int small = start + 1, big = end;
    while(small < big){
        while(small < big && data[small] < data[start]){
            ++small;
        }
        while(big > small && data[big] >= data[start]){
            --big;
        }

        if(small < big){
            swap(data[small], data[big]);
        }
    }
    if(data[small] >= data[start]){
        small--;
    }

    if(small != start){
        swap(data[small], data[start]);
    }

    quickSort(data, small + 1, end);
    quickSort(data, start, small - 1);
}

//同上一方法，不同之处在于每次寻到“异常值”时都进行交换
void solution::quickSort2(int a[], int low, int high)
{
    if(low >= high)
    {
        return;
    }
    int first = low;
    int last = high;
    int key = a[first];/*用字表的第一个记录作为枢轴*/

    while(first < last)
    {
        while(first < last && a[last] >= key)
        {
            --last;
        }

        a[first] = a[last];/*将比第一个小的移到低端*/

        while(first < last && a[first] <= key)
        {
            ++first;
        }

        a[last] = a[first];
/*将比第一个大的移到高端*/
    }
    a[first] = key;/*枢轴记录到位*/
    quickSort2(a, low, first-1);
    quickSort2(a, first+1, high);
}
