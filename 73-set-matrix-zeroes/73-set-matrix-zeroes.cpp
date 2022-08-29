class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int row[n], col[m];
        memset(row, -1, sizeof(row));
        memset(col, -1, sizeof(col));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(!matrix[i][j]){
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(row[i] == 1 || col[j] == 1){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};