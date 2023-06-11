#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */

Node *merge(Node *first, Node *second)
{

    if (first == NULL)
    {
        second->next = nullptr;
        return second;
    }

    if (second == NULL)
    {
        first->next = nullptr;
        return first;
    }

    Node *merged = NULL;

    if (first->data < second->data)
    {
        merged = first;
        merged->child = merge(first->child, second);
    }
    else
    {
        merged = second;
        merged->child = merge(first, second->child);
    }
    merged->next = nullptr;
    return merged;
}

Node *flattenLinkedList(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    head->next = flattenLinkedList(head->next);

    head = merge(head, head->next);

    return head;
}
