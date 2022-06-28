class Solution {
public:
    int minDeletions(string s) {
        int arr[26];
        int n = s.size();
        memset(arr, 0, sizeof(arr));
        for(int i = 0; i<n; i++){
            arr[s[i] - 'a']++;
        }
        int ct[n+1];
        memset(ct, 0, sizeof(ct));
        for(int i = 0; i<26; i++){
            ct[arr[i]]++;
        }
        int ans = 0;
        bool flag = false;
        for(int i = 0; i<26; i++){
            while(ct[arr[i]] > 1){
                flag = false;
                int x = arr[i];
                int p = 0;
                for(int k = x-1; k>=0; k--){
                    p++;
                    if(!ct[k]){
                        ct[arr[i]]--;
                        arr[i] = k;
                        ct[k] = 1;
                        flag = true;
                        ans+=p;
                        break;
                    }
                }
                if(!flag){
                  ans+=p;  
                  ct[arr[i]]--;
                } 
                
            }
        }
        return ans;
    }
};