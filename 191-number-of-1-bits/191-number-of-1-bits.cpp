class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ct =0;
        while(n){
            n&=(n-1), ct++;
        }return ct;
    }
};