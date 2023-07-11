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
        int start;
        int end;
        
        Meeting(int s, int e){
            start = s;
            end = e;
        }
    };
    
    
    static bool comparator(Meeting a, Meeting b){
        return a.end < b.end;
    }
    
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<Meeting> v;
        for(int i = 0; i < n; i++){
            Meeting m(start[i],end[i]);
            v.push_back(m);
        }
        sort(v.begin(),v.end(),comparator);
        
        
        int cnt = 1;
        int currEnd = v[0].end;
        for(int i = 1; i < n; i++){
            if(v[i].start > currEnd){
                cnt++;
                currEnd = v[i].end;
            }
        }
        return cnt;
        
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