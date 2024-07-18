class Solution
{
    public:
    Node* reverse(Node* head) {
        if (head == NULL || head->next == NULL) return head;
        
        Node* curr = head, *prev = NULL;
        
        while (curr) {
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    Node *compute(Node *head)
    {
        // your code goes here
        head = reverse(head);
        Node* temp = head;
        while (temp && temp->next) {
            Node* next = temp->next;
            while (next && next->data < temp->data) {
                next = next->next;
            }
            temp->next = next;
            temp = next;
        }
        head = reverse(head);
        return head;
    }
    
};
