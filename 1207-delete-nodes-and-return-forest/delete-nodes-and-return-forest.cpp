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
    vector<TreeNode*> res;
    unordered_set<int> st;
    void deleteNodePostOrder(TreeNode* &root)
    {
        if (!root) return;

        deleteNodePostOrder(root->left);
        deleteNodePostOrder(root->right);

        if (st.find(root->val) != st.end())
        {
            if (root->left) res.push_back(root->left);
            if (root->right) res.push_back(root->right);
            delete root;
            root = nullptr;
        }
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for (auto i : to_delete)
        {
            st.insert(i);
        }

        deleteNodePostOrder(root);

        if (root) res.push_back(root);

        return res;
    }
};