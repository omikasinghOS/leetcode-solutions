class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);  // Base index
        int maxLen = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                st.pop();

                if (st.empty()) {
                    st.push(i);  // New base
                } else {
                    maxLen = max(maxLen, i - st.top());
                }
            }
        }

        return maxLen;

    }
};