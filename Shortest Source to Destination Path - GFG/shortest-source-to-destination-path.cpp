//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
    // direction vectors for left , right , up and down 
    int row[4] = {1, -1, 0, 0};
    int col[4] = {0, 0, 1, -1};
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
        N = A.size();
        M = A[0].size();
        if (!A[0][0] || !A[X][Y]) return -1;
        if (X == 0 && Y == 0) return 0;
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{0, 0}});
        A[0][0] = -1;
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second.first;
            int d = q.front().second.second;
            q.pop();
            if (r == X && c == Y) return d;
            for (int k = 0; k < 4; k++) {
                int nr = r + row[k];
                int nc = c + col[k];
                if (nr >= 0 && nc >= 0 && nr < N && nc < M && A[nr][nc] == 1) {
                    A[nr][nc] = -1;
                    q.push({nr, {nc, d + 1}});
                }
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends