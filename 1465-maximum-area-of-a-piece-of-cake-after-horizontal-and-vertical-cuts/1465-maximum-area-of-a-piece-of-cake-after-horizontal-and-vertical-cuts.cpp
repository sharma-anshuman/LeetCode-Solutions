class Solution {
public:
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
        int nHc = hc.size(), nVc = vc.size();
        //sorting horizontal and vertical cuts vector
        sort(vc.begin(), vc.end());
        sort(hc.begin(), hc.end());
        
        //assigning maximum hight as (first cut from starting boundary) hc[0] - 0
        int hMax = hc[0];
        for(int i = 1; i<nHc; i++){
            hMax = max(hMax, hc[i] - hc[i-1]);
        }
        //taking the maximum of max height till now and the legnth from last cut to the end
        hMax = max(hMax, h-hc[nHc-1]);
        
        //doing the same for vertical cuts
        int vMax = vc[0];
        for(int i = 1; i<nVc; i++){
            vMax = max(vMax, vc[i] - vc[i-1]);
        }
        vMax = max(vMax, w-vc[nVc-1]);
        const int MOD = 1e9 + 7;
        
        //taking the multiplication answer in long long so as to avoid overflow
        long long int ans = (long long)(vMax) * (long long)(hMax);
        
        //returning ans%(1e9+7)
        return (int)(ans%MOD);
    }
};