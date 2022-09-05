/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<Node*> arr;
        arr.push(root);
        while(!arr.empty()){
            vector<int> tmp;
            int x = arr.size();
            for(int i = 0; i<x; i++){
                tmp.emplace_back(arr.front()->val);
                int n = arr.front()->children.size();
                for(int j = 0; j<n; j++) arr.push(arr.front()->children[j]);
                arr.pop();
            }
            ans.emplace_back(tmp);
        }
        return ans;
    }
};