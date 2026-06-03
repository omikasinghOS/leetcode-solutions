class Solution {
public:
    int threeSumClosest(vector<int>& a, int t) {
        sort(a.begin(), a.end());
        int n=a.size(), best=1e9;

        for(int i=0; i<n-2; i++){
            int l=i+1, r=n-1;
            while(l<r){
                int s=a[i]+a[l]+a[r];
                if(abs(s-t)<abs(best-t)) best=s;
                if(s<t) l++;
                else r--;
            }
        }
        return best;
    }
};