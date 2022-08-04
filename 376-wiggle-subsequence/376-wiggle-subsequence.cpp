class Solution {
public:
    
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        for(int i = 1; i<n; i++){
            int x = nums[i] - nums[i-1];
            if(x>0) nums[i-1] = 1;
            else if(x<0) nums[i-1] = 0;
            else nums[i-1] = 2;
        }
        int one = 0, lst = 1, zero = 0, lst1 = 0;
        for(int i = 0; i<n-1; i++){
            if(nums[i] == lst){
                lst = !lst;
                one++;
            }
            if(nums[i] == lst1){
                lst1 = !lst1;
                zero++;
            }
        }
        return max(one, zero)+1;
    }
};