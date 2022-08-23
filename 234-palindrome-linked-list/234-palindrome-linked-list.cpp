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
    
    ListNode* reverse(ListNode* head){
        ListNode* curr = head, *nxt, *prev = NULL;
        while(curr){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        ListNode* temp = head, *fast = head, *slow = head;
        while(fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        slow->next = reverse(slow->next);
        slow = slow->next;
        fast = head;
        bool flag = true;
        while(slow){
            if(slow->val != fast->val){
                flag = false;
                break;
            }
            slow = slow->next;
            fast = fast->next;
        }
        return flag;
    }
};