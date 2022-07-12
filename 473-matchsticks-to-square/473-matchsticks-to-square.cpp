class Solution {
public:
    int a,b,c,d;
    bool flag = false;
    bool solve(vector<int>& arr, int i){
        if(!flag){
            if(i == arr.size()){
            if(!a && !b && !c && !d){ 
                flag = true;
                return true;
            }
            else return false;
        }
        
        if(arr[i]<=a){
            a-=arr[i];
            if(solve(arr, i+1)){ 
                flag = true;
                return true;
            }
            a+=arr[i];
        }
        
        if(arr[i]<=b){
            b-=arr[i];
            if(solve(arr, i+1)){ 
                flag = true;
                return true;
            }
            b+=arr[i];
        }
        
        if(arr[i]<=c){
            c-=arr[i];
            if(solve(arr, i+1)){ 
                flag = true;
                return true;
            }
            c+=arr[i];
        }
        
        if(arr[i]<=d){
            d-=arr[i];
            if(solve(arr, i+1)){ 
                flag = true;
                return true;
            }
            d+=arr[i];
        }
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if(sum%4 || matchsticks.size()<4) return false;
        sum/=4;
        a = sum, b = sum, c = sum, d = sum;
        sort(matchsticks.rbegin(), matchsticks.rend());
        return solve(matchsticks, 0);
    }
};