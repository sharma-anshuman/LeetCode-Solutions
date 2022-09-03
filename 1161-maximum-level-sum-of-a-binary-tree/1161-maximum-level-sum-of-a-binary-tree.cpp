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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> arr;
        arr.push(root);
        int mx = root->val, lvl = 1, x = 1;
        while(!arr.empty()){
            int n = arr.size();
            int sum = 0;
            for(int i = 0; i<n; i++){
                sum+=arr.front()->val;
                if(arr.front()->left) arr.push(arr.front()->left);
                if(arr.front()->right) arr.push(arr.front()->right);
                arr.pop();
            }
            if(sum>mx){
                mx = sum;
                lvl = x;
            }
            x++;
        }
        return lvl;
    }
};