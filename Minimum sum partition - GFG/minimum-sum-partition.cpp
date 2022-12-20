//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
  

  
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum = 0;
	    for(int i = 0; i < n; i++){
	        sum += arr[i];
	    }
	    
	    vector<vector<bool>> dp(n,vector<bool>(sum+1,false));
	    
	    for(int i = 0; i < n; i++){
	        dp[i][0] = true;
	    }
	    for(int j = 0; j <= sum; j++){
	        if(j == arr[0]){
	            dp[0][j] = true;
	        }
	    }
	    
	    for(int i = 1; i < n; i++){
	        for(int j = 1; j <= sum; j++){
	            bool not_take = dp[i-1][j];
	            bool take = false;
	            if(j >= arr[i]){
	                take = dp[i-1][j-arr[i]];
	            }
	            dp[i][j] = take || not_take;
	        }
	    }
	    
	    for(int i = sum/2; i >= 0; i--){
	        if(dp[n-1][i] == true){
	            return abs(i - (sum-i));
	        }
	    }
	    return -1;
	    
	    
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends