class Solution {
public:
    
    static bool comparator(pair<int,int>& a, pair<int,int>& b){
        return a.second > b.second;
    }
    
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n = growTime.size();
        
        vector<pair<int,int>> times;
        
        for(int i = 0; i < n; i++){
            pair p{plantTime[i],growTime[i]};
            times.push_back(p);
            
        }
        
        
        sort(times.begin(),times.end(),comparator);
        
        
        int ans = 0;
        int startDay = 0;
        
        for(int i = 0; i < n; i++){
            int p = times[i].first;
            int g = times[i].second;
            ans = max(ans, startDay + p + g);
            startDay += p;
        }
        
        return ans;
        
    }
};