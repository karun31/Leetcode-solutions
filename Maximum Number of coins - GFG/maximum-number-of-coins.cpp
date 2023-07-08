//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    
        int recurHelp(vector<int>& nums, int si, int ei){
            if(si > ei){
                return 0;
            }
            int maxAns = INT_MIN;
            for(int ind = si; ind <= ei; ind++){
                int cost = nums[ind]*nums[si-1]*nums[ei+1] + recurHelp(nums,si,ind-1) + recurHelp(nums,ind+1,ei);
                maxAns = max(maxAns,cost);
            }
            return maxAns;
        }
        
        int dpHelp(vector<int>& nums){
            int n = nums.size();
            vector<vector<int>> dp(n+1,vector<int>(n+1,0));
            
            for(int si = n-2; si >= 1; si--){
                for(int ei = 1; ei <= n-2; ei++){
                    if(si > ei){
                        continue;
                    }
                    int maxAns = INT_MIN;
                    for(int ind = si; ind <= ei; ind++){
                        int cost = nums[ind]*nums[si-1]*nums[ei+1] + dp[si][ind-1] + dp[ind+1][ei];
                        maxAns = max(maxAns,cost);
                    }
                    dp[si][ei] = maxAns;
                }
            }
            return dp[1][n-2];
        }
    
        int maxCoins(int N, vector <int> &a)
        {
                // write your code here
                a.push_back(1);
                a.insert(a.begin(),1);
                int n = a.size();
                return dpHelp(a);
                return recurHelp(a,1,n-2);
        }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution S;
        cout<<S.maxCoins(n,a)<<endl;
    }
    return 0;
}
// } Driver Code Ends