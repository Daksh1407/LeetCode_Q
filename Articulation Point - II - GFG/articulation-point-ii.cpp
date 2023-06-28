//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void dfs(int u, int parent, int &time, vector<int> &disc, vector<int> &low, vector<bool> &vis, vector<bool> &isArticulation, vector<int> adj[])
    {
        vis[u] = true;
        int no_of_child = 0;
        time++;
        disc[u] = low[u] = time;
        for (auto v : adj[u])
        {
            if (vis[v] == false)
            {
                no_of_child++;
                dfs(v, u, time, disc, low, vis, isArticulation, adj);
                low[u] = min(low[u], low[v]);
                if (low[v] >= disc[u] && parent != -1)
                    isArticulation[u] = true;
            }
            else if (v != parent)
            {
                low[u] = min(low[u], disc[v]);
            }
        }
        if (parent == -1 && no_of_child > 1)
            isArticulation[u] = true;
    }
    vector<int> articulationPoints(int V, vector<int> adj[])
    {
        // Code here
        vector<int> ans;
        vector<bool> isArticulation(V, false);
        vector<bool> vis(V, false);
        vector<int> disc(V, -1);
        vector<int> low(V, -1);
        int time = 0;
        for (int i = 0; i < V; i++)
            if (vis[i] == false)
                dfs(i, -1, time, disc, low, vis, isArticulation, adj);
        for (int i = 0; i < V; i++)
            if (isArticulation[i] == true)
                ans.push_back(i);
        sort(ans.begin(), ans.end());
        auto it = unique(ans.begin(), ans.end());
        ans.erase(it, ans.end());
        if (ans.size() == 0)
            return {-1};
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends