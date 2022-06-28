// { Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


 // } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    
    static bool compare(pair<int, int> p1, pair<int, int> p2){
        return p1.second > p2.second;
    }
    
    vector<int> JobScheduling(Job arr[], int n){ 
        vector<pair<int, int>> pr(n);
        for(int i = 0; i<n; i++){
            pr[i] = {arr[i].dead, arr[i].profit};
        }
        sort(pr.begin(), pr.end(), compare);
       int deadline[101];
       memset(deadline, 0, sizeof(deadline));
       int sum = 0, ans = 0, temp = 0;
        for(int i = 0; i<n; i++){
            if(deadline[pr[i].first]){
                for(int j = pr[i].first-1; j>=1; j--){
                    if(deadline[j] == 0){
                        deadline[j] = 1;
                        temp++;
                        ans+=pr[i].second;
                        break;
                    }
                }
            }
            
            else{
                deadline[pr[i].first] = 1;
                temp++;
                ans+=pr[i].second;
            }
        }
        vector<int> fin(2);
        fin[0] = temp;
        fin[1] = ans;
        return fin;
    }
};

// { Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}


  // } Driver Code Ends