//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    
    
    void dfsCall(int n, vector<int> adj[],vector<int>& ans, int si, vector<bool>& visited){
        visited[si] = true;
        ans.push_back(si);
        for(auto adjVertex : adj[si]){
            if(!visited[adjVertex]){
                dfsCall(n,adj,ans,adjVertex,visited);
            }
        }
    }
    
    void dfs(int n, vector<int> adj[], vector<int>& ans){
        vector<bool> visited(n,false);
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                dfsCall(n,adj,ans,i,visited);
            }
        }
    }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> ans;
        dfs(V,adj,ans);
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends