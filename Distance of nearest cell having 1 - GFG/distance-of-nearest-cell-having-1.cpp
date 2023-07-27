//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int n = grid.size();
	    int m = grid[0].size();
	    vector<vector<int>> ans(n,vector<int>(m,0));
	    queue<pair<int,int>> q;
	    for(int i = 0; i < n; i++){
	        for(int j = 0; j < m; j++){
	            if(grid[i][j] == 1){
	                q.push({i,j});
	                
	            }
	        }
	    }
	    int steps = 0;
	    int dx[4] = {0,0,1,-1};
	    int dy[4] = {1,-1,0,0};
	    while(!q.empty()){
	        int k = q.size();
	        while(k--){
	            int x = q.front().first;
	            int y = q.front().second;
	            q.pop();
	            ans[x][y] = steps;
	            for(int i = 0; i < 4; i++){
	                int newX = x + dx[i];
	                int newY = y + dy[i];
	                if(newX >= 0 && newY >= 0 && newX < n && newY < m && grid[newX][newY] == 0){
	                    q.push({newX,newY});
	                    grid[newX][newY] = 1;
	                }
	            }
	        }
	        steps++;
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends