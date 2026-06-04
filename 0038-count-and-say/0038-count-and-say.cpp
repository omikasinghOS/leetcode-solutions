class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";

        for (int i = 2; i <= n; i++) {
            string temp = "";

            for (int j = 0; j < ans.size(); ) {
                int count = 1;

                while (j + 1 < ans.size() && ans[j] == ans[j + 1]) {
                    count++;
                    j++;
                }
                temp += to_string(count);
                temp += ans[j];
                j++;
            }

            ans = temp;
        }

        return ans;
    }
};