//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    long long maxDiamonds(int arr[], int n, int k) {
        long long int cnt = 0;
        priority_queue<int>pq(arr, arr + n);
        
        while (k--) {
            int top = pq.top();
            pq.pop();
            cnt += top;
            pq.push(top / 2);
        }
        return cnt;
    }
};

/*
    1 2 2 4 7
    1 2 2 4 3
    1 2 2 2 3
*/

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        
        cin>>N>>K;
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.maxDiamonds(A,N,K) << endl;
    }
    return 0;
}
// } Driver Code Ends