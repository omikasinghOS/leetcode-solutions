class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        int n = path.size();
        string cur;

        for (int i = 0; i < n; i++) {
            if (path[i] == '/') {
                if (cur == "..") {
                    if (!st.empty()) st.pop_back();
                } 
                else if (!cur.empty() && cur != ".") {
                    st.push_back(cur);
                }
                cur.clear();
            } 
            else {
                cur += path[i];
            }
        }
        if (cur == "..") {
            if (!st.empty()) st.pop_back();
        } 
        else if (!cur.empty() && cur != ".") {
            st.push_back(cur);
        }
        string res = "/";
        for (int i = 0; i < st.size(); i++) {
            res += st[i];
            if (i + 1 < st.size()) res += "/";
        }

        return res;
    }
};