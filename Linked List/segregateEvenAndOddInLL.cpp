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
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* ss=NULL,*se=NULL, *gs=NULL, *ge=NULL;
        ListNode* temp = head;
        int counter = 0;
        while (temp) {
            if (counter%2 == 0) {
                if (ss == NULL) ss = se = temp;
                else {
                    se->next = temp;
                    se = se->next;
                }
            }
            else {
                if (gs == NULL) gs = ge = temp;
                else {
                    ge->next = temp;
                    ge = ge->next;
                }
            }
            temp = temp->next;
            counter++;
        }
        if (gs != NULL) ge->next = NULL;
        if (ss == NULL) return gs;
        se->next = gs;
        return ss;
    }
};
