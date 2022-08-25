class Solution {
public:
    bool canConstruct(string x, string y) {
        int arr[26], brr[26];
        memset(arr, 0, sizeof(arr));
        memset(brr, 0, sizeof(brr));
        for(int i = 0; i<x.size(); i++) arr[x[i] - 'a']++;
        for(int i = 0; i<y.size(); i++) brr[y[i] - 'a']++;
        for(int i = 0; i<26; i++){
            if(arr[i]>brr[i]) return false;
        }
        return true;
    }
};