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
        ListNode* prev = NULL;
        ListNode* nxt;
        while(head!=NULL){
            nxt = head->next;
            head->next = prev;
            prev = head;
            head = nxt;
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right) return head;
        int x = 0;
        ListNode* headcpy = head;
        ListNode* prev = headcpy;
        while(x!=left-1){
          prev = headcpy;
          headcpy = headcpy->next;
          x+=1;
        }
        
        ListNode* newHead = headcpy;
        x = left;
        ListNode* lastNode = new ListNode();
        while(x!=right){
            headcpy = headcpy->next;
            x+=1;
        }
        lastNode = headcpy->next;
        headcpy->next = NULL;
        ListNode* finHead = reverse(newHead);
        ListNode* finCpy = finHead;
        while(finCpy->next){
            finCpy = finCpy->next;
        }
        
        if(left == 1){
            head = finHead;
        }
        else{
        prev->next = finHead;
        }
        finCpy->next = lastNode;
        return head;
        
    }
};