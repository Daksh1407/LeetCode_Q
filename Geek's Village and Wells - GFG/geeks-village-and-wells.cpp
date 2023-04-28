//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<vector<int>> chefAndWells(int n,int m,vector<vector<char>> &c){
        vector<vector<int>>distance(n, vector<int>(m, 0));
        vector<vector<int>>visited(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>>q;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(c[i][j] == 'W') {
                    visited[i][j] = 1;
                    q.push({{i, j}, 0});
                }
            }
        }
        int rows[]={0, 0, 1, -1};
        int cols[]={1, -1, 0, 0};
        while(!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dist = q.front().second;
            q.pop();
            // visited[row][col]=1;
            for(int i = 0; i < 4; i++) {
                int nr = row + rows[i];
                int nc = col + cols[i];
                if(nr >= 0 && nc >= 0 && nr < n && nc < m && (c[nr][nc] == 'H' || c[nr][nc] == '.') && visited[nr][nc] == 0) {
                    visited[nr][nc]=1;
                    distance[nr][nc]=dist+1;
                    q.push({{nr,nc},dist+1});
                }
            }
            
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(c[i][j]=='.'){
                    distance[i][j]=0;
                }
                else if(c[i][j]=='H'){
                    if(visited[i][j]==0){
                        distance[i][j]=-1;
                    }
                    else{
                        distance[i][j]=distance[i][j]*2;
                    }
                }
            }
        }
        return distance;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<char>> c(n,vector<char>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>c[i][j];
            }
        }
        Solution ob;
        vector<vector<int>> res=ob.chefAndWells(n,m,c);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<res[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}
// } Driver Code Ends