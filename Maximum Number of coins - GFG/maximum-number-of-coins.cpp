//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    
        int recurHelp(int N, vector<int>& a, int si, int ei){
            if(si > ei){
                return 0;
            }
            int maxScore = INT_MIN;
            for(int i = si; i <= ei; i++){
                int cost = recurHelp(N,a,si,i-1) + recurHelp(N,a,i+1,ei) + a[si-1]*a[i]*a[ei+1];
                maxScore = max(maxScore, cost);
            }
            return maxScore;
        }
        
        int memoHelp(int N, vector<int>& a, int si, int ei, vector<vector<int>>& memo){
            if(si > ei){
                return 0;
            }
            if(memo[si][ei] != -1){
                return memo[si][ei];
            }
            int maxScore = INT_MIN;
            for(int i = si; i <= ei; i++){
                int cost = memoHelp(N,a,si,i-1,memo) + memoHelp(N,a,i+1,ei,memo) + a[si-1]*a[i]*a[ei+1];
                maxScore = max(maxScore, cost);
            }
            return memo[si][ei] = maxScore;
        }       
    
    
        int maxCoins(int N, vector <int> &a)
        {
            // write your code here
            a.push_back(1);
            a.insert(a.begin(),1);
            N = a.size();
            vector<vector<int>> memo(N,vector<int>(N,-1));
            return memoHelp(N,a,1,N-2,memo);
            //return recurHelp(N,a,1,N-2);
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