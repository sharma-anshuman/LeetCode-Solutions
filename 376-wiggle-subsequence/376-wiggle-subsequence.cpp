class Solution {
public:
    
    int wiggleMaxLength(vector<int>& nums) {
        vector<int> arr;
        for(int i = 1; i<nums.size(); i++){
            int x = nums[i] - nums[i-1];
            if(x>0) arr.emplace_back(1);
            else if(x<0) arr.emplace_back(0);
        }
        //for 1 first;
        int one = 0, lst = 1, zero = 0, lst1 = 0;
        for(int i = 0; i<arr.size(); i++){
            if(arr[i] == lst){
                lst = !lst;
                one++;
            }
            if(arr[i] == lst1){
                lst1 = !lst1;
                zero++;
            }
        }
        return max(one, zero)+1;
    }
};