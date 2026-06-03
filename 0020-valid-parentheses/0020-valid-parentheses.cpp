class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char c:s){
            if(c=='('||c=='{'||c=='[') st.push(c);
            else{
                if(st.empty()) return false;
                if(abs(st.top()-c)>2) return false;
                st.pop();
            }
        }
        return st.empty();
    }
};