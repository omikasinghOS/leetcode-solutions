class Solution {
public:
    vector<vector<int>> result;

    void backtrack(vector<int>& nums, int start, vector<int>& subset) {
        result.push_back(subset);

        for (int i = start; i < nums.size(); i++) {
            subset.push_back(nums[i]);
            backtrack(nums, i + 1, subset);
            subset.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset;
        backtrack(nums, 0, subset);
        return result;
    }
};