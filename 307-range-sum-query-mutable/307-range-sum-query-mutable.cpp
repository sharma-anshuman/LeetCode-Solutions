class NumArray {
public:
    
    vector<int> arr;
    int n = 0, sum = 0;
    NumArray(vector<int>& nums) {
        n = nums.size();
        int temp = 0;
        for(int i = 0; i<n; i++){
            sum+=nums[i];
            arr.emplace_back(nums[i]);
        }
    }
    
    void update(int index, int val) {
        sum-=arr[index];
        arr[index] = val;
        sum+=val;
    }
    
    int sumRange(int left, int right) {
        int x = sum;
        for(int i = 0; i<left; i++) x-=arr[i];
        for(int i = right+1; i<n; i++) x-=arr[i];
        return x;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */