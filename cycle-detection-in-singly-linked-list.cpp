#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/****************************************************************

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


*****************************************************************/

bool detectCycle(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return false;
    }

    Node *slow = head;
    Node *fast = head->next;
    
    while (slow != fast)
    {
        if (fast == NULL || fast->next == NULL)
        {
            return false;
        }
        slow = slow->next;
        fast = fast->next->next;
    }

    return true;
}