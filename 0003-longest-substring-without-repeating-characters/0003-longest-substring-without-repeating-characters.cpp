class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> chars;
        int left = 0, max_length = 0;
        
        for (int right = 0; right < s.length(); right++) {
            // Shrink window if duplicate found
            while (chars.find(s[right]) != chars.end()) {
                chars.erase(s[left]);
                left++;
            }
            
            // Add current character
            chars.insert(s[right]);
            
            // Update max length
            max_length = max(max_length, right - left + 1);
        }
        
        return max_length;
    }
};