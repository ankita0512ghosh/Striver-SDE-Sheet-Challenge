#include <iostream>
#include <vector>

using namespace std;


/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next) {
 *          this->data = data;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/
Node *addTwoNumbers(Node *num1, Node *num2)
{
    Node *node1 = num1;
    Node *node2 = num2;

    int sum = 0, carry = 0;

    Node *prev = NULL;

    while (node1 != NULL && node2 != NULL)
    {
        sum = node1->data + node2->data + carry;

        node1->data = sum % 10;

        carry = sum / 10;

        prev = node1;

        node1 = node1->next;
        node2 = node2->next;
    }

    if (node1 != NULL || node2 != NULL)
    {
        if (node2 != NULL)
        {
            prev->next = node2;
        }

        node1 = prev->next;

        while (node1 != NULL)
        {
            sum = node1->data + carry;

            node1->data = sum % 10;

            carry = sum / 10;

            prev = node1;
            node1 = node1->next;
        }
    }

    if (carry > 0)
    {
        prev->next = new Node(carry);
    }

    return num1;
}
