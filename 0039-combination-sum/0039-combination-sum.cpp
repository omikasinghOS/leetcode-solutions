class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;

    void backtrack(vector<int>& candidates, int target, int idx) {
        if (target ==0) {
            ans.push_back(curr);
            return;
        }
        if (target<0 || idx == candidates.size())
            return;
        curr.push_back(candidates[ idx]);
        backtrack(candidates, target - candidates[idx], idx);
        curr.pop_back();
        backtrack(candidates, target, idx + 1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtrack(candidates, target, 0);
        return ans;
    }
};