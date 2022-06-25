class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int ct=0;
        for(int i = 1; i<nums.size(); i++){
            if(nums[i]<nums[i-1]){
                ct++;
                if(ct>1) return false;
                if(i == 1 || nums[i-2]<=nums[i]){
                    nums[i-1] = nums[i];
                }
                else{
                    nums[i] = nums[i-1];
                }
            }
        }
        return true;
    }
};


//1 2 3 10 5 6 7