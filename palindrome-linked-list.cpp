#include <iostream>
#include <vector>
#include <algorithm>
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

LinkedListNode<int> *reverse(LinkedListNode<int> *head) {
    LinkedListNode<int> *reverseHead = NULL;

    LinkedListNode<int> *current = head;

    while (current != NULL) {

        LinkedListNode<int> *currentNext = current->next;
        current->next = reverseHead;
        reverseHead = current;
        current = currentNext;

    }

    return reverseHead;

}

bool isPalindrome(LinkedListNode<int> *head) {

    LinkedListNode<int> *slow = head;
    LinkedListNode<int> *fast = head;
    LinkedListNode<int> *prev = head;

    while (fast != NULL && fast->next != NULL) {
        prev = slow;
        fast = fast->next->next;
        slow = slow->next;
    }

    if (fast != NULL) {
        slow = slow->next;
    }

    if (slow == NULL) {
        return true;
    }

    prev->next = NULL;

    LinkedListNode<int> *reverseHead = reverse(slow);

    while (head != NULL) {

        if (head->data != reverseHead->data) {
            return false;
        }
        reverseHead = reverseHead->next;
        head = head->next;

    }

    return true;

}