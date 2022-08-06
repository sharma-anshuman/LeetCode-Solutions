class Solution {
public:
    vector<vector<string>> fin;    

    bool canPlace(int x, int y, vector<int> row, vector<int> col, vector<string> grid){
        if(row[x] || col[y]) return false;
        int i = x-1, j = y+1;
        while(i>=0 && j!=grid.size()){
            if(grid[i][j] == 'Q'){
                return false;
            }
            i--, j++;
        }
        i = x+1, j = y-1;
        while(i!=grid.size() && j>=0){
            if(grid[i][j] == 'Q'){
                return false;
            }
            i++, j--;
        }
        i = x+1, j = y+1;
        while(i!=grid.size() && j!=grid.size()){
            if(grid[i][j] == 'Q'){
                return false;
            }
            i++, j++;
        }
        i = x-1, j = y-1;
        while(i>=0 && j>=0){
            if(grid[i][j] == 'Q'){
                return false;
            }
            i--, j--;
        }
        return true;
    }
    
//     bool isSafe(vector<string> grid){
        
//     }
    
    void solve(int n, vector<string> &grid, int x, vector<int> &row, vector<int> &col){
        if(x == n){
            fin.emplace_back(grid);
            return;
        }
        
        for(int i = 0; i<n; i++){
            if(canPlace(x, i, row, col, grid)){
                row[x] = 1, col[i] = 1, grid[x][i] = 'Q';
                solve(n, grid, x+1, row, col);
                row[x] = 0, col[i] = 0, grid[x][i] = '.';
            }
        }
        return;
    }
    
    vector<vector<string>> solveNQueens(int n) {
        string s = "";
        for(int i = 0; i<n; i++) s+='.';
        vector<string> grid(n);
        for(int i = 0; i<n; i++) grid[i] = s;
        vector<int> row(n, 0), col(n, 0);
        solve(n, grid, 0, row, col);
        return fin;
    }
};