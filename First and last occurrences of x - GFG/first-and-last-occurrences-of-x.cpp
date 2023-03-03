//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
vector<int> find(int arr[], int n , int x )
{
    // code here
    int s = 0, e = n-1;
    vector<int> ans;
    while(s <= e){
        int mid = (s+e)/2;
        if(arr[mid] == x){
            int fi = mid, li = mid;
            while(fi >= 0 && arr[fi] == x){
                fi--;
            }
            fi++;
            while(li < n && arr[li] == x){
                li++;
            }
            li--;
            ans.push_back(fi);
            ans.push_back(li);
            return ans;
        }else if(arr[mid] > x){
            e = mid-1;
        }else{
            s = mid+1;
        }
        
    }
    ans.push_back(-1);
    ans.push_back(-1);
    return ans;
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends