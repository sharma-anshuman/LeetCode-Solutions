class Solution {
public:
    int dp[20000][100];
    int solve(vector<int> &coins,int amount,int n){
        if(n==0) return INT_MAX-1;
        if(amount==0) return 0;
        if(dp[amount][n]!=-1) return dp[amount][n];
        if(amount<coins[n-1]) return dp[amount][n]=solve(coins,amount,n-1);
        return dp[amount][n]=min({1+solve(coins,amount-coins[n-1],n),solve(coins,amount,n-1)});
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(dp,-1,sizeof(dp));
        return solve(coins,amount,size(coins))==INT_MAX-1?-1:solve(coins,amount,size(coins));
    }
};