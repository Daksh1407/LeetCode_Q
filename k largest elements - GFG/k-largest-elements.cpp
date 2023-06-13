//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	vector<int> kLargest(int arr[], int n, int k) {
	    vector<int>v;
	    sort(arr, arr + n);
	    
	    int i = n - 1;
	    
	    while(k--) {
	        v.push_back(arr[i]);
	        i--;
	    }
	   // for(int i = n - 1; i >= 0; i--) {
	   //     v.push_back(arr[i]);
	   // }
	    //reverse(v.begin(), v.end());
	    return v;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.kLargest(arr, n, k);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends