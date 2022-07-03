class Solution {
public:
    
    int wiggleMaxLength(vector<int>& nums) {
        int arr[nums.size()-1];
        if(nums.size() == 1) return 1;
        for(int i = 1; i<nums.size(); i++){
            if(nums[i] - nums[i-1]>0) arr[i-1] = 1;
            else if(nums[i] - nums[i-1] < 0) arr[i-1] = 0;
            else arr[i-1] = -1;
        }
        int ans = 1;
        int temp = 0, last = 1;
        
        //for pos
        bool flag1 = false;
        bool flag2 = false;
        
        for(int i = 0; i<nums.size()-1; i++){
            last = 1;
            temp = 0;
            for(int j = i; j<nums.size()-1; j++){
                if(arr[j] == -1) continue;
                if(arr[j] != last){
                    flag1 = true;
                    last = arr[j];
                    temp++;
                }
            }
            ans = max(ans, temp);
        }
        
        //for neg
        temp = 0;
        for(int i = 0; i<nums.size()-1; i++){
            last = 0;
            temp = 0;
            for(int j = i; j<nums.size()-1; j++){
                if(arr[j] == -1) continue;
                if(arr[j] != last){
                    flag2 = true;
                    last = arr[j];
                    temp++;
                }
            }
            ans = max(ans, temp);
        }
        
        if(!flag1 && !flag2) return 1;
        return ans+1;
        //0 1 0 0 1 1 0 1 0
        
    }
};