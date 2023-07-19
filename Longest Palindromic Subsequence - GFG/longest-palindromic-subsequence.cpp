//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  
    int lcs(string s, string t){
        int n = s.length();
        int m = t.length();
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(s[n-i] == t[m-j]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        return dp[n][m];
        
    }
  
    int longestPalinSubseq(string s) {
        //code here
        string t = s;
        reverse(t.begin(),t.end());
        return lcs(s,t);
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends