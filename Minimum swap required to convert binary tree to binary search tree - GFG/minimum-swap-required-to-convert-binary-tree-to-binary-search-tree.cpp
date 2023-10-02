//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
  public:
  vector<int> in;
void dfs(vector<int> &nums,int i)
{
    if(i>=nums.size())  return ;
    dfs(nums,2*i+1);
    in.push_back(nums[i]);
    dfs(nums,2*i+2);
    return ;
}
int minSwaps(vector<int>&A, int n)
{
    dfs(A,0);
    vector<pair<int,int>> temp;
    for(int i=0;i<n;i++)
        temp.push_back({in[i],i});
    sort(temp.begin(),temp.end());
    int swap_cnt=0;
    for(int i=0;i<n;i++)
    {
        if(temp[i].second==i) continue;
        while(temp[i].second!=i)
        {
            swap(temp[i],temp[temp[i].second]);
            swap_cnt++;
        }
    }
    return swap_cnt;
}
    
    
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<int>A(n);
	    for(int i = 0 ; i < n; i++){
	        cin >> A[i];
	    }
	    Solution ob;
	    int ans = ob.minSwaps(A, n);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends