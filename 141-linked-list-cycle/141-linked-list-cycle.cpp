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
    bool hasCycle(ListNode *head) {
        ListNode* fast = head, *slow = head;
        bool flag = false;
        while(!flag || fast!=slow){
            flag = true;
            if(fast == NULL|| fast->next == NULL){return false;}
            fast = fast->next->next;
            slow = slow->next;
        }
        return true;
    }
};