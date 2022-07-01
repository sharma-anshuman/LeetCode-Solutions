class Solution {
public:
    static bool comp(pair<int, int> m1, pair<int, int> m2){
        return m1.first>m2.first;
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n = boxTypes.size();
        vector<pair<int, int>> arr(n);
        for(int i = 0; i<n; i++){
            arr[i] = {boxTypes[i][1], boxTypes[i][0]};
        }
        sort(arr.begin(), arr.end(), comp);
        int ans = 0;
        for(int i = 0; truckSize && i<n; i++){
            if(arr[i].second > truckSize){
                ans+=(truckSize*arr[i].first);
                truckSize = 0;
                break;
            }
            ans+=(arr[i].first*arr[i].second);
            truckSize-=arr[i].second;
        }
        return ans;
    }
};