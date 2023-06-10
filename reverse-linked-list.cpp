#include <iostream>
using namespace std;


/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{

    LinkedListNode<int> *prev = NULL;

    LinkedListNode<int> *current = head;

    while (current != NULL) 
    {
        LinkedListNode<int> *nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;

    }

    return prev;
}