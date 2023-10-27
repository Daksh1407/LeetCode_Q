//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
public:
    int palindrome(string s) {
        int n = s.length();
        string t = s;
        reverse(t.begin(), t.end());
        
        int dp[n + 1][n + 1];
        
        for(int i = 0; i < n + 1; i++) {
            for(int j = 0; j < n + 1; j++) {
                if(i == 0 || j == 0)
                    dp[i][j] = 0;
            }
        }
        
        for(int i = 1; i < n + 1; i++) {
            for(int j = 1; j < n + 1; j++) {
                if(s[i - 1] == t[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        
        return dp[n][n];
    }
    int minimumNumberOfDeletions(string s) { 
        // code here
        int n = s.length();
        int len = palindrome(s);
        
        return n - len;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string S;
        cin >> S;
        Solution obj;
        cout << obj.minimumNumberOfDeletions(S) << endl;
    }
    return 0;
}
// } Driver Code Ends