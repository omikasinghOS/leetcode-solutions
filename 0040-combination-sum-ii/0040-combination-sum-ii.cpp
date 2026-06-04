class Solution {
public:
    vector<vector<int>> ans;

    void dfs(vector<int>& candidates, int target,
             vector<int>& path, int start) {

        if (target == 0) {
            ans.push_back(path);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            if (i > start &&
                candidates[i] == candidates[i - 1])
                continue;
            if (candidates[i] > target)
                break;
            path.push_back(candidates[i]);
            dfs(candidates,
                target - candidates[i],
                path,
                i + 1);   
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates,
                                        int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> path;
        dfs(candidates, target, path, 0);

        return ans;
    }
};