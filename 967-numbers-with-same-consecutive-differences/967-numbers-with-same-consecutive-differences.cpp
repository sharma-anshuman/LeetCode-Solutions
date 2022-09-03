class Solution {
public:
    vector<int> arr;
    int toInt(string s){
        int ans = 0, n = s.size();
        for(int i = 0; i<n; i++){ ans*=10, ans+=(s[i] - '0');}
        return ans;
    }
    char st[10] = {'0','1','2','3','4','5','6','7','8','9'};
    void solve(string s, int n, int k){
        if(s.size() == n){
            arr.emplace_back(toInt(s));
            return;
        }
        for(int i = 0; i<10; i++){
            int x = s[s.size() - 1] - '0';
            if(abs(x-i) == k) solve(s+st[i], n, k);
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        string xy[] = {"1","2","3","4","5","6","7","8","9"};
        for(int i = 0; i<9; i++) solve(xy[i], n, k);
        return arr;
    }
};