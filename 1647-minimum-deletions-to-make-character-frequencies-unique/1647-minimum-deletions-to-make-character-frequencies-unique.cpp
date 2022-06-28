class Solution {
public:
    int minDeletions(string s) {
       unordered_map<char, int> arr;
        for(int i = 0; i<s.size(); i++){
            arr[s[i]]++;
        }
        int ans = 0;
        for(char x = 'a'; x<='z'; x++){
            int freq = arr[x];
            for(char p = 'a'; freq && p<='z'; p++){
                if(p!=x && freq && arr[p] == freq){
                    ans++;
                    freq--;
                    arr[x]--;
                    p = 'a';
                    p--;
                }
            }
        }
        return ans;
    }
};