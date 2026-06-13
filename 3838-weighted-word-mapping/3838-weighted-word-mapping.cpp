class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans;

        for (string& w : words) {
            int sum = 0;

            for (char c : w) {
                sum += weights[c - 'a'];
            }

            sum %= 26;
            ans.push_back('z' - sum);
        }

        return ans;
    }
};