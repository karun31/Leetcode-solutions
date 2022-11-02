class Solution {
public:
    int minDistance(string s, string t) {
        int n = s.length();
        int m = t.length();
        
        vector<vector<int>> dp(n+1, vector<int>(m+1,0));
        
        for(int i = 1; i <= n; i++){
            dp[i][0] = i;
        }
        for(int j = 1; j <= m; j++){
            dp[0][j] = j;
        }
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(s[n-i] == t[m-j]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1;
                }
            }
        }
        return dp[n][m];
        
    }
};