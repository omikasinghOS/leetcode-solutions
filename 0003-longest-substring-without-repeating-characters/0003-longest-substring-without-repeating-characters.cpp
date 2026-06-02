class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> chars;
        int left = 0, max_length = 0;
        
        for (int right = 0; right < s.length(); right++) {
          
            while (chars.find(s[right]) != chars.end()) {
                chars.erase(s[left]);
                left++;
            }
            

            chars.insert(s[right]);
            

            max_length = max(max_length, right - left + 1);
        }
        
        return max_length;
    }
};