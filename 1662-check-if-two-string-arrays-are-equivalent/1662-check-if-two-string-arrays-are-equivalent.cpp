class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string a = "";
        for(int i = 0; i < word1.size(); i++){
            a += word1[i];
        }
        string b = "";
        for(int i = 0; i < word2.size(); i++){
            b += word2[i];
        }
//         if(a.length() != b.length()){
//             return false;
//         }
        
//         for(int i = 0; i < a.length(); i++){
//             if(a[i] != b[i]){
//                 return false;
//             }
//         }
//         return true;
        return a == b;
    }
};