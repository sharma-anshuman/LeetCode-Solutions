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
    string fin = "";
    
    void answer(TreeNode* root){
        if(root == NULL) return;
        string tmp = to_string(root->val);
        if(root->left == NULL && root->right == NULL){
            fin+=tmp;
            return;
        }
        if(root->right == NULL){
            fin+=tmp;
            fin+='(';
            answer(root->left);
            fin+=')';
            return;
        }
        if(root->left == NULL){
            fin+=tmp;
            fin+="()(";
            answer(root->right);
            fin+=')';
            return;
        }
        if(root->right && root->left){
            fin+=tmp;
            fin+='(';
            answer(root->left);
            fin+=")(";
            answer(root->right);
            fin+=')';
            return;
        }
    }
    string tree2str(TreeNode* root) {
        answer(root);
        return fin;
    }
};