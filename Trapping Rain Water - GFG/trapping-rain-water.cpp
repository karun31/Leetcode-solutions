//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        // code here
        long long ans = 0;
        int l = 0;
        int r = n-1;
        int lmax = arr[l];
        int rmax = arr[r];
        while(l < r){
            if(arr[l] < arr[r]){
                if(arr[l] < lmax){
                    ans += lmax - arr[l];
                }else{
                    lmax = arr[l];
                }
                l++;
            }else{
                if(arr[r] < rmax){
                    ans += rmax - arr[r];
                }else{
                    rmax = arr[r];
                }
                r--;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends