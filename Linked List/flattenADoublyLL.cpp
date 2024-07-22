/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    void convert(Node* head) {
        Node* next = head->next;
        Node* child = head->child;
        Node* childLast = child;
        
        head->next = child;
        child->prev = head;
        head->child = NULL;
        
        while (childLast->next) {
            childLast = childLast->next;
        }
        
        childLast->next = next;
        if (next != NULL) {
            next->prev = childLast;
        }
    }
    Node* flatten(Node* head) {
        if (head == NULL) return NULL;
        
        Node* temp = head;
        while(temp != NULL) {
            if (temp->child != NULL) {
                convert(temp);
            }
            temp = temp->next;
        }
        return head;
    }
};
