class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (s.empty() || words.empty()) return res;

        int n = s.size(), m = words.size(), w = words[0].size();
        unordered_map<string,int> need;

        for (auto &x : words) need[x]++;
        for (int i = 0; i < w; i++) {
            unordered_map<string,int> win;
            int left =i, cnt= 0;

            for (int j = i; j + w <= n; j += w) {
                string cur = s.substr(j, w);

                if (need.count(cur)) {
                    win[cur]++; cnt++;

                    while (win[cur] > need[cur]) {
                        string t = s.substr(left, w);
                        win[t]--; left += w; cnt--;
                    }

                    if (cnt == m) {
                        res.push_back(left);
                        string t = s.substr(left, w);
                        win[t]--; left += w; cnt--;
                    }
                } else {
                    win.clear(); cnt = 0;
                    left = j + w;
                }
            }
        }
        return res;
    }
};