// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int n = height.size();
//         int left = 0, right = n-1;
//         int i1=0, i2 = right, y = 0;
//         long long mx = 0;
//         while(left<right){
//             long long mul = min(height[left], height[right])*(right-left-1);
//             if(mul>mx){
//                 mx = mul;
//                 i1 = left, i2 = right, y = min(height[left], height[right]);
//             }
//             if(height[left]>height[right]){
//                 right--;
//             }
//             else{
//                 left++;
//             }
//         }
//         for(int i = i1+1; i<=i2-1; i++){
//             mx-=min(height[i], y);
//         }
//         int tmx = max(0, height[n-1]);
//         for(int i = n-2; i>i2; i--){
//             if(height[i]>tmx){
//                 tmx = height[i];
//             }
//         }
//         return mx;
        
        
        
//     }
// };

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int mx1[n], mx2[n];
        memset(mx1, 0, sizeof(mx1));
        memset(mx2, 0, sizeof(mx2));
        mx1[0] = height[0];
        mx2[n-1] = height[n-1];
        for(int i = 1; i<n; i++){
            mx1[i] = max(mx1[i-1], height[i]);
        }
        int k = n-2;
        for(int i = n-2; i>=0; i--){
            mx2[k] = max(mx2[k+1], height[i]);
            k--;
        }
        
        int ans = 0;
        for(int i = 1; i<n-1; i++){
            ans+=max(0, (min(mx1[i-1], mx2[i+1]) - height[i]));
            
        }
        return ans;
    }
};