//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
  
    int recurHelp(int price[], int n, int ind, int remLen){
        if(ind == 0){
            return remLen*price[0];
        }
        int not_take = recurHelp(price,n,ind-1,remLen);
        int take = 0;
        if(ind + 1 <= remLen){
            take = recurHelp(price,n,ind,remLen-(ind+1)) + price[ind];
        }
        return max(take,not_take);
    }
  
  
    int dpHelp(int price[], int n){
        vector<vector<int>> dp(n,vector<int>(n+1,0));
        
        for(int j = 0; j <= n; j++){
            dp[0][j] = j*price[0];
        }
        
        for(int i = 1; i < n; i++){
            for(int j = 0; j <= n; j++){
                int not_take = dp[i-1][j];
                int take = INT_MIN;
                if(i+1 <= j){
                    take = price[i] + dp[i][j-(i+1)];
                }
                dp[i][j] = max(take,not_take);
            }
        }
        return dp[n-1][n];
    }
  
  
    int cutRod(int price[], int n) {
        //code here
        return dpHelp(price,n);
        return recurHelp(price,n,n-1,n);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends