class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<int> ans(m,-2);
        
        
        for(int j = 0; j < m; j++){
            int currCol = j;
            for(int i = 0; i < n; i++){
                if(grid[i][currCol] == 1){
                    if(currCol == m-1){
                        ans[j] = -1;
                        break;
                    }
                    if(grid[i][currCol+1] == -1){
                        ans[j] = -1;
                        break;
                    }
                    currCol++;
                }else{
                    if(currCol == 0){
                        ans[j] = -1;
                        break;
                    }
                    if(grid[i][currCol-1] == 1){
                        ans[j] = -1;
                        break;
                    }
                    currCol--;
                }
                
            }
            if(ans[j] == -2){
                ans[j] = currCol;
            }
        }
        
        return ans;
    }
};