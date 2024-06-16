#ifndef LISTQUEUE_H
#define LISTQUEUE_H

#include <iostream>
#include "DbList.h"

template <class T>
class ListQueue{

    public:
        ListQueue();
        ~ListQueue();

        T peek();
        void enqueue(T x);
        void dequeue();
        unsigned int size();
        bool isEmpty();
    
    private:
        int numElements;
        DoublyLinked<T> list;
};

template <class T>
ListQueue<T>::ListQueue(){
}

template <class T>
ListQueue<T>::~ListQueue(){}

template <class T>
void ListQueue<T>::enqueue(T x){
    list.insertBack(x);
    ++numElements;
}

template <class T>
void ListQueue<T>::dequeue(){
    if(isEmpty()){
        throw std::runtime_error("EMPTY");
    }
    list.removeFront();
    --numElements;
}

template <class T>
T ListQueue<T>::peek(){
    return list.getFront();
}

template <class T>
unsigned int ListQueue<T>::size(){
    return list.getSize();
}

template <class T>
bool ListQueue<T>::isEmpty(){
    return (numElements == 0);
}

#endif