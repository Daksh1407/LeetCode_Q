//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    bool ok = true;
    int closedIslands(vector<vector<int>>& matrix, int n, int m) {
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                ok = true;
                if(matrix[i][j]) {
                    func(i, j, n, m, matrix);
                    if(ok) ans++;
                }
            }
        }
        return ans;
    }
    void func(int i, int j, int n, int m, vector<vector<int>> &arr) {
        if(i < 0 || i >= n || j < 0 || j >= m || !arr[i][j]) return;
        if(i == 0 || i == n-1 || j == 0 || j == m-1) ok = false;
        
        arr[i][j] = 0;
        func(i-1, j, n, m, arr);
        func(i+1, j, n, m, arr);
        func(i, j-1, n, m, arr);
        func(i, j+1, n, m, arr);
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends