class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> arr;
        int l = 0, r = 0, mx = 0;
        for(; r<s.size(); ){
            if(arr[s[r]] && arr[s[r]]>l){
                l = arr[s[r]];
                arr[s[r]] = r+1;
                r++;
                continue;
            }
            
            arr[s[r]] = r+1;
            if(r-l+1>mx){
                mx = r-l+1;
            }
            r++;
        }
        return mx;
    }
};