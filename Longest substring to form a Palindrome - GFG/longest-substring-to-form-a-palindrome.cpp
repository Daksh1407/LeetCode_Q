//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int longestSubstring(string str) {
        int n = str.size();
        vector<vector<int>> dp(n, vector<int>(26, 0));
        
        for(int i = 0; i < n; i++) {
            char ch = str[i];
            dp[i][ch - 'a']++;
        }
        
        for(int i = 1; i < n; i++)
            for(int j = 0; j < 26; j++) 
                dp[i][j] += dp[i-1][j];
              
        int res = 0;  
        for(int ch = 0; ch < 26; ch++) {
            unordered_map<int, int> start;
            unordered_map<int, int> end;
            start[0] = -1, end[0] = -1;
            for(int i = 0; i < n; i++) {
                int val = 0;
                for(int j = 0; j < 26; j++) {
                    if(j == ch) continue;
                    val |= ((dp[i][j]) % 2) << j;
                }
                if(start.find(val) == start.end()) start[val] = i;
                end[val] = i;
            }
            for(auto it: end) {
                int mask = it.first, e = it.second;
                int s = start[mask];
                int len = e - s;
                res = max(res, len);
            }
        }
        
        return res;
        // code here
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;

        Solution ob;
        cout << ob.longestSubstring(S) << endl;
    }
    return 0;
}
// } Driver Code Ends