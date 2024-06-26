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

    void get(TreeNode* root, vector<int>& v) {
        if (!root) return;
        get(root->left, v);
        v.push_back(root->val);
        get(root->right, v);
    }

    TreeNode* balBST(vector<int>& v, int l, int r) {
        if (l > r) return nullptr;
        int mid = l + (r - l) / 2;
        TreeNode* root = new TreeNode(v[mid]);
        root->left = balBST(v, l, mid - 1);
        root->right = balBST(v, mid + 1, r);
        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> v;
        get(root, v);
        return balBST(v, 0, v.size() - 1);
    }
};