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
    ListNode* reverseList(ListNode* present) {
        ListNode* prev = NULL;
        ListNode* nxt;
        while(present!=NULL){
            nxt = present->next;
            present->next = prev;
            prev = present;
            present = nxt;
        }
        return prev;
    }
};