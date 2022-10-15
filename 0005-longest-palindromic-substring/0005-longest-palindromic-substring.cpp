class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        int maxLen = 0;
        int si = 0;
        for(int g = 0; g < n; g++){
            for(int i = 0, j = g; j < n; i++, j++){
                if(g == 0){
                    maxLen = 1;
                    dp[i][j] = true;
                    si = i;
                }else if(g == 1){
                    if(s[i] == s[j]){
                        dp[i][j] = true;
                        maxLen = 2;
                        si = i;
                    }
                }else{
                    if(s[i] == s[j]){
                        if(dp[i+1][j-1] == true){
                            dp[i][j] = true;
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