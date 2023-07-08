//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


// } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    
    void helper(int remOpen, int remClosed, vector<string>& ans, string s){
        if(remOpen == 0 && remClosed == 0){
            ans.push_back(s);
            return;
        }
        if(remClosed > remOpen){
            string t = s;
            t += ')';
            helper(remOpen,remClosed-1,ans,t);
        }
        if(remOpen > 0){
            string t = s;
            t += '(';
            helper(remOpen-1,remClosed,ans,t);
        }
    }
    
    
    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here 
        vector<string> ans;
        string s = "";
        helper(n,n,ans,s);
        return ans;
    }
};

//{ Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 

// } Driver Code Ends