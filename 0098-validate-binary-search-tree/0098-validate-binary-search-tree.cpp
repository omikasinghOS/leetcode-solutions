class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return helper(root, LLONG_MIN, LLONG_MAX);
    }
private:
    bool helper(TreeNode* node, long long low, long long high) {
        if (!node) return true;

        if (node->val <= low || node->val >= high) return false;
        return helper(node->left, low, node->val) &&
               helper(node->right, node->val, high);
    }
};