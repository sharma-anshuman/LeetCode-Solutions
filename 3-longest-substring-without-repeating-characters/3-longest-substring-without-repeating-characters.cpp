class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int arr[256], n = s.size(), mx = 0, temp = 0;
        memset(arr, -1, sizeof(arr));
        for(int i = 0; i<n; i++){
            if(arr[s[i] - ' ']!=-1){
                mx = max(mx, temp);
                int x = arr[s[i] - ' '];
                temp = i - x;
                for(int k = 0; k<=x; k++){
                    if(arr[s[k] - ' ']<=x){
                      arr[s[k] - ' '] = -1;
                    }
                }
                arr[s[i] - ' '] = i;
            }
            else{
                temp++;
                arr[s[i] - ' '] = i;
            }
        }
        mx = max(mx, temp);
        return mx;
    }
};