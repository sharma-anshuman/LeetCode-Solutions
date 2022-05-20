class Solution {
public:
    int dp[101][101]{}, cnt = 0;
    int solve(vector<vector<int>>& arr, int i, int j, int n, int m){
        if(i == n-1 && j == m-1 && !arr[i][j]){
            return 1;
        }
        if(i>=n || j>=m || arr[i][j]){
            return 0;
        }
        if(dp[i][j]){
            return dp[i][j];
        }
        return dp[i][j] = solve(arr, i+1, j, n, m) + solve(arr, i, j+1, n, m);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        int ans = solve(arr, 0, 0, n, m);
        return ans;
    }
};