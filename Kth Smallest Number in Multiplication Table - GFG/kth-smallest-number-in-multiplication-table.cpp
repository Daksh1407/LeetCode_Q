//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int KthSmallest(int m, int n, int k) {
        //Write your code here
        int l=1,h=m*n,ans=0;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            int cnt=0;
            int i=m,j=1;
            while(i>=1 && j<=n)
            {
                if(i*j <= mid)
                {
                    cnt=cnt+i;
                    j++;
                }
                else
                 i--;
            }
            if(cnt >=k)
            {
                ans=mid;
                h=mid-1;
            }
            else
             l=mid+1;
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int m, n, k;
	    cin >> m >> n >> k;
	    Solution ob;
	    int ans = ob.KthSmallest(m, n, k);
	    cout << ans << endl;
	}
	return 0;
}

// } Driver Code Ends