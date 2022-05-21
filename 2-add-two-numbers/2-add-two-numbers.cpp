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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* fin = new ListNode();
        ListNode* prev = fin;
        while(l1 && l2){
            ListNode* temp = new ListNode();
            prev->next = temp;
            prev = temp;
            int sum = carry+l1->val+l2->val;
            temp->val = sum%10;
            carry = sum/10;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1){
            ListNode* temp = new ListNode();
            prev->next = temp;
            prev = temp;
            int sum = carry+l1->val;
            temp->val = sum%10;
            carry = sum/10;
            l1 = l1->next;
        }
        while(l2){
            ListNode* temp = new ListNode();
            prev->next = temp;
            prev = temp;
            int sum = carry+l2->val;
            temp->val = sum%10;
            carry = sum/10;
            l2 = l2->next;
        }
        if(carry){
            ListNode* temp = new ListNode();
            prev->next = temp;
            prev = temp;
            temp->val = carry;
        }
        return fin->next;
    }
};