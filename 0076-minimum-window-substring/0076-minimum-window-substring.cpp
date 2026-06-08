class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;

        for (char c : t) mp[c]++;

        int required = t.size();
        int left = 0, start = 0, minLen = INT_MAX;

        for (int right = 0; right < s.size(); right++) {
            if (mp[s[right]] > 0) required--;
            mp[s[right]]--;

            while (required == 0) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                mp[s[left]]++;
                if (mp[s[left]] > 0) required++;
                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
