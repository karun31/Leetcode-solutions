//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int n)
	{
	    // Code here
	    vector<vector<bool>> visited(n,vector<bool>(n,0));
	    KnightPos[0]--;
	    KnightPos[1]--;
	    TargetPos[0]--;
	    TargetPos[1]--;
	    queue<pair<int,int>> q;
	    q.push({KnightPos[0],KnightPos[1]});
	    if(KnightPos[0] == TargetPos[0] && KnightPos[1] == TargetPos[1]){
	        return 0;
	    }
	    
	    int dx[8] = {1,1,-1,-1,2,2,-2,-2};
        int dy[8] = {2,-2,2,-2,1,-1,1,-1};	    
	    int steps = 0;
	    visited[KnightPos[0]][KnightPos[1]] = 1;
	    while(!q.empty()){
	        int k = q.size();
	        while(k--){
	            int x = q.front().first;
	            int y = q.front().second;
	            q.pop();
	            if(x == TargetPos[0] && y == TargetPos[1]){
	                return steps;
	            }
	            for(int z = 0; z < 8; z++){
	                int newX = x + dx[z]; 
	                int newY = y + dy[z];
	                if(newX >= 0 && newY >= 0 && newX < n && newY < n && !visited[newX][newY]){
	                    visited[newX][newY] = true;
	                    q.push({newX,newY});
	                }
	            }
	        }
	        steps++;
	    }
	    return -1;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends