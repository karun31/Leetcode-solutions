//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:


    int recurHelp(int N, int arr[], int si, int ei){
        if(si >= ei){
            return 0;
        }
        int minVal = INT_MAX;
        for(int k = si; k < ei; k++){
            int lVal = recurHelp(N,arr,si,k);
            int rVal = recurHelp(N,arr,k+1,ei);
            int multiVal = arr[si]*arr[k+1]*arr[ei+1];
            minVal = min(minVal,lVal+rVal+multiVal);
        }
        return minVal;
    }
    
    int memoHelp(int N, int arr[], int si, int ei, vector<vector<int>>& memo){
        if(si >= ei){
            return 0;
        }
        if(memo[si][ei] != -1){
            return memo[si][ei];
        }
        int minVal = INT_MAX;
        for(int k = si; k < ei; k++){
            int lVal = memoHelp(N,arr,si,k,memo);
            int rVal = memoHelp(N,arr,k+1,ei,memo);
            int multiVal = arr[si]*arr[k+1]*arr[ei+1];
            minVal = min(minVal,lVal+rVal+multiVal);
        }
        return memo[si][ei] = minVal;
    }


    int dpHelp(int N, int arr[]){
        vector<vector<int>> dp(N,vector<int>(N,0));
        
        for(int si = N-2; si >= 0; si--){
            for(int ei = 0; ei <= N-2; ei++){
                if(si >= ei){
                    continue;
                }
                int minVal = INT_MAX;
                for(int k = si; k < ei; k++){
                    int lVal = dp[si][k];
                    int rVal = dp[k+1][ei];
                    int multiVal = arr[si]*arr[k+1]*arr[ei+1];
                    minVal = min(minVal, lVal + rVal + multiVal);
                }
                dp[si][ei] = minVal;
            }
        }
        return dp[0][N-2];
    }

    int matrixMultiplication(int N, int arr[])
    {
        return dpHelp(N,arr);
        vector<vector<int>> memo(N,vector<int>(N,-1));
        return memoHelp(N,arr,0,N-2,memo);
        return recurHelp(N,arr,0,N-2);
        // code here
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