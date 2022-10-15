class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0;
        int count = 0;
        while(i < s.length()){
            unordered_map<char,int> m;
            int c = 0;
            for(int j = i; j < s.length(); j++){
                if(m[s[j]] == 0){
                    c++;
                    m[s[j]]++;
                }else{
                    break;
                }
            }
            count = max(count,c);
            i++;
        }
        return count;
    }
};