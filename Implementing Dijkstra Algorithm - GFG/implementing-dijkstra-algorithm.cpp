//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int n, vector<vector<int>> adj[], int s)
    {
        // Code here
        
        vector<vector<int>> mat(n,vector<int>(n,0));
        for(int i = 0; i < n; i++){
            // for(auto adjVertex_weights = adj[i]){
            //     int v = adjVertex_weights[0];
            //     int w = adjVertex_weights[1];
            //     mat[i][v] = w;
            // }
            for(int j = 0; j < adj[i].size(); j++){
                vector<int> temp = adj[i][j];
                int x = i;
                int y = temp[0];
                int w = temp[1];
                mat[x][y] = w;
            }
        }
        vector<int> distances(n,INT_MAX);
    set<pair<int,int>> pending;
    distances[s] = 0;
    pending.insert({0,s});
    while(!pending.empty()){
        auto front = *pending.begin();
        int dis = front.first;
        int node = front.second;
        pending.erase(pending.begin());
        for(int i = 0; i < n; i++){
            if(mat[node][i] != 0){
                int currD = distances[i];
                int disFromNode = dis + mat[node][i];
                if(disFromNode < currD){
                    auto record = pending.find({currD,i});
                    if(record != pending.end()){
                        pending.erase(record);
                    }
                    distances[i] = disFromNode;
                    pending.insert({distances[i],i});
                }
            }
        }
    }
    return distances;
    }
    
    
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends