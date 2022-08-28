class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        for(int i = n-1; i>=0; i--){
            vector<int> x;
            int a = i, b = 0;
            while(a<=n-1 && b<=m-1){
                x.emplace_back(mat[a++][b++]);
            }
            sort(x.begin(), x.end());
            a = i, b = 0;
            while(a<=n-1 && b<=m-1){
                mat[a][b] = x[b];
                a++, b++;
            }
        }
        
        for(int i = 1; i<m; i++){
            vector<int> x;
            int a = 0, b = i;
            while(a<=n-1 && b<=m-1){
                x.emplace_back(mat[a++][b++]);
            }
            sort(x.begin(), x.end());
            a = 0, b = i;
            while(a<=n-1 && b<=m-1){
                mat[a][b] = x[a];
                a++, b++;
            }
        }
        return mat;
    }
};