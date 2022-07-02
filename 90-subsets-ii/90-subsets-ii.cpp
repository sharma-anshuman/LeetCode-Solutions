class Solution {
public:
    set<vector<int>> ans;
    void solve(vector<int> nums, int n, int i, vector<int> temp){
        if(i == n){
            sort(temp.begin(), temp.end());
            ans.insert(temp);
            return;
        }
        temp.emplace_back(nums[i]);
        solve(nums, n, i+1, temp);
        temp.pop_back();
        solve(nums, n, i+1, temp);
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> x;
        solve(nums, nums.size(), 0, x);
        vector<vector<int>> fin;
        for(auto i: ans){
            fin.push_back(i);
        }
        return fin;
    }
};