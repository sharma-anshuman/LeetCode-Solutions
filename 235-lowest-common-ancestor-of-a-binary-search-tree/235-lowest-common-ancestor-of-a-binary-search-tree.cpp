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
        map<int, int> m;
        TreeNode* temp = root;
        while(true){
            if(temp == p){
                m[p->val] = 1;
                break;
            }
            if(temp->val > p->val){
                m[temp->val] = 1;
                temp = temp->left;
                continue;
            }
            if(temp->val < p->val){
                m[temp->val] = 1;
                temp = temp->right;
                continue;
            }
        }temp = root;
        TreeNode* ans = root;
        while(true){
            if(temp == q){
                if(m[temp->val] == 1){
                    ans = temp;
                    break;
                }
                break;
            }
            if(temp->val > q->val){
                if(m[temp->val]){
                    ans = temp;
                }
                temp = temp->left;
                continue;
            }
            if(temp->val < q->val){
                if(m[temp->val]){
                    ans = temp;
                }
                temp = temp->right;
                continue;
            }
        }
        return ans;
        
    }
};