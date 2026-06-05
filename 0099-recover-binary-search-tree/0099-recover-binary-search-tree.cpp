class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode *first = nullptr, *second = nullptr, *prev = nullptr;

        stack<TreeNode*> st;
        TreeNode* cur = root;

        while (cur || !st.empty()) {
            while (cur) {
                st.push(cur);
                cur = cur->left;
            }

            cur = st.top();
            st.pop();

            if (prev && prev->val > cur->val) {
                if (!first) first = prev;
                second = cur;
            }

            prev = cur;
            cur = cur->right;
        }

        swap(first->val, second->val);
    }
};