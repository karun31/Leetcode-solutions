//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxInstance(string s){
        map<char,int> m;
        for(auto c : s){
            m[c]++;
        }
        int maxPossible = INT_MAX;
        maxPossible = min(maxPossible,m['b']);
        maxPossible = min(maxPossible,m['a']);
        maxPossible = min(maxPossible,m['l']/2);
        maxPossible = min(maxPossible,m['o']/2);
        maxPossible = min(maxPossible,m['n']);
        return maxPossible;
        
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.maxInstance(s)<<endl;
    }
    return 0;
}
// } Driver Code Ends