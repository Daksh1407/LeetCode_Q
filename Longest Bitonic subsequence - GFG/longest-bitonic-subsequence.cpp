//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int LongestBitonicSequence(vector<int>nums) {
	    int n = nums.size();
	    vector<int>arr;
	    
	    for(auto i : nums)
	        arr.push_back(i);
	    vector<int>left(n , 1);
	    vector<int>right(n , 1);
	    int ans = 0;
	    
	    for(int i = 1; i < n; i++) {
	        for(int j = 0; j < i; j++) {
	            if(arr[j] < arr[i])
	                left[i] = max(left[i], 1 + left[j]);
	        }
	    }
	    
	    for(int i = n - 1; i >= 0; i--) {
	        for(int j = n - 1; j >= i; j--) {
	            if(arr[j] < arr[i])
	                right[i] = max(right[i], right[j] + 1);
	        }
	        ans = max(left[i] + right[i] - 1 ,ans);
	    }
	    return ans;
	    // code here
	}
	    
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends