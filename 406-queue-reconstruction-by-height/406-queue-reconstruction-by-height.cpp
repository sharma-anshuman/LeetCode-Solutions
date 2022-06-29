class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n = people.size();
        vector<vector<int>> ans(n, vector<int>(2, -1));
        vector<pair<int, int>> pr(n);
        for(int i = 0; i<n; i++){
            pr[i] = {people[i][0], people[i][1]};
        }
        stable_sort(pr.begin(), pr.end());
        
        for(int i = 0; i<n; i++){
            int ct = pr[i].second;
            for(int j = 0; j<n; j++){
                if(!ct && ans[j][0] == -1 && ans[j][1] == -1){
                    ans[j][0] = pr[i].first;
                    ans[j][1] = pr[i].second;
                    break;
                }
                if(ans[j][0] == -1 && ans[j][1] == -1){
                    ct--;
                    continue;
                }
                if(ans[j][0]>=pr[i].first){
                    ct--;
                }
            }
        }
        return ans;
    }
};