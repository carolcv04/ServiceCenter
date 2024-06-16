#ifndef DBLIST_H
#define DBLIST_H

//standard doubly linked list 
template <typename T> 
class Node {
    public:
        Node(T data);
        ~Node();

        T getData();
        Node<T>* next = nullptr;
        Node<T>* prev = nullptr;
        T data;
};
template <typename T> 
Node<T>::Node(T d){
    data = d;
}

template <typename T> 
Node<T>::~Node() {}

template <typename T> 
T Node<T>::getData(){ 
    return data;
}

template <class T>
class DoublyLinked{
    private:
        Node<T> *front;
        Node<T> *back;
        unsigned int size;
    public:
        DoublyLinked();
        ~DoublyLinked();

        void insertFront(T d);
        void insertBack(T d);
        T removeBack();
        T removeFront();
        T removeNode(T value);
        T find(T value);
        bool isEmpty();
        unsigned int getSize();
        T getFront();
        Node<T>* getFrontPointer();

        void printList(bool isPrintLink);


};

template <class T>
DoublyLinked<T>::DoublyLinked(){
    front = nullptr;
    back = nullptr;
    size = 0;
}

template <class T>
DoublyLinked<T>::~DoublyLinked(){
    
    // while (front != nullptr) {
    //     Node<T>* temp = front;
    //     front = front->next;
    //     delete temp;
    // }
    // back = nullptr;
}

template <class T>
void DoublyLinked<T>::insertFront(T d){
    Node<T> *node = new Node<T>(d);

    if(isEmpty()){
        back = node;
    }
    else{
        node->next = front;
        front->prev = node;
    }
    front = node;
    ++size;
}

template <class T>
void DoublyLinked<T>::insertBack(T d){
    Node<T> *node = new Node<T>(d);

    if(isEmpty()){
        front = node;
    }
    else{
        back->next = node;
        node->prev = back;
    }
    back = node;
    ++size;
}

template <class T>
T DoublyLinked<T>::removeFront(){
    if(isEmpty()){
        throw std::runtime_error("list is empty");
    }

    Node<T> *temp = front;

    if(front->next == NULL){
        //one null in the list
        back = NULL;
    }
    else{
        //more than one node
        front->next->prev = NULL;
    }

    front = front->next;
    temp->next = NULL;
    T data = temp->data;
    --size;

    delete temp;
    return data;
}

template <class T>
T DoublyLinked<T>::removeBack(){
    if(isEmpty()){
        throw std::runtime_error("list is empty");
    }

    Node<T> *temp = back;

    if(back->prev == NULL){
        //one node
        front = NULL;
    }
    else{
        back->prev->next = NULL;
    }
    back = back->prev;
    temp->prev = NULL;
    T data = temp->data;
    --size;
    delete temp;
    return data;
}

template <class T>
T DoublyLinked<T>::find(T value){
    int pos = -1;
    Node<T> *curr = front;

    while(curr != NULL){
        ++pos;
        if(curr->data == value)
            break;
        curr = curr->next;
    }
    if(curr == NULL)
        pos = -1;
    
    return pos;
}

template <class T>
T DoublyLinked<T>::removeNode(T value){

    if(isEmpty()){
        throw std::runtime_error("list is empty");
    }

    Node<T> *curr = front;
    while(curr->data != value){
        curr = curr->next;

        if(curr == NULL)
            return -1;
    }

    //if we make it here we found the node that needs to be deleted :3
    if(curr == front){
        front = curr->next;
        front->prev = NULL;
    } else if(curr == back){
        back = curr->prev;
        back->next = NULL;
    }else{
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
    }

    curr->next = NULL;
    curr->prev = NULL;
    int temp = curr->data;
    --size;
    delete curr;
}

template <class T>
T DoublyLinked<T>::getFront(){
    return front->data;
}

template <class T>
bool DoublyLinked<T>::isEmpty(){
    return (getSize() == 0);
}

template <class T>
unsigned int DoublyLinked<T>::getSize(){
    return size;
}

template <class T>
Node<T>* DoublyLinked<T>::getFrontPointer(){
    return front;
}

#endif