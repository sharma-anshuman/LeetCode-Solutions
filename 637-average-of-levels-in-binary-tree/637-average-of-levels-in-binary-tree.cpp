/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> arr;
        TreeNode* nul = NULL;
        queue<TreeNode*> qu;
        qu.push(root);
        qu.push(nul);
        double x = 0, sum = 0;
        while(!qu.empty()){
            if(qu.front() == NULL){
                arr.emplace_back(sum/x);
                qu.pop();
                if(!qu.empty()) qu.push(nul);
                sum = 0, x = 0;
                continue;
            }
            sum+=(qu.front()->val);
            if(qu.front()->left) qu.push(qu.front()->left);
            if(qu.front()->right) qu.push(qu.front()->right);
            qu.pop(), x++;
        }
        return arr;
    }
};