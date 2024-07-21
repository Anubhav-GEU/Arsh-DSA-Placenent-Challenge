/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) return head;
        Node* headCopy = NULL;
        Node* temp = head;
        while (temp) {
            Node* next = temp->next;
            temp->next = new Node(temp->val);
            temp = temp->next;
            if (headCopy == NULL) headCopy = temp;
            temp->next = next;
            temp = temp->next;
        } 
        temp = head;
        while (temp && temp->next) {
            Node* random = temp->random;
            if (random && random->next)
            temp->next->random = random->next;
            temp = temp->next->next;
        }
        temp = head;
        Node* copiedHead = head->next;
        Node* copyCurrent = copiedHead;
        while (temp) {
            temp->next = temp->next->next;
            if (copyCurrent->next) {
                copyCurrent->next = copyCurrent->next->next;
            }
            temp = temp->next;
            copyCurrent = copyCurrent->next;
        }

        return copiedHead;
    }
};
