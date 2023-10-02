//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:	
	int distinctSubsequences(string s)
	{
	    const int mod = 1000000007;
        int dp[s.length() + 1];
        dp[0] = 1;
        
        int ch[26] = {0}; // Initialize the character array to all zeros.
        
        for (int i = 1; i <= s.length(); i++) {
            int val = ch[s[i - 1] - 'a'];
            dp[i] = ((2 * dp[i - 1]) % mod) - val;
            dp[i] %= mod;
            if (dp[i] < 0) {
                dp[i] += mod; // Ensure dp[i] is non-negative
            }
            ch[s[i - 1] - 'a'] = dp[i - 1];
        }
        
        int ans = (dp[s.length()] + mod) % mod;
        
        return ans;

	    // Your code goes here
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

        Solution ob;
   		cout << ob.distinctSubsequences(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends