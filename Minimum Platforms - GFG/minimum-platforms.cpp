// { Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    static bool compare(pair<int, int> m1, pair<int, int> m2){
        return m1.second<m2.second;
    }
    int findPlatform(int arr[], int dep[], int n)
    {
    	vector<pair<int, int>> train;
    	for(int i = 0; i<n; i++){
    	    train.push_back({arr[i], dep[i]});
    	}
    	sort(train.begin(), train.end(), compare);
    // 	for(int i = 0; i<n; i++){
    // 	    cout<<train[i].first<<' '<<train[i].second<<endl;
    // 	}
    	vector<int> last;
    	last.push_back(-1);
    	int mx = 0;
    	for(int i = 0; i<n; i++){
    	    
    	        bool flag = true;
    	        for(int k = last.size()-1; k>=0; k--){
    	            if(train[i].first>last[k]){
    	                last[k] = train[i].second;
    	                sort(last.begin(), last.end());
    	                flag = false;
    	                break;
    	            }
    	        }
    	        if(flag){
    	            mx++;
    	            last.push_back(train[i].second);
    	        }
    	        
    	   
    	}
    	return last.size();
    }
};


// { Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}  // } Driver Code Ends