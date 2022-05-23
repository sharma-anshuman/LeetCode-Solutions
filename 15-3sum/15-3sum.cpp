class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i<n-2; i++){
           int target = (-1)*nums[i];
           int l = i+1, h = n-1;
           while(l<h){
               if(nums[l] + nums[h] == target){
                   vector<int> xy(3);
                   xy[0] = nums[i], xy[1] = nums[l], xy[2] = nums[h];
                   ans.push_back(xy);
                   while(l<h && nums[l]==nums[l+1]) l++;
                   while(h>l && nums[h]==nums[h-1]) h--;
                   l++, h--;
               }
               else if(nums[l]+nums[h] < target) l++;
               else h--;
           }
            while(i < n-2 && nums[i] == nums[i+1]){
                i++;
            }
        }
        return ans;
    }
};