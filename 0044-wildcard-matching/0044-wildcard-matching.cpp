class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();

        vector<bool> prev(m + 1, false), curr(m + 1, false);

        prev[0] = true;

        for (int j = 1; j <= m; j++) {
            if (p[j - 1] == '*')
                prev[j] = prev[j - 1];
        }

        for (int i = 1; i <= n; i++) {
            curr[0] = false;

            for (int j = 1; j <= m; j++) {
                if (p[j - 1] == '*') {
                    curr[j] = curr[j - 1] || prev[j];
                }
                else if (p[j - 1] == '?' || s[i - 1] == p[j - 1]) {
                    curr[j] = prev[j - 1];
                }
                else {
                    curr[j] = false;
                }
            }
            prev = curr;
            fill(curr.begin(), curr.end(), false);
        }
        return prev[m];
    }
};