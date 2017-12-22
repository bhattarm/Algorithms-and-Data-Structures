
/*
By: Madan Bhattarai
Doubly Linked List in C++ with Generic

When you Call RemoveFromHead or RemoveFromTail it returns pointer to the element at head and
pointer to the element at the tail. So, as soon as the pointer is returned, program doesn't gurantee
the existance of pointer. So, deference the pointer and set it equal to the local variable
if you want to use it later on. 
*/

#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST

#include <iostream>


//file with forward declartion for class and its methods
template<class T>
class DoublyLinkedList{

    public:
        DoublyLinkedList() { head = tail = 0; }
        int isEmpty() const {return head == 0; }
        void SetToNull() { head = tail = 0; }
        void AddToHead(const T&);
        void AddToTail(const T&);
        T* RemoveFromHead();
        T* RemoveFromTail();
        bool Find(const T&) const;
        void PrintList() const;
    
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
AddToHead(const T& element)
Adds element to the head of the linked list
*/
template<class T>
void DoublyLinkedList<T>::AddToHead(const T& element)
{
    //If there is already elements in the list
    if(head != 0)
    {
        head = new Node(element,head,0);
        head->next->prev = head;
    }
    else
    {
        head = new Node(element);
        tail = head;
    }
}

/*
AddToTail(const T&)
Adds element to the tail of the linked list
*/
template<class T>
void DoublyLinkedList<T>::AddToTail(const T& element)
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
Prints out the list from head to tail
does not print anything if the list is empty
*/
#include <iostream>
template<class T>
void DoublyLinkedList<T>::PrintList() const
{
    Node* temp;
    for(temp = head; temp; temp = temp->next)
    {
        std::cout << temp->data << ' ';
    }
    std::cout<<'\n';
}

/*
Remove from head and returns the first element of the list
If the list is not empty, it will return the first element in the list
but if the list is empty, it will return null
*/
template<class T>
T* DoublyLinkedList<T>::RemoveFromHead()
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
        return NULL;
    }
}

/*
Deletes the tail of the list if the list is not empty
returns null if list is empty
*/
template<class T>
T* DoublyLinkedList<T>::RemoveFromTail()
{
    //If the list is not empty
    if(tail != 0)
    {
        current_element = tail->data;
        
        //If there is only one element in the list
        if(head == tail)
        {
            delete tail;
            head = 0;
            tail = head;
        }
        else
        {
            tail = tail->prev;
            delete tail->next;
            tail->next = 0;   
        }

        return &current_element;
    }
    else
    {
        return NULL;
    }
}

/*
Finds the given element in the list
returns true if the element is in the list or returns false otherwise
*/
template<class T>
bool DoublyLinkedList<T>::Find(const T& element_to_find) const
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
    DoublyLinkedList<int> db;
    db.AddToHead(5);
    db.AddToHead(6);
    db.AddToTail(3);
    db.AddToTail(2);
    db.PrintList();

    while(db.isEmpty() == false)
    {
        cout<<*db.RemoveFromHead()<<'\n';
        cout<<*db.RemoveFromTail()<<'\n';
    }
    db.PrintList();
    cout<<db.Find(3)<<'\n';
    cout<<db.Find(6)<<'\n';
}