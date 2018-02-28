#include"solution.h"

template<typename T> solution::CQueue<T>::CQueue(){}

template<typename T> void solution::CQueue<T>::appendTail(const T& node){
    s1.push(node);
}

template<typename T> T solution::CQueue<T>::deleteHead(){
    if(s1.empty() && s2.empty()){
        logic_error ex("empty queue.");
        throw exception(ex);
    }

    if(s2.empty()){
        while(!s1.empty()){
            T tmp = s1.top();
            s2.push(tmp);
            s1.pop();
        }
    }

    T node;

    node = s2.top();
    s2.pop();
    return node;
}

template<typename T> solution::CQueue<T>::~CQueue(){
}
