class Solution {
public:
    string intToRoman(int num) {
        vector<int> a = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        vector<string> b = {"M", "CM", "D" , "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        
        string ans;
        int i = 0;
        while(num > 0 && i < a.size()){
            if(num >= a[i]){
                ans += b[i];
                num = num - a[i];
            }else{
                i++;
            }
        }
        return ans;
    }
};