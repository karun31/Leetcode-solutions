class Solution {
public:
    bool checkIfPangram(string sentence) {
        map<char,int> m;
        for(auto x : sentence){
            m[x]++;
        }
        return m.size() >= 26;
    }
};