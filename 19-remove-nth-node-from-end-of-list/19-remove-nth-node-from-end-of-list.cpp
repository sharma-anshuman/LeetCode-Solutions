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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int x = 0;
        ListNode* temp = head;
        while(temp){
            x++;
            temp = temp->next;
            
        }
        n = x-n+1;
        x = 0;
        temp = head;
        if(n == 1){
            return head->next;
        }
        while(x<n){
            x++;
            if(x == n-1){
                temp->next = temp->next->next;
                break;
            }
            temp = temp->next;
        }
        return head;
    }
};