//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long solve(int N, int K, vector<long long> GeekNum) {
        // code here
        if(K == 1){
            return GeekNum[0];
        }
        if(N <= K){
            return GeekNum[N-1];
        }
        
        int l = 0;
        int r = K-1;
        long long sum = 0;
        for(int i = l; i <= r; i++){
            sum += GeekNum[i];
        }
        GeekNum.push_back(sum);
        while(GeekNum.size() < N){
            sum -= GeekNum[l];
            l++;
            r++;
            sum += GeekNum[r];
            GeekNum.push_back(sum);
        }
        return GeekNum[N-1];
    }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<long long> GeekNum(K);

        for (int i = 0; i < K; i++) cin >> GeekNum[i];

        Solution ob;
        cout << ob.solve(N, K, GeekNum) << "\n";
    }
    return 0;
}

// } Driver Code Ends