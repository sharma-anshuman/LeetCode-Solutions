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
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL) return head;
        ListNode *lf = NULL, *ll = NULL, *gf = NULL, *gl = NULL;
        while(head){
            if(head->val < x){
                if(lf == NULL){
                  lf = head;
                  ll = head;
                }
                else{
                    if(ll){
                    ll->next = head;
                    ll = head;
                    }
                }
            }
            else{
                if(gf == NULL){
                    gf = head;
                    gl = head;
                }
                else{
                    gl->next = head;
                    gl = head;
                }
            }
            head = head->next;
        }
        
        if(ll){
            ll->next = gf;
            if(gl) gl->next = NULL;
        }
        
        if(lf) return lf;
        else return gf;
        //return lf;
        
        
    }
    
};