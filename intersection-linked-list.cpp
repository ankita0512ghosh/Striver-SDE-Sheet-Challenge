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

int length(Node *head)
{
    int length = 0;
    Node *tmp = head;

    while (tmp != NULL)
    {
        tmp = tmp->next;
        length++;
    }

    return length;
}

Node* findIntersection(Node *firstHead, Node *secondHead)
{

    int firstListLength = length(firstHead), secondListLength = length(secondHead);

    while (firstListLength > secondListLength)
    {
        firstHead = firstHead->next;
        firstListLength--;
    }

    while (firstListLength < secondListLength)
    {
        secondHead = secondHead->next;
        secondListLength--;
    }

    while (firstHead != secondHead)
    {
        firstHead = firstHead->next;
        secondHead = secondHead->next;
    }

    return firstHead;
}