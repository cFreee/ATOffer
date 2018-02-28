#include "solution.h"

template <typename T> const T& solution::StackWithMin<T>::min() {
    if(s2.size() == 0){
        return NULL;
    }

    return s2.top();
}

template <typename T> void solution::StackWithMin<T>::push(const T& value) {
    s1.push(value);
    if(s2.size() == 0 || s2.top() >value){
        s2.push(value);
    } else{
        s2.push(s2.top());
    }
}

template <typename T> void solution::StackWithMin<T>::pop() {
    if(s1.size() == 0){
        return;
    }
    s1.pop();
    s2.pop();
}
