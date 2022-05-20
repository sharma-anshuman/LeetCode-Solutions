class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> arr(256, -1);
        int l = 0, r = 0, mx = 0;
        while(r<s.size()){
            if(arr[s[r]]!=-1){
                l = max(l, arr[s[r]]+1);
            }
            arr[s[r]] = r;
            mx = max(mx, r-l+1);
            r++;
        }
        return mx;
    }
};