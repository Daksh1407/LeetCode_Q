//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int s[], int e[], int n) {
        multimap<int, int>meet;
        for (int i = 0; i < n; i++) {
            meet.insert({e[i], s[i]});
        }
        
        int end_t = {INT_MIN};
        int max_meet = {0};
        
        for(auto &it : meet) {
            int end = it.first;
            int start = it.second;
            
            if(start > end_t) {
                max_meet++;
                end_t = end;
            }
        }
        
        return max_meet;
        // Your code here
    }
};

//{ Driver Code Starts.
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
}
// } Driver Code Ends