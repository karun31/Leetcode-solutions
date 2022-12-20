//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:

    bool helper(string A, map<string,bool>& m, int si, int n){
        if(si == n){
            return true;
        }
        
        for(int i = si; i < n; i++){
            if(m.find(A.substr(si,i-si+1)) != m.end()){
                bool check = helper(A,m,i+1,n);
                if(check){
                    return true;
                }
            }
        }
        
        return false;
        
    }


    int wordBreak(string A, vector<string> &B) {
        //code here
        map<string,bool> m;
        for(auto x : B){
            m[x] = true;
        }
        
        return helper(A,m,0,A.length());
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends