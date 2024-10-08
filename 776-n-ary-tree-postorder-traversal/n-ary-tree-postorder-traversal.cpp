/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> ans;

    void postOrder(Node* root) {
        if (!root) return;

        for (auto i : root->children) postOrder(i);

        ans.push_back(root->val);
    }

    vector<int> postorder(Node* root) {
        postOrder(root);

        return ans;
    }
};