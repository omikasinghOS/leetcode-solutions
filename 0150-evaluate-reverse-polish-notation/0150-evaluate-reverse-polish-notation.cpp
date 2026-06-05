class Solution {
public:
    int evalRPN(vector<string>& t) {
        stack<long long> st;

        for (auto &x : t) {
            if (x == "+" || x == "-" || x == "*" || x == "/") {
                long long b = st.top(); st.pop();
                long long a = st.top(); st.pop();

                if (x == "+") st.push(a + b);
                else if (x == "-") st.push(a - b);
                else if (x == "*") st.push(a * b);
                else st.push(a / b);
            } else {
                st.push(stoll(x));
            }
        }
        return st.top();
    }
};