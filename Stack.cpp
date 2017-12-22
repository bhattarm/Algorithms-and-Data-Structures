

/*
Generic Stacks(last in first out) written in c++
By: Madan Bhattarai

When you Call Pop it returns pointer to the element at front of the stack. So, as soon as the 
pointer is returned, program doesn't gurantee the existance of pointer. 
So, deference the pointer and set it equal to the local variable
if you want to use it later on. 
*/


/*
Forward declared class stacsk
*/
#ifndef __STACK__
#define __STACK__


template<class T>
class Stack {

    public:
        Stack() { head = 0; }
        bool IsEmpty() {return head == 0; }
        void SetToNull() {head = 0; }
        void Push(const T&);
        T* Pop();

    private:
        struct Node
        {
            T data;
            Node* next;
            Node(T element, Node *n = 0)
            {
                data = element;
                next = n;
            }
        }*head;
        T returnData;
};

template<class T>
void Stack<T>::Push(const T& element)
{
    //If stack is empty
    if(head == 0)
    {
        head =  new Node(element);
    }
    else
    {
        head = new Node(element,head);
    }
}

template<class T>
T* Stack<T>::Pop()
{
    if(head == 0) { return 0;  }
    else
    {
        Node* temp = head;
        returnData = temp->data;
        head = head->next;
        delete temp;
        return &returnData;
    }
}

#endif

#include <iostream>
using namespace std;

int main()
{
    Stack<int> stack;
    stack.Push(5);
    stack.Push(4);
    stack.Push(3);
    stack.Push(2);
    stack.Push(1);
    while(stack.IsEmpty() == false)
    {
        cout<<*stack.Pop()<<' ';
    }
    cout<<'\n';
}