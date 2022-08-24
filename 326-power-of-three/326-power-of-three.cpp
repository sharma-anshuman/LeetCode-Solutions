class Solution {
public:
    bool isPowerOfThree(int n) {
        // if(!n) return false;
        // if(n==1) return true;
        return n>0 && 1162261467%n==0;
    }
};