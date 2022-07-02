// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	
	
	
	int minCoins(int coins[], int n, int V){ 
	    int table[V+1];
	    for(int i = 0; i<V+1; i++){
	        table[i] = INT_MAX;
	    }
	    table[0] = 0;
	    for(int i = 1; i<=V; i++){
	        for(int j = 0; j<n; j++){
	            if(coins[j] <= i){
	                int sub_res = table[i - coins[j]];
	                if(sub_res!=INT_MAX && sub_res+1<table[i]){
	                    table[i] = sub_res + 1;
	                }
	            }
	        }
	    }
	    if(table[V] == INT_MAX){
	        return -1;
	    }
	    return table[V];
	} 
	  
};

// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends