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
        ListNode* temp = head;
        ListNode* prevNode = new ListNode(-101);
        ListNode* p = prevNode;
        while (temp) {
            int count = 0;
            int val = temp->val;
            ListNode* prev = temp;
            while (temp && prev->val == temp->val) {
                temp = temp->next;
                count++;
            }
            if (count == 1) {
                p->next = prev;
                p = p->next;
            }
        }
        p->next = NULL;
        return prevNode->next;
    }
};
