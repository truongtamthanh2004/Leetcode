/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* &root, int val, int i, int depth)
    {
        if (!root) return;

        if (i == depth)
        {
            TreeNode* pleft = new TreeNode{val, root->left, nullptr};
            TreeNode* pright = new TreeNode{val, nullptr, root->right};
            root->left = pleft;
            root->right = pright;
            return;
        }
        
        dfs(root->left, val, i + 1, depth);
        dfs(root->right, val, i + 1, depth);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) return new TreeNode {val, root, nullptr};
        dfs(root, val, 2, depth);
        return root;
    }
};