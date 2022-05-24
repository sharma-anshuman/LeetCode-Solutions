class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int mx = 0, temp = 0;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] == 1){
                temp++;
            }
            else{
               mx = max(temp, mx);
                temp = 0;
            }
        }
        
        return max(temp, mx);
    }
};