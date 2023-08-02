//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        if(A[0][0] == 0){
            return -1;
        }
        if(X == 0 && Y == 0){
            return 0;
        }
        int n = A.size(), m = A[0].size();
        queue<pair<int,int>> q;
        int steps = 1;
        q.push({0,0,});
        A[0][0] = 0;
        while(!q.empty()){
            int k = q.size();
            while(k--){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int i = 0; i < 4; i++){
                    int newX = x + dx[i], newY = y + dy[i];
                    if(newX >= 0 && newY >= 0 && newX < n && newY < m && A[newX][newY] == 1){
                        if(newX == X && newY == Y){
                            return steps;
                        }
                        A[newX][newY] = 0;
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
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends