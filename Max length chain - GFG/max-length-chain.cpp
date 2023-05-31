//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct val{
	int first;
	int second;
};


// } Driver Code Ends
/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/

class Solution{
public:
    /*You are required to complete this method*/
    
    static bool comparator(pair<int,int> a, pair<int,int> b){
        return a.second < b.second;
    }
    
    int maxChainLen(struct val p[],int n){
        //Your code here
        
        vector<pair<int,int>> vals(n);
        for(int i = 0; i < n; i++){
            int f = p[i].first;
            int s = p[i].second;
            vals[i] = {f,s};
        }
        sort(vals.begin(),vals.end(),comparator);
        int ans = 1;
        int currEnd = vals[0].second;
        for(int i = 1; i < n; i++){
            if(vals[i].first > currEnd){
                ans++;
                currEnd = vals[i].second;
            }
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		val p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}
		Solution ob;
		cout<<ob.maxChainLen(p,n)<<endl;
	}
	return 0;
}
// } Driver Code Ends