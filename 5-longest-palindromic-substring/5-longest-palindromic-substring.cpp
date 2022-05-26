class Solution {
public:
    string longestPalindrome(string s) {
        int mx = 1, temp=0, n = s.size(), x = 0, y = 0;
        for(int i = 0; i<s.size(); i++){
            temp = 1;
            int l = i-1, r = i+1;
            while(l>=0 && r<n){
                if(s[l] == s[r]){
                    l--, r++;
                    temp+=2;
                    continue;
                }break;
            }
            if(temp>mx){
                x = l+1, y = r-1;
                mx = temp;
            }
        }
        for(int i = 0; i<s.size(); i++){
            temp = 0;
            int l = i, r = i+1;
            while(l>=0 && r<n){
                if(s[l] == s[r]){
                    l--, r++;
                    temp+=2;
                    continue;
                }break;
            }
            if(temp>mx){
                x = l+1, y = r-1;
                mx = temp;
            }
        }
        return s.substr(x, y-x+1);
    }
};