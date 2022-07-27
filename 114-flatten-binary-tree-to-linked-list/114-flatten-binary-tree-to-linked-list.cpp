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
    void flatten(TreeNode* root) {
        //Node Left Right
//         if(root == NULL) return;
        
//         TreeNode* temp = NULL;
//         if(root->left!=NULL){
//             temp = root->right;
//             root->right = root->left;
//             root->left = NULL;
//             flatten(root->right);
//             flatten(temp);
//         }
//         if(root->right!=NULL){
//             temp = root->right;
//             root->right = root->left;
//             root->left = NULL;
//             flatten(root->right);
//             flatten(temp);
//         }
        if(root != NULL){
        vector<TreeNode*> arr;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            arr.push_back(st.top());
            TreeNode* temp = st.top();
            st.pop();
            if(temp->right) st.push(temp->right);
            if(temp->left) st.push(temp->left);
        }
        for(int i = 0; i<arr.size()-1; i++){
            arr[i]->right = arr[i+1];
            arr[i]->left = NULL;
        }
        
        arr[arr.size()-1]->right = NULL;
        }
    }
};