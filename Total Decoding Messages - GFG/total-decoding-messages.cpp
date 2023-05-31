//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		int CountWays(string str){
		    // Code here
		    if(str[0] == '0'){
		        return 0;
		    }
		    int n = str.length();
		    vector<int> dp(n,0);
		    dp[0] = 1;
		    if(str.length() == 1){
		        return dp[0];
		    }
		    if(str[1] == '0'){
		        if(str[0] == '1' || str[0] == '2'){
		            dp[1] = 1;
		        }else{
		            return 0;
		        }
		    }else{
		        if((str[0]-'0')*10 + (str[1]-'0') <= 26){
		            dp[1] = 2;
		        }else{
		            dp[1] = 1;
		        }
		    }
		    long modulo = 1000000007;
		    for(int i = 2; i < n; i++){
		        if(str[i] == '0' && str[i-1] == '0'){
		            return 0;
		        }else if(str[i] != '0' && str[i-1] == '0'){
		            dp[i] = dp[i-1]%modulo;
		        }else if(str[i] == '0' && str[i-1] != '0'){
		            if(str[i-1] == '1' || str[i-1] == '2'){
		                dp[i] = dp[i-2]%modulo;
		            }else{
		                return 0;
		            }
		        }else{
		            if((str[i-1]-'0')*10 + (str[i]-'0') <= 26){
		                dp[i] = (dp[i-1] + dp[i-2])%modulo;
		            }else{
		                dp[i] = dp[i-1];
		            }
		        }
		    }
		    return dp[n-1];
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends