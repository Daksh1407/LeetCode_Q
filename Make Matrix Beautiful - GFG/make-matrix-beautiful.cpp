//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int> > mat, int n) {
        // code here 
        int max_val = INT_MIN;
        
        for(int i = 0; i < n; i++) {
            int rsum = 0, csum = 0;
            for(int j = 0; j < n; j++) {
                rsum += mat[i][j];
                csum += mat[j][i];
            }
            
            max_val = max(max_val, max(rsum, csum));
        }
        
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            int sum = 0;
            for(int j = 0; j < n; j++) {
                sum += mat[i][j];
            }
            cnt += (max_val - sum);
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
        int n;
        cin>>n;
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}


// } Driver Code Ends