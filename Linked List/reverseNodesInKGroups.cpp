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
        ListNode* prev = NULL, *curr = head;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* temp = head;
        int countNodes = 0;
        while (temp) {
            temp = temp->next;
            countNodes++;
        }
        int count = k;
        temp = head;
        ListNode* tail = head;
        ListNode* next = NULL;
        ListNode* prev = NULL;
        for (int i=1; i<=countNodes/k; i++) {
            count = k;
            tail = temp;
            while (count-1 > 0) {
                tail = tail->next;
                count--;
            }
            next = tail->next;
            tail->next = NULL;
            tail  = reverse(temp);
            if (i == 1) head = tail;
            if (prev) prev->next = tail;
            prev = temp;
            temp->next = next;
            temp = temp->next;
        }
        return head;
    }
};
