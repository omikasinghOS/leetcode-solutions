class Solution {
public:
    vector<string> result;

    bool isValid(string s) {
        if (s.empty() || s.size() > 3) return false;
        if (s.size() > 1 && s[0] == '0') return false;
        int num = stoi(s);
        return num >= 0 && num <= 255;
    }

    void backtrack(string& s, int start, int parts, string current) {
        if (parts == 4 && start == s.size()) {
            current.pop_back(); // remove last '.'
            result.push_back(current);
            return;
        }

        if (parts == 4 || start == s.size()) return;

        for (int len = 1; len <= 3 && start + len <= s.size(); len++) {
            string part = s.substr(start, len);

            if (isValid(part)) {
                backtrack(s, start + len, parts + 1, current + part + ".");
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        backtrack(s, 0, 0, "");
        return result;
    }
};