/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL){
            return head;
        }
        Node* temp = head;
        Node* copy = new Node(head->val);
        unordered_map<Node*, int> mp;
        vector<Node*> arr;
        Node* prev = copy;
        arr.emplace_back(copy);
        temp = temp->next;
        int n = 2;
        mp[head] = 1;
        while(temp){
            Node* x = new Node(temp->val);
            mp[temp] = n++; 
            prev->next = x;
            prev = x;
            arr.emplace_back(x);
            temp = temp->next;
        }
        Node* temppp = NULL;
        arr.emplace_back(temppp);
        mp[NULL] = n;
        unordered_map<Node* , int> cpyMp;
        temp = head;
        while(temp){
            cpyMp[temp] = mp[temp->random];
            temp = temp->next;
        }
        temp = head;
        prev = copy;
        while(temp){
            prev->random = arr[cpyMp[temp] - 1];
            prev = prev->next;
            temp = temp->next;
        }
        return copy;
    }
};