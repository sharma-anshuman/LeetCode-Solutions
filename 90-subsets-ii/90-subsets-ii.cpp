class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int> nums, int n, int i, vector<int> temp){
        ans.emplace_back(temp);
        for(int x = i; x<n; x++){
            if(x!=i && nums[x] == nums[x-1]) continue;
            temp.emplace_back(nums[x]);
            solve(nums, n, x+1, temp);
            temp.pop_back();
        }
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> x;
        solve(nums, nums.size(), 0, x);
        return ans;
    }
};