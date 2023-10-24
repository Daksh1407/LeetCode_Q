//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool check(string s, int i, int j) {
        while(i <= j) {
            if(s[i] != s[j])
                return false;
            else {
                i++;
                j--;
            }
        }
        
        return true;
    }
    
    //int dp[501][501];
    
    int solve(string str, int i, int j, vector<vector<int>>&dp) {
        int n = str.length();
        
        if(j == n - 1) {
            if(check(str, i, j))
                return 0;
            else
                return INT_MAX;
        }
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int cut = INT_MAX;
        int notcut = INT_MAX;
        if(check(str, i, j))
            cut = 1 + solve(str, j + 1, j + 1, dp);
        
        notcut = solve(str, i, j + 1, dp);
        dp[i][j] = min(cut, notcut);
        
        return dp[i][j];
    }
    
    int palindromicPartition(string s) {
        int n = s.length();
        int i = 0;
        int j = n - 1;
        vector<vector<int>>dp(n, vector<int>(n, -1));
        
        //memset(dp, -1, sizeof(dp));
        
        return solve(s, 0, 0, dp);
        // code here
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends