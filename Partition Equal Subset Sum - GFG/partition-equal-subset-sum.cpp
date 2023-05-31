//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    bool recurHelp(int N, int arr[], int target, int ind){
        if(ind == N){
            return target == 0;
        }
        bool not_take = recurHelp(N,arr,target,ind+1);
        bool take = false;
        if(arr[ind] <= target){
            take = recurHelp(N,arr,target-arr[ind],ind+1);
        }
        return take || not_take;
    }


    bool dpHelp(int N, int arr[], int target){
        vector<vector<bool>> dp(N,vector<bool>(target+1,false));
        
        if(arr[0] <= target){
            dp[0][arr[0]] = true;
        }
        for(int i = 0; i < N; i++){
            dp[i][0] = true;
        }
        for(int i = 1; i < N; i++){
            for(int j = 1; j <= target; j++){
                bool not_take = dp[i-1][j];
                bool take = false;
                if(arr[i] <= j){
                    take = dp[i-1][j-arr[i]];
                }
                dp[i][j] = take || not_take;
            }
        }
        return dp[N-1][target];
        
    }

    bool subsetSum(int N, int arr[], int target){
        return dpHelp(N,arr,target);
        return recurHelp(N,arr,target,0);
    }

    int equalPartition(int N, int arr[])
    {
        // code here
        int sum = 0;
        for(int i = 0; i < N; i++){
            sum += arr[i];
        }
        if(sum%2 != 0){
            return 0;
        }
        return subsetSum(N,arr,sum/2);
        
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
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends