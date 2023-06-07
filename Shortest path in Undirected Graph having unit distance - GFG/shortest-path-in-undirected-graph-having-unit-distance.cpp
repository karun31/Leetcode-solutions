//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        vector<vector<int>> adj(N);
        for(int i = 0; i < M; i++){
            int f = edges[i][0];
            int s = edges[i][1];
            adj[f].push_back(s);
            adj[s].push_back(f);
        }
        
        
        int dist = 0;
        queue<int> pending;
        pending.push(src);
        vector<int> ans(N,-1);
        ans[src] = 0;
        while(!pending.empty()){
            int k = pending.size();
            dist++;
            while(k--){
                int node = pending.front();
                pending.pop();
                for(auto adjVertex : adj[node]){
                    if(ans[adjVertex] == -1){
                        ans[adjVertex] = dist;
                        pending.push(adjVertex);
                    }
                }
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends