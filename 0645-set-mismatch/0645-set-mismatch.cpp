class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int,int> m;
        for(int i = 0; i < nums.size(); i++){
            m[nums[i]]++;
        }
        int n = nums.size();
        int duplicate;
        int missing;
        for(int i = 1; i <= n; i++){
            if(m[i] == 2){
                duplicate = i;
            }
            if(m[i] == 0){
                missing = i;
            }
        }
        vector<int> ans;
        ans.push_back(duplicate);
        ans.push_back(missing);
        return ans;
    }
};