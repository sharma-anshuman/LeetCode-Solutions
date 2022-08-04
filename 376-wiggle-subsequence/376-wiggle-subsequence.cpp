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
        int one = 0, lst = 1, zero = 0;
        for(int i = 0; i<arr.size(); i++){
            if(arr[i] == lst){
                lst = !lst;
                one++;
            }
        }
        lst = 0;
        for(int i = 0; i<arr.size(); i++){
            if(arr[i] == lst){
                lst = !lst;
                zero++;
            }
        }
        
        return max(one, zero)+1;
        
        //0 1 0 0 1 1 0 1 0
        
    }
};