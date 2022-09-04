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
    vector<vector<int>> ans;
    map<TreeNode*, pair<int, int>> mp;
    
    
    void solve(TreeNode* root, int col, int row){
        if(root==NULL) return;
        solve(root->left, col-1, row+1);
        mp[root] = {col,row};
        solve(root->right, col+1, row+1);
    }
    
    static bool comp(const pair<int,pair<int, int>> &a, const pair<int,pair<int, int>> &b){
    return ((a.second.first == b.second.first && a.second.second == b.second.second && a.first<b.first) || (a.second.first < b.second.first));
}
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        solve(root, 0, 0);
        multimap<pair<int, int>, TreeNode*> arr;
        for(auto& it:mp){
            arr.insert({{it.second.first, it.second.second}, it.first});
        }
        int prev = -1001, temp = 0;
        vector<pair<int, pair<int, int>>> xy;
        for(auto&it: arr){
            if(it.first.first!=prev && temp){
                sort(xy.begin(), xy.end(), comp);
                vector<int> tmpp;
                for(int i = 0; i<xy.size(); i++){
                    tmpp.emplace_back(xy[i].first);
                }
                ans.push_back(tmpp);
                tmpp.clear();
                xy.clear();
                xy.emplace_back(it.second->val, make_pair(it.first.second, it.first.first));
                prev = it.first.first;
            }
            else{
                prev = it.first.first;
                xy.emplace_back(it.second->val, make_pair(it.first.second, it.first.first));
            }
            temp++;
        }
        //sort(xy.begin(), xy.end());
        sort(xy.begin(), xy.end(), comp);
                vector<int> tmpp;
                for(int i = 0; i<xy.size(); i++){
                    tmpp.emplace_back(xy[i].first);
                }
                ans.push_back(tmpp);
        return ans;
    }
};