//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string longestPalin (string s) {
        // code here
        int n = s.length();
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        int si = -1;
        int maxLen = 0;
        for(int g = 0; g < n; g++){
            for(int i = 0, j = g; j < n; i++, j++){
                if(g == 0){
                    dp[i][j] = true;
                    if(maxLen == 0){
                        maxLen = 1;
                        si = i;
                    }
                }else if(g == 1){
                    if(s[i] == s[j]){
                        dp[i][j] = true;
                        if(maxLen < j-i+1){
                            maxLen = 2;
                            si = i;
                        }
                    }
                }else{
                    if(s[i] == s[j] && dp[i+1][j-1] == true){
                        dp[i][j] = true;
                        if(maxLen < j-i+1){
                            maxLen = j-i+1;
                            si = i;
                        }
                    }
                }
            }
        }
        return s.substr(si,maxLen);
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends