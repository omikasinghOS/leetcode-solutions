#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string s;
        dfs(res, s, n, n);
        return res;
    }

    void dfs(vector<string>& res, string s, int open, int close) {if (open == 0 && close == 0) {
            res.push_back(s);
            return;
        }
        if (open > 0) dfs(res, s + "(", open - 1, close);
        if (close > open) dfs(res, s + ")", open, close - 1);
    }
};