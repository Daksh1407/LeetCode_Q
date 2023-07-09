//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDistinctChars (S) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends


int longestSubstrDistinctChars (string s){
    map<char, int>mp;
    int i = 0, j = 0;
    int max_len = 0;
    
    while(j < s.size()) {
        mp[s[j]]++;
        
        while(mp[s[j]] > 1) {
            mp[s[i]]--;
            i++;
        }
        
        max_len = max(max_len, j - i + 1);
        j++;
    }
    
    return max_len;
}