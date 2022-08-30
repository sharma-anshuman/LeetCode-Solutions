class Solution {
public:
    void transpose(vector<vector<int>> &arr){
        int n = arr.size();
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                swap(arr[i][j], arr[j][i]);
            }
        }
    }
    void rev(vector<vector<int>> &arr){
        int n = arr.size();
        for(int i = 0; i<n; i++){
            reverse(arr[i].begin(), arr[i].end());
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);
        rev(matrix);
    }
};