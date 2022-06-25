class Solution {
public:
    vector<vector<int>> ans;
    void genSub(vector<int> temp, vector<int> arr, int i){
        if(i == arr.size()){
            ans.push_back(temp);
            return;
        }
        genSub(temp, arr, i+1);
        temp.push_back(arr[i]);
        genSub(temp, arr, i+1);
        temp.pop_back();
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        genSub(temp, nums, 0);
        return ans;    
    }
};