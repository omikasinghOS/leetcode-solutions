class Solution {
public:
    string convert(string s, int n) {
        if (n == 1 || n >= s.size()) return s;
        vector<string> r(n);
        int i = 0, d = 1;
        for (char c : s) {
            r[i] += c;
            if (i == 0) d = 1;
            else if (i == n - 1) d = -1;
            i += d;
        }
        string ans;
        for (auto &x : r) ans += x;
        return ans;
    }
};