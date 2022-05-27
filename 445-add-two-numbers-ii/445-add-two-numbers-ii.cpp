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
    int carry = 0;
    ListNode* solve(ListNode* x, ListNode* y){
        if(x->next){
            solve(x->next, y->next);
        }
        int sum = (x->val+y->val+carry);
        y->val = sum%10;
        carry = (sum)/10;
        return y;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1=0, len2=0;
        ListNode* l1c = l1, *l2c = l2;
        ListNode* ans;
        while(l1c){
            len1++, l1c = l1c->next;
        }while(l2c){
            len2++, l2c = l2c->next;
        }
        int diff = abs(len1-len2);
        if(len1<len2){
            ListNode* prev = l1;
            while(diff--){
                ListNode* currH = new ListNode(0);
                currH->next = prev;
                prev = currH;
                
            }
            ans = solve(prev, l2);
        }
        else if(len2<len1){
            ListNode* prev = l2;
            while(diff--){
                ListNode* currH = new ListNode(0);
                currH->next = prev;
                prev = currH;
            }
            ans = solve(prev, l1);
        }
        else{
            ans = solve(l1, l2);
        }
        if(carry){
            ListNode* fin = new ListNode(carry);
            fin->next = ans;
            ans = fin;
        }
        return ans;
    }
};