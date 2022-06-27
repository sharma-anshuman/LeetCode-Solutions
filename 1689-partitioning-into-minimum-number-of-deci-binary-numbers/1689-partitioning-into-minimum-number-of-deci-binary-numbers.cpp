class Solution {
public:
    int minPartitions(string n) {
        char mx = '0';
        for(int i = 0; i<n.size(); i++){
            if(n[i]>mx){
                mx = n[i];
            }
        }
        return mx-'0';
    }
};