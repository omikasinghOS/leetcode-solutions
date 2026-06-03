class Solution {
public:
    int val(char c){
        switch(c){
            case 'I':return 1;
            case 'V':return 5;
            case 'X':return 10;
            case 'L':return 50;
            case 'C':return 100;
            case 'D':return 500;
            default :return 1000;
        }
    }
    int romanToInt(string s){
        int r=0;
        for(int i=0;i<s.size();i++)
            r += val(s[i]) * (i+1<s.size() && val(s[i])<val(s[i+1]) ? -1 : 1);
        return r;
    }
};