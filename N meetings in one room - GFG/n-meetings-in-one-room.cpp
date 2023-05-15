//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    
    class Meeting{
      public:
      int st;
      int et;
      
      Meeting(int s, int e){
          st = s;
          et = e;
      }
        
    };
    
    bool static comp(Meeting m1, Meeting m2){
        return m1.et < m2.et;
    }
    
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<Meeting> meets;
        for(int i = 0; i < n; i++){
            Meeting m(start[i],end[i]);
            meets.push_back(m);
        }
        sort(meets.begin(),meets.end(),comp);
        
        int count = 1;
        int currEnd = meets[0].et;
        for(int i = 1; i < n; i++){
            if(meets[i].st > currEnd){
                count++;
                currEnd = meets[i].et;
            }
        }
        return count;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends