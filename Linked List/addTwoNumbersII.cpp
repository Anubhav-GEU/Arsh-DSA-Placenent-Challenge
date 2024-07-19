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
        ListNode* curr = head, *prev = NULL;
        while (curr) {
            ListNode* next =curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);
        int carry = 0;
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        while (l1 || l2 || carry) {
            int digit1 = (l1 == NULL) ? 0 : l1->val; 
            int digit2 = (l2 == NULL) ? 0 : l2->val;

            int sum = digit1+digit2+carry;
            int digit = sum%10;
            carry = sum/10;

            ListNode* newNode = new ListNode(digit);
            curr->next = newNode;
            curr = curr->next;

            l1 = (l1 != nullptr) ? l1->next : nullptr;
            l2 = (l2 != nullptr) ? l2->next : nullptr;
        }
        ListNode* res = dummy->next;
        res = reverse(res);
        delete dummy;
        return res;
    }
};
