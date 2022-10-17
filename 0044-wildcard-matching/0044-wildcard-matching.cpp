class Solution {
public:
    bool isMatch(string s, string p) {
        int n = p.length();
        int m = s.length();
        
        vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));
        
        dp[n][m] = true;
        
        for(int i = n-1; i >= 0; i--){
            if(p[i] == '*'){
                dp[i][m] = dp[i+1][m];
            }
        }
        
        
        for(int i = n-1; i >= 0; i--){
            for(int j = m-1; j >= 0; j--){
                if(p[i] == '*'){
                    dp[i][j] = dp[i+1][j] || dp[i][j+1];
                }else if(p[i] == '?'){
                    dp[i][j] = dp[i+1][j+1];
                }else{
                    if(p[i] == s[j]){
                        dp[i][j] = dp[i+1][j+1];
                    }
                }
            }
        }
        return dp[0][0];
        
        
    }
};