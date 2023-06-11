#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

Node *rotate(Node *head, int k) {
    if(head == NULL) {
        return head;
    }
    
    int len = 1;
    Node *temp = head;
        
    while(temp->next != NULL) {
        temp = temp->next;
        len += 1;
    }
    
    k = k % len;
    
    if(k == len || k == 0) {
        return head;
    }

    temp->next = head;

    temp = head;
    
    for(int i = 0; i < abs(len - k - 1); i++) {
        temp = temp->next;
    }

    head = temp->next;
    temp->next = NULL;

    return head;
}
