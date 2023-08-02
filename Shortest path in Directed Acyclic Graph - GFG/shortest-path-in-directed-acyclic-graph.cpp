//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<vector<pair<int,int>>> adj(N);
        for(auto it: edges){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int> distances(N,1e9);
        distances[0] = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});
        while(!pq.empty()){
            auto front = pq.top();
            pq.pop();
            int dist = front.first, node = front.second;
            for(auto it : adj[node]){
                int adjV = it.first , wt = it.second;
                if(dist + wt < distances[adjV]){
                    distances[adjV] = dist+wt;
                    pq.push({distances[adjV],adjV});
                }
            }
        }
        for(int i = 0; i < N; i++){
            if(distances[i] == 1e9){
                distances[i] = -1;
            }
        }
        return distances;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends