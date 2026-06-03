class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& a, int t) {
        sort(a.begin(), a.end());
        vector<vector<int>> r;
        int n=a.size();

        for(int i=0;i<n-3;i++){
            if(i&&a[i]== a[i- 1]) continue;
            for(int j= i+1; j<n-2;  j++){
                if(j>   i+1&&a[j]==a[j - 1]) continue;

                int l=j+1, k=n-1;
                while(l<k){
                    long long s=1LL*a[i]+a[j]+a[l]+a[k];

                    if(s==t){
                        r.push_back({a[i],a[j],a[l],a[k]});
                        while(l<k&&a[l]==a[l+1]) l++;
                        while(l<k&&a[k]==a[k-1]) k--;
                        l++; k--;
                    }
                    else if(s<t) l++;
                    else k--;
                }
            }
        }
        return r;
    }
};