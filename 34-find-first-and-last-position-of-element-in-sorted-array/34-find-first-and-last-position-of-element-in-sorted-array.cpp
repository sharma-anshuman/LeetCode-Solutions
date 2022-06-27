class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> arr(2);
        arr[0] = arr[1] = -1;
        int x = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        if(x<nums.size() && nums[x] == target){
            arr[0] = x;
            arr[1] = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
            arr[1] = max(x, arr[1]-1);
        }
        return arr;
        
    }
};