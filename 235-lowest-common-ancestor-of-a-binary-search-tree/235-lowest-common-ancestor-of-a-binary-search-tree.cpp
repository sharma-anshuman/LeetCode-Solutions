/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        map<TreeNode*, int> m1;
        TreeNode* temp = root;
        while(temp!=p){
            if(temp->val>p->val){
                m1[temp] = 1;
                temp = temp->left;
                continue;
            }
            if(temp->val<p->val){
                m1[temp] = 1;
                temp = temp->right;
                continue;
            }
        }
        m1[temp] = 1;
        temp = root;
        TreeNode* ans = root;
        while(temp!=q){
            if(m1[temp] == 1){
                ans = temp;
            }
            if(temp->val>q->val){
                temp = temp->left;
                continue;
            }
            if(temp->val<q->val){
                temp = temp->right;
                continue;
            }
        }
        
        if(m1[temp] == 1){
            ans = temp;
        }
        
        return ans;
        
        
    }
};