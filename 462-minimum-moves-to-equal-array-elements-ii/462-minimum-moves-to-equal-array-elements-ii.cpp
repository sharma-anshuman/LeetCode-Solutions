class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        // 1 2 9 10
        // 9+8+1 = 18
        // 8+7+1 = 16
        // 1+7+8 = 16
        sort(nums.begin(), nums.end());
        int x = n/2;
        int sum = 0;
        for(int i = 0; i<n; i++){
            sum+=(abs(nums[i] - nums[x]));
        }
        return sum;
    }
};