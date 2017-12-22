
/*
By: Madan Bhattarai
Queue written in C++ with Generic

When you Call Dequeue it returns pointer to the element at front of the queue. So, as soon as the 
pointer is returned, program doesn't gurantee the existance of pointer. 
So, deference the pointer and set it equal to the local variable
if you want to use it later on. 
*/

#ifndef __QUEUE__
#define __QUEUE__


//file with forward declartion for class and its methods
template<class T>
class Queue{

    public:
        Queue() { head = tail = 0; }
        int isEmpty() const {return head == 0; }
        void SetToNull() { head = tail = 0; }
        void Enqueue(const T&);
        T* Dequeue();
        bool Find(const T&) const;
    
    protected:
        struct Node{
            T data;
            Node *next,*prev;
            Node(T element, Node *n = 0, Node *p = 0)
            {
                data = element;
                next = n;
                prev = p;
            }
        }*head,*tail;

        T current_element;
};

/*
Enqueue(const T&)
Adds element to the end of the queue
*/
template<class T>
void
Queue<T>::Enqueue(const T& element)
{
    if(tail != 0)
    {
        tail = new Node(element,0,tail);
        tail->prev->next = tail;
    }
    else
    {
        tail = new Node(element);
        head = tail;
    }
}

/*
Remove the first element of the queue
If the list is not empty, it will return the first element in the list
but if the list is empty, it will return null
*/
template<class T>
T* 
Queue<T>::Dequeue()
{

    //If the list is not empty
    if(head != 0)
    {
        current_element = head->data;

        //If there is only one element in the list
        if(head == tail)
        {
            delete head;
            tail = 0;
            head = tail;
        }
        else
        {
            head = head->next;
            delete head->prev;
            head->prev = 0;
        }
        return &current_element;
    }
    else
    {
        return 0;
    }
}

/*
Finds the given element in the list
returns true if the element is in the list or returns false otherwise
*/
template<class T>
bool
Queue<T>::Find(const T& element_to_find) const
{
    Node *current_node;

    for(current_node = head; current_node; current_node = current_node->next)
    {
        if(current_node->data == element_to_find)
        {
            return true;
        }
    }

    return false;
}


#endif


#include <iostream>
using namespace std;

int main()
{
    Queue<int> queue;
    queue.Enqueue(1);
    queue.Enqueue(2);
    queue.Enqueue(3);
    queue.Enqueue(4);
    queue.Enqueue(5);
    while(queue.isEmpty() == false)
    {
        cout<<*queue.Dequeue()<<' ';
    }
    cout<<'\n';
}