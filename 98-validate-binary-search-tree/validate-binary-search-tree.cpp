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
private:
    long long prev = LONG_MIN;
    bool dfs(TreeNode* p)
    {
        if (!p) return true;
        if (!dfs(p->left)) return false;
        if (p->val <= prev) return false;
        prev = p->val;
        return dfs(p->right);
    }
public:
    bool isValidBST(TreeNode* root) {
        return dfs(root);
    }
};