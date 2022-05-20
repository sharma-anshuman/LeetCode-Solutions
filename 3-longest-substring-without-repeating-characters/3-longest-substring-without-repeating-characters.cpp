class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> arr;
        int mx = 0, l = 0, r = 0;
        for(; r<s.size(); ){
            if(arr.find(s[r]) == arr.end()){
                arr.insert(s[r]);
                if(r-l+1 > mx){
                    mx = r-l+1;
                }
                r++;
            }
            else{
                arr.erase(arr.find(s[l]));
                l++;
            }
        }
        return mx;
    }
};