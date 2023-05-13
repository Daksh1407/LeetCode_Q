//{ Driver Code Starts
#include <bits/stdc++.h>
 
using namespace std;
 

// } Driver Code Ends
class Solution{
public:
    int captainAmerica(int N, int M, vector<vector<int>> &V){
        int indegree[N+1]={0};
        queue<int> q;
        vector<int> adj[N+1];
        for(int i=0;i<M;i++){
            indegree[V[i][1]]++;
            adj[V[i][0]].push_back(V[i][1]);
        }
        int terminalNodes = 0;
        for(int i=1;i<=N && terminalNodes<2;i++){
            if(!adj[i].size())
                terminalNodes++;
            if(!indegree[i])
                q.push(i);
        }
        // if non-zero terminal Nodes
        if(terminalNodes)
            return terminalNodes==1;
        // else continue with topSort
        while(!q.empty()){
            int x=q.front();
            q.pop();
            N--;
            for(auto it:adj[x]){
                if(!--indegree[it])
                    q.push(it);
            }
        }
        return N;
    }
};

//{ Driver Code Starts.
 

int main() {
    int t;cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> v(m+1);
        for(int i=0;i<m;i++){
            int a, b;cin >> a >> b;
            v[i].push_back(a);
            v[i].push_back(b);
        }
        
        Solution obj;
        cout << obj.captainAmerica(n, m, v) << endl;
    }
 
}
// } Driver Code Ends