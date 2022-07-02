class Solution {
public:
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
        int nHc = hc.size(), nVc = vc.size();
        sort(vc.begin(), vc.end());
        sort(hc.begin(), hc.end());
        int hMax = hc[0];
        for(int i = 1; i<nHc; i++){
            hMax = max(hMax, hc[i] - hc[i-1]);
        }
        hMax = max(hMax, h-hc[nHc-1]);
        
        int vMax = vc[0];
        for(int i = 1; i<nVc; i++){
            vMax = max(vMax, vc[i] - vc[i-1]);
        }
        vMax = max(vMax, w-vc[nVc-1]);
        //cout<<hMax<<' '<<vMax<<endl;
        const int MOD = 1e9 + 7;
        long long int ans = (long long)(vMax) * (long long)(hMax);
        return (int)(ans%MOD);
    }
};