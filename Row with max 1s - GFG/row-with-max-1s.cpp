//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

    int index(vector<int>& row, int size){
        int l = 0;
        int h = size-1;
        while(l <= h){
            int mid = (l+h)/2;
            if(row[mid] == 1){
                h = mid-1;
            }else{
                l = mid+1;
            }
        }
        return l;
    }


	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    // code here
	    n = arr.size();
	    m = arr[0].size();
	    int ans = 0;
	    int minInd = index(arr[0],m);
	    for(int i = 1; i < n; i++){
	        int smallInd = index(arr[i],m);
	        if(smallInd < minInd){
	            minInd = smallInd;
	            ans = i;
	        }
	    }
	    if(minInd == m){
	        return -1;
	    }
	    return ans;
	}

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends