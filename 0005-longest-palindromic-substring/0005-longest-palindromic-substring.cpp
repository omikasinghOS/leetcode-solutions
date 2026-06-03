class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size(),l=0,r=0;
        auto f=[&](int i,int j){
            while(i>=0&&j<n&&s[i]==s[j]) i--,j++;
            if(j-i-2>r-l) l=i+1,r=j-1;
        };
        for(int i=0;i<n;i++) f(i,i),f(i,i+1);
        return s.substr(l,r-l+1);
    }
};