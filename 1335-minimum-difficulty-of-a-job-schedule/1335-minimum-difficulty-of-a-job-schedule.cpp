class Solution {
public:
    
    int rec(vector<int>& jobDifficulty,int n, int d, int ind){
        if(ind == n && d != 0){
            return -1;
        }
        if(d == 0 && ind != n){
            return -1;
        }
        if(d == 0 && ind == n){
            return 0;
        }
        int maxi = INT_MIN;
        int ans = INT_MAX;
        for(int i = ind; i < n; i++){
            maxi = max(maxi, jobDifficulty[i]);
            int sAns = rec(jobDifficulty, n, d-1, i+1);
            if(sAns != -1){
                if(sAns < ans){
                    ans = min(ans,sAns + maxi);    
                }
                
            }
        }
        return ans;
    }
    

    int memoization(vector<int>& jobDifficulty,int n, int d, int ind,vector<vector<int>>& memo){
        if(ind == n && d != 0){
            return -1;
        }
        if(d == 0 && ind != n){
            return -1;
        }
        if(d == 0 && ind == n){
            return 0;
        }
        if(memo[d][ind] != -1){
            return memo[d][ind];
        }
        int maxi = INT_MIN;
        int ans = INT_MAX;
        for(int i = ind; i < n; i++){
            maxi = max(maxi, jobDifficulty[i]);
            int sAns = memoization(jobDifficulty, n, d-1, i+1,memo);
            if(sAns != -1){
                if(sAns < ans){
                    ans = min(ans,sAns + maxi);    
                }
                
            }
        }
        return memo[d][ind] = ans;
    }
        
    
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if(n < d){
            return -1;
        }
        if(n == d){
            int s = 0;
            for(auto x : jobDifficulty){
                s += x;
            }
            return s;
        }
        vector<vector<int>> memo(d+1,vector<int>(n,-1));
        return memoization(jobDifficulty,n,d,0,memo);
        // return rec(jobDifficulty,n,d,0);
    }
};