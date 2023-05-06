//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    bool makeChanges(int n , int k , int sum , vector<int> &coins) {
        bool dp[k + 1][sum + 1];
        
        for (int i = 0; i < k + 1; i++) {
            for (int j = 0; j < sum + 1; j++) {
                //if (i == 0 || j == 0)
                    dp[i][j] = 0;
            }
        }
        dp[0][0] = 1;
        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < k + 1; j++) {
                for (int k = coins[i - 1]; k < sum + 1; k++) {
                    dp[j][k] = dp[j][k] || dp[j - 1][k - coins[i - 1]];
                }
            }
        }
        return dp[k][sum];
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int N;
        scanf("%d", &N);

        int K;
        scanf("%d", &K);

        int target;
        scanf("%d", &target);

        vector<int> coins(N);
        Array::input(coins, N);

        Solution obj;
        bool res = obj.makeChanges(N, K, target, coins);

        cout << res << endl;
    }
}

// } Driver Code Ends