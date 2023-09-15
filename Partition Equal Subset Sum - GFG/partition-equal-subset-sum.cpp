//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int getSum(int arr[], int n) {
        int sum = 0;
        
        for(int i = 0; i < n; i++)
            sum += arr[i];
            
        return sum;
    }
    int equalPartition(int n, int arr[]) {
        int sum = getSum(arr, n);
        if(sum % 2 != 0)
            return 0;
        int s = sum / 2;
        bool dp[n + 1][s + 1];
        
        for(int i = 0; i < n + 1; i++) {
            for(int j = 0; j < s + 1; j++) {
                if(i == 0)
                    dp[i][j] = 0;
                if(j == 0)
                    dp[i][j] = 1;
                if(i == 0 && j == 0)
                    dp[i][j] = 1;
            }
        }
        
        
        for(int i = 1; i < n + 1; i++) {
            for(int j = 1; j < s + 1; j++) {
                if(arr[i - 1] <= j)
                    dp[i][j] = dp[i - 1][j] or dp[i - 1][j - arr[i - 1]];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        if(dp[n][s])
            return true;
        else
            return false;
        // code here
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends