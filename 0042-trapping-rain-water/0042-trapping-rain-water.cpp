class Solution {
public:
    int trap(vector<int>& a) {
        int l = 0;
        int r = a.size()-1;
        int lmax = 0;
        int rmax = 0;
        int ans = 0;
        while(l < r){
            if(a[l] <= a[r]){
                if(a[l] > lmax){
                    lmax = a[l];
                }else{
                    ans += lmax-a[l];
                }
                l++;
            }else{
                if(a[r] > rmax){
                    rmax = a[r];
                }else{
                    ans += rmax-a[r];
                }
                r--;
            }
        }
        return ans;
    }
};