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
    vector<int> res;
    void inorder(TreeNode* p)
    {
        if (!p) return;
        inorder(p->left);
        res.push_back(p->val);
        inorder(p->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        inorder(root);
        return res[k - 1];
    }
};