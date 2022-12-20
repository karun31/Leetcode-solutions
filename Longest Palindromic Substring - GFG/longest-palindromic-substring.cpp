//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    string longestPalindrome(string S){
        // code here 
        int n = S.length();
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        int maxLen = 0;
        int si = 0;
        for(int g = 0; g < n; g++){
            for(int i = 0, j = g; j < n; i++, j++){
                if(g == 0){
                    dp[i][j] = true;
                    if(j-i+1 > maxLen){
                        maxLen = j-i+1;
                        si = i;
                    }
                }else if(g == 1){
                    if(S[i] == S[j]){
                        dp[i][j] = true;
                        if(j-i+1 > maxLen){
                            maxLen = j-i+1;
                            si = i;
                        }
                    }
                }else{
                    if(S[i] == S[j] && dp[i+1][j-1] == true){
                        dp[i][j] = true;
                        if(j-i+1 > maxLen){
                            maxLen = j-i+1;
                            si = i;
                        }
                    }
                }
            }
        }
        return S.substr(si,maxLen);
        
        
    }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.longestPalindrome(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends