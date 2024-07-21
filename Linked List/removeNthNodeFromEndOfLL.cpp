/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverse(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* curr = head, *prev = NULL;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL) return NULL;
        if (head->next == NULL && n==1) return NULL;
        head = reverse(head);
        if (n == 1) {
            head = head->next;
            return reverse(head);
        }
        ListNode* temp = head;
        for (int i=1; i<n-1 && temp; i++) {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        head = reverse(head);
        return head;
    }
};
