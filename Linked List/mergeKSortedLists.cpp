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
    ListNode* merge(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        ListNode* result;
        if (l1->val < l2->val) {
            result = l1;
            result->next = merge(result->next,l2);
        }
        else {
            result = l2;
            result->next = merge(l1,result->next);
        }
        return result;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
         if(lists.size() == 0){
            return NULL;
        }
        if(lists.size() == 1){
            return lists[0];
        }
        ListNode* head = lists[0];
        for (int i=1; i<lists.size(); i++) {
            head = merge(head,lists[i]);
        }
        return head;
    }
};
