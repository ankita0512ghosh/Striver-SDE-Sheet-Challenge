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
Node *firstNode(Node *head)
{
	if (head == NULL)
	{
		return NULL;
	}

	Node *slow = head;

	Node *fast = head;

	do
	{
		if (fast && fast->next)
		{
			fast = fast->next->next;
		}
		else
		{
			return NULL;
		}

		slow = slow->next;
	} while (fast != slow);

	slow = head;

	while (slow != fast)
	{
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}