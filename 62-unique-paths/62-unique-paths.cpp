class Solution {
public:
    
    
    int uniquePaths(int n, int m){
        vector<vector<int>> arr(n, vector<int>(m, 0));
        // arr[n-1][m-1] = 1;
        for(int i = n-1; i>=0; i--){
            for(int j = m-1; j>=0; j--){
                if(i<n-1 && j<m-1) arr[i][j] = arr[i+1][j]+arr[i][j+1];
                else if(i == n-1 && j<m-1) arr[i][j] = arr[i][j+1];
                else if(j == m-1 && i<n-1) arr[i][j] = arr[i+1][j];
                else arr[i][j] = 1;
            }
        }
        return arr[0][0];
    }
};