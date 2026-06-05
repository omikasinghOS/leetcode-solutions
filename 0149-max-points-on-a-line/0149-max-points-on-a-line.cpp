class Solution {
public:
    int maxPoints(vector<vector<int>>& p) {
        int n = p.size(), ans = 1;
        
        for (int i = 0; i < n; i++) {
            unordered_map<long double,int> mp;
            int dup = 0, cur = 0;

            for (int j = i + 1; j < n; j++) {
                if (p[i] == p[j]) { dup++; continue; }

                long double slope = (p[j][0] - p[i][0] == 0)
                    ? 1e18
                    : (long double)(p[j][1] - p[i][1]) / (p[j][0] - p[i][0]);

                cur = max(cur, ++mp[slope]);
            }

            ans = max(ans, cur + dup + 1);
        }

        return ans;
    }
};