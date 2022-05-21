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
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<int> arr;
        ListNode* temp = head;
        int n = 0;
        while(temp){
            arr.push_back(temp->val);
            n++;
            temp = temp->next;
        }
        for(int i = 0; i<=n-k; i+=k){
            reverse(arr.begin()+i, arr.begin()+i+k);
        }
        temp = head;
        int i = 0;
        while(temp){
            temp->val = arr[i];
            i++;
            temp = temp->next;
        }
        return head;
    }
};