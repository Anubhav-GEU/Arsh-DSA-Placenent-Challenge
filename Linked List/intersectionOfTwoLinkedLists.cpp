/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int count1 = 0;
        int count2 = 0;
        ListNode* temp1 = headA;
        while (temp1) {
            count1++;
            temp1 = temp1->next;
        }
        temp1 = headB;
        while (temp1) {
            count2++;
            temp1 = temp1->next;
        }
        temp1 = headA;
        ListNode*temp2 = headB;
        if (count1>count2) {
            int store = count1-count2;
            while (store) {
                temp1 = temp1->next;
                store--;
            }
        }
        else if (count2>count1) {
            int store = count2-count1;
            while (store) {
                temp2 = temp2->next;
                store--;
            }
        }

        while (temp1 && temp2 && temp1 != temp2) {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return temp1;
    }
};
