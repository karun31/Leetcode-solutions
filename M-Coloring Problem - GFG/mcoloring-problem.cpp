//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool isPossible(bool graph[101][101], int m, int n, vector<int>& colors, int node, int color){
        for(int k = 0; k < n; k++){
            if(k != node && graph[node][k] == 1 && colors[k] == color){
                return false;
            }
        }
        return true;
    }
    
    bool helper(bool graph[101][101], int m, int n, vector<int>& colors, int node){
        if(node == n){
            return true;
        }
        for(int i = 1; i <= m; i++){
            if(isPossible(graph,m,n,colors,node,i)){
                colors[node] = i;
                bool smallAns = helper(graph, m, n, colors, node+1);
                if(smallAns == true){
                    return true;
                }
                colors[node] = 0;
            }
        }
        return false;
    }
    
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        vector<int> colors(n,0);
        return helper(graph,m,n,colors,0);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends