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
    int getDecimalValue(ListNode* head) {
        if (head == NULL) return 0;
        if (head->next == NULL) return head->val;
        head = reverse(head);
        int ans = 0;
        int power = 0;
        while (head) {
            if (head->val == 1) {
                ans += pow(2,power);
            }
            power++;
            head = head->next;
        }
        return ans;
    }
};
