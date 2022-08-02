class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(), m = matrix[0].size();
        int arr[n*m], x = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                arr[x++] = matrix[i][j];
            }
        }
        sort(arr, arr+(n*m));
        return arr[k-1];
    }
};