class Solution {
public:
    int numberOfSteps(int num) {
        int n = 0;
        while(num){
            if(num%2) num--;
            else num/=2;
            n++;
        }return n;
    }
};