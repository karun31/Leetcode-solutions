//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int recurHelp(int arr[], int N, int si, int ei){
        if(si == ei){
            return 0;
        }
        int minVal = INT_MAX;
        for(int k = si; k < ei; k++){
            int lf = recurHelp(arr,N,si,k);
            int rf = recurHelp(arr,N,k+1,ei);
            int s = arr[si]*arr[k+1]*arr[ei+1];
            minVal = min(minVal,lf+rf+s);
        }
        return minVal;
    }
    
    int memoHelp(int arr[], int N, int si, int ei,vector<vector<int>>& memo){
        if(si == ei){
            return 0;
        }
        if(memo[si][ei] != -1){
            return memo[si][ei];
        }
        int minVal = INT_MAX;
        for(int k = si; k < ei; k++){
            int lf = memoHelp(arr,N,si,k,memo);
            int rf = memoHelp(arr,N,k+1,ei,memo);
            int s = arr[si]*arr[k+1]*arr[ei+1];
            minVal = min(minVal,lf+rf+s);
        }
        return memo[si][ei] = minVal;
    }
    
    int dpHelp(int arr[], int n){
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int si = n-2; si >= 0; si--){
            for(int ei = 0; ei <= n-2; ei++){
                if(si >= ei){
                    continue;
                }
                int minVal = INT_MAX;
                for(int k = si; k < ei; k++){
                    int lf = dp[si][k];
                    int rf = dp[k+1][ei];
                    int s = arr[si]*arr[k+1]*arr[ei+1];
                    minVal = min(minVal,lf+rf+s);
                }
                dp[si][ei] = minVal;
            }
        }
        return dp[0][n-2];
    }

    int matrixMultiplication(int N, int arr[])
    {
        // code here
        return dpHelp(arr,N);
        vector<vector<int>> memo(N-1,vector<int>(N-1,-1));
        return memoHelp(arr,N,0,N-2,memo);
        //return recurHelp(arr,N,0,N-2);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends