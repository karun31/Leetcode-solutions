//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
         // Code here
         sort(intervals.begin(),intervals.end());
         vector<vector<int>> ans;
         int i = 0;
         while(i < intervals.size()){
             int j = i+1;
             int currOpening = intervals[i][0];
             int currClosing = intervals[i][1];
             while(j < intervals.size() && intervals[j][0] <= currClosing){
                 currClosing = max(currClosing,intervals[j][1]);
                 j++;
             }
             vector<int> temp{currOpening,currClosing};
             ans.push_back(temp);
             i = j;
         }
         return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends