#include <iostream>
using namespace std;


/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node *findMiddle(Node *head) 
{
    // If head is null just return null
    if (head == NULL) 
    {
        return head;
    }
    
    if (head->next == NULL) 
    {
        return head;
    }
    
    Node *fast = head;
    Node *slow = head;
    while (fast != NULL && fast->next != NULL) 
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

