//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    
    void helper(string S, int n, vector<string>& ans, vector<bool>& visited, string path){
        if(path.length() == n){
            ans.push_back(path);
            return;
        }
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                string t = path + S[i];
                visited[i] = true;
                helper(S,n,ans,visited,t);
                visited[i] = false;
            }
        }
    }
    
    vector<string> permutation(string S)
    {
        //Your code here
        vector<string> ans;
        int n = S.length();
        vector<bool> visited(n,false);
        string path = "";
        helper(S,n,ans,visited,path);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends