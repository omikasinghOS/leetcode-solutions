class Solution {
public:
    bool isMatch(string s,string p){
        vector<vector<int>> dp(s.size()+1,vector<int>(p.size()+1,-1));
        auto f=[&](auto&& f,int i,int j)->bool{
            if(j==p.size()) return i==s.size();
            if(dp[i][j]!=-1) return dp[i][j];
            bool m=i<s.size()&&(s[i]==p[j]||p[j]=='.');
            return dp[i][j]=(j+1<p.size()&&p[j+1]=='*')?
                f(f,i,j+2)||(m&&f(f,i+1,j)):
                m&&f(f,i+1,j+1);
        };
        return f(f,0,0);
    }
};