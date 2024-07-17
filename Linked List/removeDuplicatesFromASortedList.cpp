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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* temp = head;
        int prev = head->val;
        while (temp) {
            ListNode* next = temp;
            while (next && (prev == next->val)) {
                prev = next->val;
                next = next->next;
            }
            if (next == NULL) {
                temp->next = NULL;
                return head;
            }
            temp->next = next;
            temp = next;
            prev = temp->val;
        }
        return head;
    }
};
