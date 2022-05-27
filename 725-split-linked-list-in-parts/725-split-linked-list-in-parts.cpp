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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* temp = head, *prev = head;
        int n = 0;
        while(temp){
            temp = temp->next;
            n++;
        }
        int x = n/k, rem = n%k;
        temp = head;
        vector<ListNode*> ans;
        for(int i = 0; i<k; i++){
            ans.push_back(temp);
            for(int j = 0; j<x; j++){
                prev = temp;
                temp = temp->next;
            }if(prev && !rem) prev->next = NULL;
            if(rem){
                rem--;
                prev = temp;
                temp = temp->next;
                prev->next = NULL;
                if(!rem) prev = NULL;
            }
            
        }
        return ans;
    }
};