class Solution {
public:
    unordered_map<int, int> mp;
    int preIdx = 0;

    TreeNode* build(vector<int>& preorder, int left, int right) {
        if (left > right) return nullptr;

        int val = preorder[preIdx++];
        TreeNode* root = new TreeNode(val);

        int mid = mp[val];

        root->left = build(preorder, left, mid - 1);
        root->right = build(preorder, mid + 1, right);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;

        return build(preorder, 0, inorder.size() - 1);
    }
};