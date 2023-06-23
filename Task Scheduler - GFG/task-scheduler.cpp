//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int leastInterval(int n, int k, vector<char> &tasks) {
        // code here
        int mx = 0, mx_cnt = 0;
        unordered_map<char, int>mp;
        for(auto it : tasks) {
            mp[it]++;
            mx = max(mx, mp[it]);
        }
        for(auto it : mp) {
            if(it.second == mx)
                mx_cnt++;
        }
        int res = mx_cnt + (mx - 1) * (k + 1);
        return max(res, n);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<char> tasks(N);
        for (int i = 0; i < N; i++) cin >> tasks[i];

        Solution obj;
        cout << obj.leastInterval(N, K, tasks) << endl;
    }
    return 0;
}
// } Driver Code Ends