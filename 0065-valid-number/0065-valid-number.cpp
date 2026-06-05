class Solution {
public:
    bool isNumber(string s) {
        int i = 0, n = s.size();

        while (i < n && s[i] == ' ') i++;

        if (i < n && (s[i] == '+' || s[i] == '-')) i++;

        bool num = false, dot = false, exp = false;

        while (i < n) {
            if (isdigit(s[i])) {
                num = true;
            } 
            else if (s[i] == '.') {
                if (dot || exp) return false;
                dot = true;
            } 
            else if (s[i] == 'e' || s[i] == 'E') {
                if (exp || !num) return false;
                exp = true;
                num = false; // must have digits after e

                if (i + 1 < n && (s[i + 1] == '+' || s[i + 1] == '-'))
                    i++;
            } 
            else {
                break;
            }
            i++;
        }

        while (i < n && s[i] == ' ') i++;

        return num && i == n;
    }
};