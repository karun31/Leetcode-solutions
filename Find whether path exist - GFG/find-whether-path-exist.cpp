//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    
    bool checkUsingBFS(vector<vector<int>>& grid, int x, int y){
        int n = grid.size(), m = grid[0].size();
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};
        queue<pair<int,int>> q;
        q.push({x,y});
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            for(int z = 0; z < 4; z++){
                int newX = i + dx[z];
                int newY = j + dy[z];
                if(newX >= 0 && newY >= 0 && newX < n && newY < m){
                    if(grid[newX][newY] == 2){
                        return true;
                    }
                    if(grid[newX][newY] == 3){
                        q.push({newX,newY});
                        grid[newX][newY] = 1;
                    }
                }
            }
        }
        return false;
        
    }
    
    bool is_Possible(vector<vector<int>>& grid) 
    {
        //code here
        int x = 0, y = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    x = i, y = j;
                }
            }
        }
        return checkUsingBFS(grid,x,y);
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}
// } Driver Code Ends