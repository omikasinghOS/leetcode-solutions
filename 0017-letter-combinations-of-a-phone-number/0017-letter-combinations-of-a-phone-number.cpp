class Solution {
public:
    vector<string> letterCombinations(string d) {
        if(d.empty()) return {};
        vector<string> m={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> r={""};

        for(char x:d){
            vector<string> t;
            for(string &s:r)
                for(char c:m[x-'0'])
                    t.push_back(s+c);
            r.swap(t);
        }
        return r;
    }
};