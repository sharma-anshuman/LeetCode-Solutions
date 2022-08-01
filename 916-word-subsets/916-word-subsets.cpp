class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> mxFreq(26, 0);
        for(int i = 0; i<words2.size(); i++){
            string s = words2[i];
            vector<int> freq(26, 0);
            for(int j = 0; j<s.size(); j++){
                freq[s[j] - 'a']++;
                mxFreq[s[j] - 'a'] = max(mxFreq[s[j] - 'a'], freq[s[j] - 'a']);
            }
        }
        
        vector<string> ans;
        for(int i = 0; i<words1.size(); i++){
            vector<int> freq(26, 0);
            string s = words1[i];
            for(int j = 0; j<s.size(); j++){
                freq[s[j] - 'a']++;
            }
            
            bool flag = true;
            for(int j = 0; j<26; j++){
                if(mxFreq[j]>freq[j]) flag = false;
            }
            if(flag) ans.emplace_back(words1[i]);
        }
        return ans;
    }
};