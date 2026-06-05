class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int n = words.size();
        int i = 0;

        while (i < n) {
            int j = i, lineLen = 0;
            while (j < n && lineLen + words[j].size() + (j - i) <= maxWidth) {
                lineLen += words[j].size();
                j++;
            }
            int gaps = j - i - 1;
            string line;

            if (j == n || gaps == 0) {
                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k != j - 1) line += " ";
                }
                line += string(maxWidth - line.size(), ' ');
            } 
            else {
                int spaces = maxWidth - lineLen;
                int spaceEach = spaces / gaps;
                int extra = spaces % gaps;

                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k != j - 1) {
                        line += string(spaceEach + (extra > 0 ? 1 : 0), ' ');
                        if (extra > 0) extra--;
                    }
                }
            }
            res.push_back(line);
            i = j;
        }
        return res;
    }
};