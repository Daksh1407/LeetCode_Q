//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int getSum(int n) {
        int sum = 0;
        
        while(n != 0) {
            sum += n % 10;
            n /= 10;
        }
        
        return sum;
    }
    int isPossible(int n, int arr[]) {
        int s = 0;
        
        for(int i = 0; i < n; i++) {
            int sum = getSum(arr[i]);
            
            s += sum;
        }
        if(s % 3 == 0)
            return 1;
        else
            return 0;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution ob;
        cout << ob.isPossible(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends