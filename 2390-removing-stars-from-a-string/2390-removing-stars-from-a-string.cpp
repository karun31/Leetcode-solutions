class Solution {
public:
   
    string removeStars(string s) {
        stack<char> S;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '*'){
                S.pop();
            }else{
                S.push(s[i]);
            }
        }
        
        string ans = "";
        while(!S.empty()){
            ans += S.top();
            S.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};