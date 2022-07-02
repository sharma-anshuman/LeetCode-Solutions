class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int> arr, int target, int n, int i, vector<int> temp){
        if(target < 0) return;
        if(target == 0){
            ans.emplace_back(temp);
            return;
        }
        if(i == n) return;
        
        for(int x = i; x<n; x++){
            if(x!=i && arr[x] == arr[x-1]) return;
            temp.emplace_back(arr[x]);
            solve(arr, target - arr[x], n, x, temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<int> x;
        sort(arr.begin(), arr.end());
        solve(arr, target, arr.size(), 0, x);
        return ans;
    }
};