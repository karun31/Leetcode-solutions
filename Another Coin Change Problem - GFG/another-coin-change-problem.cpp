//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
  
    bool recurHelp(int N, int K, int target, vector<int>& coins, int ind){
        if(ind == N){
            return target == 0 && K == 0;
        }
        bool not_take  = recurHelp(N,K,target,coins,ind+1);
        bool take = false;
        if(coins[ind] <= target){
            take = recurHelp(N,K-1,target-coins[ind],coins,ind);
        }
        return take || not_take;
    }
    
    
    bool memoHelp(int N, int K, int target, vector<int>& coins, int ind,vector<vector<vector<int>>>& memo){
        if(ind == N){
            return target == 0 && K == 0;
        }
        if(K < 0 || target < 0){
            return false;
        }
        if(memo[ind][K][target] != -1){
            return memo[ind][K][target];
        }
        bool not_take  = memoHelp(N,K,target,coins,ind+1,memo);
        bool take = false;
        if(coins[ind] <= target){
            take = memoHelp(N,K-1,target-coins[ind],coins,ind,memo);
        }
        return memo[ind][K][target] = take || not_take;
    }
  
    
  
  
  
    bool makeChanges(int N, int K, int target, vector<int> &coins) {
        // code here
        vector<vector<vector<int>>> memo(N,vector<vector<int>>(K+1,vector<int>(target+1,-1)));
        return memoHelp(N,K,target,coins,0,memo);
        return recurHelp(N,K,target,coins,0);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int N;
        scanf("%d", &N);

        int K;
        scanf("%d", &K);

        int target;
        scanf("%d", &target);

        vector<int> coins(N);
        Array::input(coins, N);

        Solution obj;
        bool res = obj.makeChanges(N, K, target, coins);

        cout << res << endl;
    }
}

// } Driver Code Ends