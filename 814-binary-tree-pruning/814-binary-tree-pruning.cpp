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
    
    void solve(TreeNode* root){
        if(!root) return;
        solve(root->left);
        solve(root->right);
        if(root->left == NULL && root->right == NULL && root->val == 0){
            root->val = -1;
            return;
        }
        if(root->left && root->left->val == -1 && root->right && root->right->val == -1 && root->val == 0){
            root->val = -1;
            return;
        }
        if(root->left == NULL && root->right && root->right->val == -1 && root->val == 0){
            root->val = -1;
            return;
        } 
        if(root->right == NULL && root->left && root->left->val == -1 && root->val == 0){
            root->val = -1;
            return;
        }
    }
    
    void del(TreeNode* root){
        if(!root) return;
        if(root->left && root->left->val == -1){
            root->left = NULL;
        } 
        if(root->right && root->right->val == -1){
            root->right = NULL;
        }
        del(root->left);
        del(root->right);
    }
   
    
    TreeNode* pruneTree(TreeNode* root) {
      if(!root) return root;
        solve(root);
        del(root);
        if(root->val == -1) return NULL;
        return root;
    }
};