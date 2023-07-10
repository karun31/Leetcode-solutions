//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<vector<int>> mat(V,vector<int>(V,-1));
        for(int i = 0; i < V; i++){
            vector<vector<int>> temp = adj[i];
            for(int j = 0; j < temp.size(); j++){
                int s = temp[j][0];
                int w = temp[j][1];
                mat[i][s] = w;
                mat[s][i] = w;
            }
        }
        
        vector<int> distances(V,INT_MAX);
        set<pair<int,int>> mySet;
        distances[S] = 0;
        mySet.insert({0,S});
        while(!mySet.empty()){
            auto front = *mySet.begin();
            mySet.erase(front);
            int dis = front.first;
            int node = front.second;
            for(int i = 0; i < V; i++){
                if(mat[node][i] != -1){
                    int disFromNode = dis + mat[node][i];
                    int currDis = distances[i];
                    if(disFromNode < currDis){
                        auto record = mySet.find({currDis,i});
                        if(record != mySet.end()){
                            mySet.erase(record);
                        }
                        distances[i] = disFromNode;
                        mySet.insert({distances[i],i});
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