//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int findMoves(int n, vector<int> ch, vector<int> pass) {
        sort(ch.begin(), ch.end());
        sort(pass.begin(), pass.end());
        
        int cnt = 0;
        
        for(int i = 0; i < n; i++) {
            cnt += abs(ch[i] - pass[i]);
        }
        return cnt;
    }
    
};

/*

    2 2 6 6
    1 2 3 6
    
    
    1 3 5
    2 4 7
*/

//{ Driver Code Starts.

int main() {
    int tt;
    cin >> tt;
    Solution sol;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> chairs(n), passengers(n);
        for (auto &val : chairs) cin >> val;
        for (auto &val : passengers) cin >> val;
        int ans = sol.findMoves(n, chairs, passengers);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends