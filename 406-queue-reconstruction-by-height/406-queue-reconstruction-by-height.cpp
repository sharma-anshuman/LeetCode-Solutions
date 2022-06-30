class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
       int n = people.size();
        vector<vector<int>> ans(n, vector<int>(2, -1));
        vector<pair<int, int>> arr(n);
        for(int i = 0; i<n; i++){
            arr[i] = {people[i][0], people[i][1]};
        }
        stable_sort(arr.begin(), arr.end());
        
        for(int i = 0; i<n; i++){
            int freq = arr[i].second;
            for(int j = 0; j<n; j++){
                if(freq == 0 && ans[j][0] == -1){
                    ans[j][0] = arr[i].first;
                    ans[j][1] = arr[i].second;
                    break;
                }
                if((ans[j][0] == -1) || ans[j][0]>=arr[i].first){
                    freq--;
                    continue;
                }
            }
        }
        return ans;
    }
};


    // 4 4     5 0     5 0     5 0     5 0    -1 -1
    // 5 0     5 2     6 1     7 0     7 0    -1 -1
    // 5 2     6 1     5 2     6 1     5 2    -1 -1
    // 6 1     7 0     7 0     5 2     6 1    -1 -1
    // 7 0     4 4     4 4     4 4     4 4    -1 -1
    // 7 1     7 1     7 1     7 1     7 1    -1 -1