//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
public:

    int recHelp(vector<vector<int>> &colors, int N, int ind, int prevCol){
        if(ind == N){
            return 0;
        }
        int ans = 0;
        if(prevCol == 3){
            int a = recHelp(colors,N, ind+1,0) + colors[ind][0];
            int b = recHelp(colors,N, ind+1,1) + colors[ind][1];
            int c = recHelp(colors,N, ind+1,2) + colors[ind][2];
            ans = min(a,min(b,c));
        }
        if(prevCol == 0){
            int a = recHelp(colors,N, ind+1,1) + colors[ind][1];
            int b = recHelp(colors,N, ind+1,2) + colors[ind][2];
            ans = min(a,b);
        }
        if(prevCol == 1){
            int a = recHelp(colors,N, ind+1,0) + colors[ind][0];
            int b = recHelp(colors,N, ind+1,2) + colors[ind][2];
            ans = min(a,b);
        }
        if(prevCol == 2){
            int a = recHelp(colors,N, ind+1,0) + colors[ind][0];
            int b = recHelp(colors,N, ind+1,1) + colors[ind][1];
            ans = min(a,b);
        }
        return ans;
        
    }
    
    int memoHelp(vector<vector<int>> &colors, int N,int ind, int prevCol,vector<vector<int>>& memo){
        if(ind == N){
            return 0;
        }
        if(memo[ind][prevCol] != -1){
            return memo[ind][prevCol];
        }
        int ans = 0;
        if(prevCol == 3){
            int a = memoHelp(colors,N, ind+1,0,memo) + colors[ind][0];
            int b = memoHelp(colors,N, ind+1,1,memo) + colors[ind][1];
            int c = memoHelp(colors,N, ind+1,2,memo) + colors[ind][2];
            ans = min(a,min(b,c));
        }
        if(prevCol == 0){
            int a = memoHelp(colors,N, ind+1,1,memo) + colors[ind][1];
            int b = memoHelp(colors,N, ind+1,2,memo) + colors[ind][2];
            ans = min(a,b);
        }
        if(prevCol == 1){
            int a = memoHelp(colors,N, ind+1,0,memo) + colors[ind][0];
            int b = memoHelp(colors,N, ind+1,2,memo) + colors[ind][2];
            ans = min(a,b);
        }
        if(prevCol == 2){
            int a = memoHelp(colors,N, ind+1,0,memo) + colors[ind][0];
            int b = memoHelp(colors,N, ind+1,1,memo) + colors[ind][1];
            ans = min(a,b);
        }
        return memo[ind][prevCol] = ans;
        
    }

    

    int minCost(vector<vector<int>> &colors, int N) {
        // Write your code here.
        vector<vector<int>> memo(N,vector<int>(4,-1));
        return memoHelp(colors,N,0,3,memo);
        
        return recHelp(colors,N,0,3);
        
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        vector<vector<int>> colors(n, vector<int>(3));
        for (int i = 0; i < n; i++)
            cin >> colors[i][0] >> colors[i][1] >> colors[i][2];
            
        Solution ob;
        cout << ob.minCost(colors, n) << endl;    
    }
}
// } Driver Code Ends