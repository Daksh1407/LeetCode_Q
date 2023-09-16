//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int findSubArraySum(int arr[], int n, int k) {
        // code here
        int prefix[n];
        prefix[0] = arr[0];
        
        for(int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + arr[i];
        }
        unordered_map<int, int>mp;
        int cnt = 0;
        
        for(int i = 0; i < n; i++) {
            if(prefix[i] == k)
                cnt++;
                
            if(mp.find(prefix[i] - k) != mp.end()) {
                cnt += mp[prefix[i] - k];
            }
            mp[prefix[i]]++;
        }
        
        return cnt;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int Arr[N];
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int k;
        cin>>k;
        Solution obj;
        cout<<obj.findSubArraySum(Arr, N, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends