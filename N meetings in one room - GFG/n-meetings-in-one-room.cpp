// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    static bool compare(pair<int, int> m1, pair<int, int> m2){
       return m1.second < m2.second;
   }
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n){
        vector<pair<int, int>> arr;
        for(int i = 0; i<n; i++){
            arr.emplace_back(make_pair(start[i], end[i]));
        }
        sort(arr.begin(), arr.end(), compare);
        int ans = 0, curr = -1;
        for(int i = 0; i<n; i++){
            if(arr[i].first > curr){
                ans++;
                curr = arr[i].second;
            }
        }
        return ans;
       
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends