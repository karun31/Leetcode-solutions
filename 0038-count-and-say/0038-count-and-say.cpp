class Solution {
public:
    
    string helper(int n, string s){
        if(n == 0){
            return s;
        }
        string a = "";
        int i = 0;
        int x = s.length();
        while(i < x){
            int j = i+1;
            while(j < x && s[i] == s[j]){
                j++;
            }
            int len = j-i;
            a += len + '0';
            a += s[i];
            i = j;
        }
        return helper(n-1,a);
    }
    
    string countAndSay(int n) {
        string s = "1";
        return helper(n-1,s);
    }
};