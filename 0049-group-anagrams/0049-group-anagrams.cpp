class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> sorted(strs.size());
        for(int i = 0; i < strs.size(); i++){
            string s = strs[i];
            sort(s.begin(),s.end());
            sorted[i] = s;
        }
        
        map<string, vector<string>> m;
        for(int i = 0; i < strs.size(); i++){
            m[sorted[i]].push_back(strs[i]);
        }
        
        vector<vector<string>> ans;
        for(auto t : m){
            ans.push_back(t.second);
        }
        return ans;
        
    }
};