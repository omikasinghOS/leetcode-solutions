class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        string r=s[0];
        for(auto &x:s)
            while(x.find(r)!=0) r.pop_back();
        return r;
    }
};