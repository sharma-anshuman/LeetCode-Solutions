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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL)return head;
        ListNode* temp = head, *temp2 = head->next, *x =temp, *y = temp2;
        ListNode* lst2 = new ListNode(0), *cpy = lst2, *prev = head;
        while(temp && temp->next){
            lst2->next = temp->next;
            lst2 = lst2->next;
            prev = temp;
            temp->next = temp->next->next;
            temp = temp->next;
        }
        if(lst2){
            lst2->next = NULL;
            lst2 = lst2->next;
        }
        if(temp){
        temp->next = cpy->next;
        }
        else{
            prev->next = cpy->next;
        }
        return x;
    }
};