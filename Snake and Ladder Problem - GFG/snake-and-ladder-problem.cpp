//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minThrow(int N, int arr[]){
        // code here
        map<int,int> lad_snake;
        for(int i = 0; i < 2*N; i += 2){
            int x = arr[i];
            int y = arr[i+1];
            lad_snake[x] = y;
        }
        
        int moves = 0;
        vector<bool> visited(31,false);
        
        queue<int> q;
        q.push(1);
        visited[1] = true;
        
        while(!q.empty()){
            moves++;
            int s = q.size();
            while(s--){
                int f = q.front();
                q.pop();
                
                for(int die = 1; die <= 6; die++){
                    int newV = f + die;
                    if(newV == 30){
                        return moves;
                    }
                    
                    if(newV < 30 && lad_snake.find(newV) != lad_snake.end() && !visited[lad_snake[newV]]){
                        if(lad_snake[newV] == 30){
                            return moves;
                        }
                        visited[lad_snake[newV]] = true;
                        q.push(lad_snake[newV]);
                    }
                    
                    if(newV < 30 && lad_snake.find(newV) == lad_snake.end() && !visited[newV]){
                        visited[newV] = true;
                        q.push(newV);
                    }
                    
                }
                
            }
        }
        
        return -1;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[2*N];
        for(int i = 0;i < 2*N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.minThrow(N, arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends