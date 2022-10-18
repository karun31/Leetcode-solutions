class Solution {
public:
    
    string helper(string s){
        int i = 0;
        while(i < s.length() && s[i] != '*'){
            i++;
        }
        if(i == s.length()){
            return s;
        }
        i--;
        string newS = "";
        for(int x = 0; x < i; x++){
            newS += s[x];
        }
        for(int x = i+2; x < s.length(); x++){
            newS += s[x];
        }
        
        return helper(newS);
        
    }
    
    
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